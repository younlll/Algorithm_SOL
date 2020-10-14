#include <iostream>
using namespace std;

int Input[50][50];
int N, M;
int cnt = 0;

//           상  우 하 좌
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//          서 북 동 남
int d[4] = { 3, 0, 1, 2 };
//             남 서 북 동
int back[4] = { 2, 3, 0, 1 };
void  cleanMap(int x, int y, int dir) {
	if (Input[x][y] == 0) {
		cnt++;
	}
	else if (Input[x][y] == 1) {
		return;
	}
	Input[x][y] = 2;

	for (int i = 0; i < 4; i++) {
		dir = d[dir];
		int next_x = x + dx[dir];
		int next_y = y + dy[dir];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) {
			continue;
		}

		//청소할 공간 O
		if (Input[next_x][next_y] == 0) {
			cleanMap(next_x, next_y, dir);
			return;
		}

		//청소할 공간 X
	}
	
	//한칸 후진
	int next_x = x + dx[back[dir]];
	int next_y = y + dy[back[dir]];
	cleanMap(next_x, next_y, dir);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int x, y, dir;
	cin >> x >> y >> dir;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Input[i][j];
		}
	}

	cleanMap(x, y, dir);

	cout << cnt << '\n';

	return 0;
}