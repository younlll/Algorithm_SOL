#include <iostream>
#include <stack>
using namespace std;

int N, K;
int arr[8][8];
bool chkArr[8][8];
int maxSize = 0;
//          상  좌  하  우
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void solution(int x, int y, int val, int digCnt) {
	stack<pair<int, int>> st;
	st.push(pair<int, int>(x, y));

	int digX = -1;
	int digY = -1;

	while (!st.empty()) {
		bool chgYn = false;
		for (int i = 0; i < 4; i++) {
			int next_x = st.top().first + dx[i];
			int next_y = st.top().second + dy[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) {
				continue;
			}

			if (chkArr[next_x][next_y]) {
				continue;
			}

			if (arr[next_x][next_y] >= val && digCnt == 0) {
				int gap = arr[next_x][next_y] - val;
				if (gap >= K) {
					continue;
				}
				chkArr[next_x][next_y] = true;
				st.push(pair<int, int>(next_x, next_y));
				val--;
				digCnt++;
				digX = next_x;
				digY = next_y;
				chgYn = true;
				break;
			}
			else if (arr[next_x][next_y] < val) {
				chkArr[next_x][next_y] = true;
				st.push(pair<int, int>(next_x, next_y));
				val = arr[st.top().first][st.top().second];
				chgYn = true;
				break;
			}
		}
		if (!chgYn) {
			if (digX == st.top().first && digY == st.top().second) {
				digX = -1;
				digY = -1;
				digCnt = 0;
			}
			chkArr[st.top().first][st.top().second] = false;
			if (maxSize < st.size()) {
				maxSize = st.size();
			}
			st.pop();
		}

		if (x == st.top().first && y == st.top().second) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	int maxVal = 0;
	for (int t = 1; t <= T; t++) {
		//입력부
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];

				if (maxVal < arr[i][j]) {
					maxVal = arr[i][j];
				}
			}
		}

		int result = 0;
		//최고점으로부터 등산로 탐색
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == maxVal) {
					chkArr[i][j] = true;
					solution(i, j, arr[i][j], 0);
					chkArr[i][j] = false;
					
					if (result < maxSize) {
						result = maxSize;
					}
				}
			}
		}

		cout << result << '\n';
	}
}