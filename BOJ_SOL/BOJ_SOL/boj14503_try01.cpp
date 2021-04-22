#include <iostream>

using namespace std;

int N, M;
int map[51][51];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct ROBOT {
	int x;
	int y;
	int d;
	int cleanCnt;
};

ROBOT robot;

int findLeft(int d) {
	if (d == 0) {
		return 3;
	}
	else if (d == 1) {
		return 0;
	}
	else if (d == 2) {
		return 1;
	}
	else if (d == 3) {
		return 2;
	}
}

void solution() {
	if (map[robot.x][robot.y] == 0) {
		robot.cleanCnt++;	//현재 위치를 청소한다.
		map[robot.x][robot.y] = 2;
	}

	//로봇청소기의 이동
	int leftDir = findLeft(robot.d);
	int leftX = robot.x + dx[leftDir];
	int leftY = robot.y + dy[leftDir];
	
	if (map[leftX][leftY] == 0) {	//왼쪽에 청소할 공간이 있다면
		robot.x = leftX;
		robot.y = leftY;
		robot.d = leftDir;
	}
	else {	//왼쪽에 청소할 공간이 없다면

		int notMoveCnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = robot.x + dx[i];
			int ny = robot.y + dy[i];

			if (map[nx][ny] == 1 || map[nx][ny] == 2) {	//이동할 공간이 벽이거나 청소한 공간인 경우
				notMoveCnt++;
			}
		}

		if (notMoveCnt == 4) {	//네 방향 모두가 벽이거나 청소한 경우
			int nx = robot.x + (dx[robot.d] * -1);
			int ny = robot.y + (dy[robot.d] * -1);

			if (map[nx][ny] != 1) {	//후진이 가능하다면
				robot.x = nx;
				robot.y = ny;
			}
			else if (map[nx][ny] == 1) {	//뒤쪽이 벽이라면
				return;	//종료
			}
		}
		else {
			robot.d = leftDir;
		}
	}

	solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	
	int r, c, d;	// d: 0↑ 1→ 2↓ 3←
	cin >> r >> c >> d;
	robot.x = r;
	robot.y = c;
	robot.d = d;
	robot.cleanCnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	solution();

	cout << robot.cleanCnt << '\n';

	return 0;
}