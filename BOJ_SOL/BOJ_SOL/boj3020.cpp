#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, H;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> H;
	vector<int> bottom(N / 2), top(N / 2);	//석순과 종유석이 번갈아 나오므로 깊이N의 /2만큼씩 존재
	for (int i = 0; i < N / 2; i++) {
		cin >> bottom[i] >> top[i];	//석순과 종유석 높이 입력
	}

	//석순과 종유석 높이 오름차순 정렬
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int minVal = 987897897;
	int answer = 1;
	for (int i = 1; i <= H; i++) {

		//높이i에서 겹치는 석순의 갯수
		int cnt = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		
		//높이i에서 겹치는 종유석의 갯수
		cnt += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		if (minVal == cnt) {	//최솟값과 높이i를 지나는 석순과 종유석의 갯수가 같다면 카운트 +1
			answer++;
		}
		else if (minVal > cnt) {	//최솟값과 높이i를 지나는 석순과 종유석의 갯수가 다른경우
			minVal = cnt;	//최소값 갱신
			answer = 1;		//카운트 1로 초기화
		}
	}

	cout << minVal << ' ' << answer << '\n';

	return 0;
}