#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 51

using namespace std;

struct CHINFO {
	int x;
	int y;
	bool life;
};

int N, M, answer = 987987987;
int map[MAX][MAX];
vector<CHINFO> vc;
vector<pair<int, int>> hinfo;

void mesureDir() {
	int sum = 0;
	vector<int> vSize;
	vSize.resize(hinfo.size(), 987987987);	// 각 집별 치킨거리 저장변수 초기화
	for (int i = 0; i < vc.size(); i++) {
		if (vc[i].life) {	//폐업하지 않은 치킨집이라면
			for (int j = 0; j < hinfo.size(); j++) {
				int tmp = abs(hinfo[j].first - vc[i].x) + abs(hinfo[j].second - vc[i].y);	//치킨집과의 거리 구하기
				if (vSize[j] > tmp) {	//최소 치킨집과의 거리 저장
					vSize[j] = tmp;
				}
			}
		}
	}

	for (int i = 0; i < vSize.size(); i++) {	//각 집별 치킨거리의 합 구하기
		sum += vSize[i];
	}
	
	if (answer > sum) {	//최소 치킨거리 구하기
		answer = sum;
	}
}

void solution(int cnt, int idx, int nc) {
	if (cnt >= nc) {	//선택한 치킨집 수(nc)와 폐업하지 않을 치킨집 수(nc)가 같은경우
		mesureDir();
		return;
	}

	for (int i = idx; i < vc.size(); i++) {
		vc[i].life = true;	// 폐업하지 않을 치킨집 선택
		solution(cnt + 1, i + 1, nc);
		vc[i].life = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				vc.push_back({ i, j, false });	//치킨집 정보 입력(x좌표, y좌표, 폐업여부)
			}
			else if (map[i][j] == 1) {
				hinfo.push_back({ i, j });	//집 좌표
			}
		}
	}

	for (int i = 1; i <= M; i++) {	// 1개부터 최대 M개 까지 치킨집 선택
		solution(0, 0, i);
	}

	cout << answer << '\n';

	return 0;
}