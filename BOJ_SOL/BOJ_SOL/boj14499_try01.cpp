#include <iostream>

using namespace std;

int map[20][20];
int N, M, x, y, K;
int nemo[4][3];
int order[1000];
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> order[i];
	}

	for (int i = 0; i < K; i++) {
		int nx = x + dx[order[i]];
		int ny = y + dy[order[i]];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {	// 영역을 벗어나는 경우, 주사위 움직이지 않기
			continue;
		}

		/**********
		*    [0] [1] [2]
		* [0] 0  뒤  0
		* [1] 왼 위  오
		* [2] 0  앞  0
		* [3] 0  바  0
		*
		***********/

		//주사위 이동
		if (order[i] == 1) {	// →
			               // [0] 바닥   [1] 왼      [2] 위     [3] 오
			int tmp[4] = { nemo[3][1], nemo[1][0], nemo[1][1], nemo[1][2] };
			// 오 -> 바
			nemo[3][1] = tmp[3];
			// 바 -> 왼
			nemo[1][0] = tmp[0];
			// 왼 -> 위
			nemo[1][1] = tmp[1];
			// 위 -> 오
			nemo[1][2] = tmp[2];
		}
		else if (order[i] == 2) {	// ←
						   // [0] 바닥   [1] 왼      [2] 위     [3] 오
			int tmp[4] = { nemo[3][1], nemo[1][0], nemo[1][1], nemo[1][2] };
			// 왼 -> 바
			nemo[3][1] = tmp[1];
			// 위 -> 왼
			nemo[1][0] = tmp[2];
			// 오 -> 위
			nemo[1][1] = tmp[3];
			// 바 -> 오
			nemo[1][2] = tmp[0];
		}
		else if (order[i] == 3) {	// ↑
			int tmp = nemo[0][1];
			for (int i = 0; i < 3; i++) {
				nemo[i][1] = nemo[i + 1][1];
			}
			nemo[3][1] = tmp;
		}
		else if (order[i] == 4) {	// ↓
			int tmp = nemo[3][1];
			for (int i = 3; i > 0; i--) {
				nemo[i][1] = nemo[i - 1][1];
			}
			nemo[0][1] = tmp;
		}

		if (map[nx][ny] == 0) {	// 이동한 칸의 수가 0이면, 주사위 바닥면 숫자를 맵에 복사
			map[nx][ny] = nemo[3][1];
		}
		else {	// 이동한 칸의 수가 0이 아니라면, 맵의 숫자를 주사위 바닥면에 복사
			nemo[3][1] = map[nx][ny];
			map[nx][ny] = 0;
		}

		x = nx;
		y = ny;

		cout << nemo[1][1] << '\n';
	}
}