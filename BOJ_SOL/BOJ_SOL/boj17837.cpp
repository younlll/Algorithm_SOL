#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CHESS {
	int x;
	int y;
	int d;
};

struct MAP_INFO {
	int color;
	vector<int> vc;
};

CHESS chess[15];
MAP_INFO map[15][15];
int N, K;
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

int reverseDir(int n) {
	if (n == 1) {
		return 2;
	}
	else if (n == 2) {
		return 1;
	}
	else if (n == 3) {
		return 4;
	}
	else if (n == 4) {
		return 3;
	}
}

int find_position(int x, int y, int idx) {
	for (int i = 0; i < map[x][y].vc.size(); i++) {
		if (map[x][y].vc[i] == idx) {
			return i;
		}
	}
}

bool checkState() {
	for (int i = 1; i <= K; i++) {
		int x = chess[i].x;
		int y = chess[i].y;
		if (map[x][y].vc.size() >= 4) {
			return true;
		}
	}
	return false;
}

void move(int cx, int cy, int nx, int ny, int idx, int pos, int color) {
	int cnt = 0;
	if (color == 0) {
		for (int i = pos; i < map[cx][cy].vc.size(); i++) {
			map[nx][ny].vc.push_back(map[cx][cy].vc[i]);
			int chNum = map[cx][cy].vc[i];
			chess[chNum].x = nx;
			chess[chNum].y = ny;
			cnt++;
		}
		for (int i = 0; i < cnt; i++) {
			map[cx][cy].vc.pop_back();
		}
	}
	else if (color == 1) {
		for (int i = map[cx][cy].vc.size() - 1; i >= pos; i--) {
			map[nx][ny].vc.push_back(map[cx][cy].vc[i]);
			int chNum = map[cx][cy].vc[i];
			chess[chNum].x = nx;
			chess[chNum].y = ny;
			cnt++;
		}
		for (int i = 0; i < cnt; i++) {
			map[cx][cy].vc.pop_back();
		}
	}
	else if (color == 2) {
		chess[idx].d = reverseDir(chess[idx].d);
		
		int nnx = cx + dx[chess[idx].d];
		int nny = cy + dy[chess[idx].d];

		if (nnx > 0 && nnx <= N && nny > 0 && nny <= N && map[nnx][nny].color != 2) {
			move(cx, cy, nnx, nny, idx, pos, map[nnx][nny].color);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j].color;	// 맵의 1x1에 대한 정보 저장
		}
	}

	for (int i = 1; i <= K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		chess[i] = { a, b, c };	// 체스말 정보 저장(x좌표, y좌표, 방향)
		map[a][b].vc.push_back(i);	// 맵(a, b)에 쌓여있는 체스말 번호 저장
	}

	int turn = 1;
	bool flag = false;
	while (turn <= 1000) {
		for (int idx = 1; idx <= K; idx++) {
			int dir = chess[idx].d;
			int cx = chess[idx].x;
			int cy = chess[idx].y;

			int nx = chess[idx].x + dx[dir];
			int ny = chess[idx].y + dy[dir];

			int pos = find_position(cx, cy, idx);

			if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
				move(cx, cy, nx, ny, idx, pos, map[nx][ny].color);
			}
			else {
				move(cx, cy, nx, ny, idx, pos, 2);
			}
			if (checkState() == true) {
				cout << turn << '\n';
				return 0;
			}
		}
		turn++;
	}

	cout << "-1\n";

	return 0;
}