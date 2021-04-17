#include <iostream>

#define MAX 500
using namespace std;

int arr[MAX][MAX];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int N;
int answer = 0;

// 1 1 7 7 10 10 2 2 5 alpha
int sendX[4][10] = { {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}
				, {0, 0, 1, 1, 2, 2, 1, 1, 3, 2}
				, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}
				, {0, 0, -1, -1, -2, -2, -1, -1, -3, -2} };
int sendY[4][10] = { {0, 0, -1, -1, -2, -2, -1, -1, -3, -2}
				, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}
				, {0, 0, 1, 1, 2, 2, 1, 1, 3, 2}
				, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0} };

int percent[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };

void moveSend(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int send = arr[nx][ny];
	int tmpSend = send;
	for (int i = 0; i < 9; i++) {
		nx = x + sendX[dir][i];
		ny = y + sendY[dir][i];
		int p = percent[i];
		int tmp = (tmpSend * p) / 100;

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			arr[nx][ny] += tmp;
		}
		else {
			answer += tmp;
		}
		send -= tmp;
	}
	nx = x + sendX[dir][9];
	ny = y + sendY[dir][9];
	if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
		arr[nx][ny] += send;
	}
	else {
		answer += send;
	}

	nx = x + dx[dir];
	ny = y + dy[dir];
	arr[nx][ny] = 0;
}

void solution() {
	int x = N / 2;
	int y = N / 2;
	int dir = 0;
	int cnt = 1;
	int nx, ny;

	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < cnt; j++) {
				nx = x + dx[dir];
				ny = y + dy[dir];

				moveSend(x, y, dir);

				//현재 위치한 좌표 바꾸기
				x = nx;
				y = ny;
			}

			//이동 방향 변경
			dir++;
			if (dir > 3) {
				dir = 0;
			}
		}

		cnt++;
		if (cnt == N) {
			for (int i = 0; i < cnt; i++) {
				nx = x + dx[dir];
				ny = y + dy[dir];
				moveSend(x, y, dir);
				x = nx;
				y = ny;
			}
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	solution();

	cout << answer << '\n';

	return 0;
}