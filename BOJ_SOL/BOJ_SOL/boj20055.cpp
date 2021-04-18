#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	deque<pair<int, bool>> dq1;
	deque<pair<int, bool>> dq2;

	cin >> N >> K;

	int cnt = 0;
	int answer = 0;

	for (int i = 0; i < 2 * N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			cnt++;
		}
		if (i < N) {
			dq1.push_back({ tmp, false });
		}
		else {
			dq2.push_front({ tmp, false });
		}
	}

	while (cnt < K) {	//내구도 0의 갯수가 K미만인 경우동안 반복
		//컨베이어벨트 한칸씩 이동
		pair<int, bool> downInfo = dq1.back();	//내려갈 칸 정보 저장
		pair<int, bool> upInfo = dq2.front();	//올라갈 칸 정보 저장
		downInfo.second = false;	//로봇 내려주기
		if (downInfo.second) {

		}
		dq1.pop_back();	//윗줄에서 내려갈 칸 pop
		dq2.pop_front(); //아랫줄에서 올라갈 칸 pop
		dq1.push_front(upInfo);
		dq2.push_back(downInfo);

		//벨트위 로봇 이동시키기
		for (int i = N - 1; i >= 0; i--) {
			if (i + 1 >= N) {	//로봇이 한칸 이동한 곳이 내려가는 곳인 경우
				dq1[i].second = false;
			}else if (dq1[i].second && dq1[i + 1].first >= 1) {	//현재 위치에 로봇이 있으면서 이동할 칸의 내구도가 1이상인 경우
				if (!dq1[i + 1].second) {	//이동할 칸이 빈칸인 경우
					dq1[i].second = false;
					dq1[i + 1].second = true;	//로봇 존재 표시
					dq1[i + 1].first -= 1;	//내구도 1 감소
					if (dq1[i + 1].first == 0) {	//감소한 내구도가 0인지 검사
						cnt++;
					}
				}
			}
		}

		//올라가는 위치에 로봇이 없가나 내구도가 1이상인 경우
		//로봇 올리기
		if (dq1[0].first >= 1 && !dq1[0].second) {
			dq1[0].first -= 1;	//내구도 1감소
			dq1[0].second = true;
			if (dq1[0].first == 0) {	//감소한 내구도가 0인지 검사
				cnt++;
			}
		}

		answer++;
	}

	cout << answer << '\n';

	return 0;
}