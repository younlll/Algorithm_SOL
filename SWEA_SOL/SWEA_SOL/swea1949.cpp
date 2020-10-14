#include <iostream>
using namespace std;

int N, K;
int arr[8][8];
bool chkArr[8][8];
int maxSize = 0;
//          상  좌  하  우
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void solution(int x, int y, int cnt, int digCnt) {
	chkArr[x][y] = true;
	if (maxSize < cnt) {
		maxSize = cnt;
	}
	
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) {
			continue;
		}

		if (chkArr[next_x][next_y]) {
			continue;
		}

		if (arr[x][y] > arr[next_x][next_y]) {
			solution(next_x, next_y, cnt + 1, digCnt);
		}
		else if (arr[next_x][next_y] - arr[x][y] < K && digCnt == 0) {
			int tmp = arr[next_x][next_y];
			arr[next_x][next_y] = arr[x][y] - 1;
			solution(next_x, next_y, cnt + 1, digCnt + 1);
			arr[next_x][next_y] = tmp;
		}
 	}
	chkArr[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int maxVal = 0;
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
					solution(i, j, 1, 0);

					if (result < maxSize) {
						result = maxSize;
					}
				}
			}
		}

		cout << '#' << t << ' ' << result << '\n';
		maxSize = 0;
	}
}
