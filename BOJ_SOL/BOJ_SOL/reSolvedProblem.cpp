#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[100][100];
int N, pinx, piny, point = 0;

//          ↑  ↓  ← →
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<pair<int, pair<int, int>>> wholl;

int chkDir(int x, int y, int dir) {
	int num = map[x][y];

	if (dir == 0) {	// ↑
		if (num >= 6) {
			return 1;
		}
		else if (num == 1 || num == 4 || num == 5) {
			return 1;
		}
		else if (num == 2) {
			return 3;
		}
		else if (num == 3) {
			return 2;
		}
	}
	else if (dir == 1) {	// ↓
		if (num >= 6) {
			return 0;
		}
		else if (num == 2 || num == 3 || num == 5) {
			return 0;
		}
		else if (num == 1) {
			return 3;
		}
		else if (num == 4) {
			return 2;
		}
	}
	else if (dir == 2) {	// ←
		if (num >= 6) {
			return 3;
		}
		else if (num == 3 || num == 4 || num == 5) {
			return 3;
		}
		else if (num == 1) {
			return 0;
		}
		else if (num == 2) {
			return 1;
		}
	}
	else if (dir == 3) {	// →
		if (num >= 6) {
			return 2;
		}
		else if (num == 1 || num == 2 || num == 5) {
			return 2;
		}
		else if (num == 3) {
			return 1;
		}
		else if (num == 4) {
			return 0;
		}
	}
}

void solution(int x, int y, int dir) {
	point = 0;
	while (1) {
		// 핀볼 이동시키기
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		int nd = dir;
		//dir = chkDir(x, y, dir);	// 좌표에서 갖게될 방향 정하기

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {	// 핀볼이 외각 벽에 부딪힌 경우, 좌표 위치 유지
			if (dir == 0) {
				nd = 1;
			}
			else if (dir == 1) {
				nd = 0;
			}
			else if (dir == 2) {
				nd = 3;
			}
			else if (dir == 3) {
				nd = 2;
			}
			point++;
		}
		else {
			if (nx == pinx && ny == piny) {	// 이동할 좌표가 핀볼 시작위치인 경우 종료
				break;
			}
			else if (map[nx][ny] == -1) {	// 이동할 좌표가 블랙홀인 경우 종료
				break;
			}
			else if (1 <= map[nx][ny] && map[nx][ny] <= 5) {	// 핀볼이 블럭과 부딪힌 경우
				nd = chkDir(nx, ny, dir);
				point++;
			}
			else if (6 <= map[nx][ny] && map[nx][ny] <= 10) {	// 웜홀인 경우, 이동
				for (int i = 0; i < wholl.size(); i++) {
					if (wholl[i].first == map[nx][ny]) {	// 같은 웜홀 번호
						if (nx != wholl[i].second.first || ny != wholl[i].second.second) {	// 다른 웜홀 위치일때 좌표 변경
							nx = wholl[i].second.first;
							ny = wholl[i].second.second;
							break;
						}
					}
				}
			}
		}
		x = nx;
		y = ny;
		dir = nd;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	cin >> TC;

	for (int testcase = 1; testcase <= TC; testcase++) {
		cin >> N;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];

				if (map[i][j] >= 6) {	//움홀좌표 저장
					wholl.push_back({ map[i][j], {i, j} });
				}
			}
		}

		sort(wholl.begin(), wholl.end());	//웜홀 번호 오름차순 정렬

		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						cout << i << ' ' << j << ' ' << k << '\n';
						pinx = i;
						piny = j;
						solution(i, j, k);

						if (answer < point) {
							answer = point;
						}
					}
				}
			}
		}
		cout << "#" << testcase << ' ' << answer << '\n';
	}
}