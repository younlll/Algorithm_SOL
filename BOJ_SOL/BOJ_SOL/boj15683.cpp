#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CCTV_INFO {
	int x;
	int y;
	int num;
	int dir;
};

int N, M, answer = 987987897, zeroCnt = 0;
int map[8][8];
int copyMap[8][8];
vector<CCTV_INFO> vc;

void copyMapInfo() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
}

void observeMap() {
	copyMapInfo();
	int blankCnt = zeroCnt;
	for (int i = 0; i < vc.size(); i++) {
		int num = vc[i].num;
		int dir = vc[i].dir;
		int cnt = 0;
		int x = vc[i].x;
		int y = vc[i].y;

		if (num == 1) {
			if (dir == 1) {
				for (int i = x - 1; i >= 0; i--) {	// ╩С
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
			}
			else if (dir == 2) {
				for (int i = y + 1; i < M; i++) {	// ©Л
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
			}
			else if (dir == 3) {
				for (int i = x + 1; i < N; i++) {	// го
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
			}
			else if (dir == 4) {
				for (int i = y - 1; i >= 0; i--) {	// аб
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
			}
		}
		else if (num == 2) {
			if (dir == 1 || dir == 3) {	// ╩С го
				for (int i = x - 1; i >= 0; i--) {	// ╩С
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
				for (int i = x + 1; i < N; i++) {	// го
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
			}
			else {	// аб ©Л
				for (int i = y - 1; i >= 0; i--) {	// аб
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
				for (int i = y + 1; i < M; i++) {	// ©Л
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
			}
		}
		else if (num == 3) {
			if(dir == 1){	// ╩С ©Л
				for (int i = x - 1; i >= 0; i--) {	// ╩С
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
				for (int i = y + 1; i < M; i++) {	// ©Л
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
			}
			else if (dir == 2) {	// ©Л го
				for (int i = y + 1; i < M; i++) {	// ©Л
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
				for (int i = x + 1; i < N; i++) {	// го
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
			}
			else if (dir == 3) {	// го аб
				for (int i = x + 1; i < N; i++) {	// го
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
				for (int i = y - 1; i >= 0; i--) {	// аб
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
			}
			else if (dir == 4) {	//  аб ╩С
				for (int i = y - 1; i >= 0; i--) {	// аб
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
				for (int i = x - 1; i >= 0; i--) {	// ╩С
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
			}
		}
		else if (num == 4) {
			if(dir == 1){	// ╩С аб ©Л
				for (int i = x - 1; i >= 0; i--) {	// ╩С
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
				for (int i = y - 1; i >= 0; i--) {	// аб
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
				for (int i = y + 1; i < M; i++) {	// ©Л
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
			}
			else if (dir == 2) { // ╩С ©Л го
				for (int i = x - 1; i >= 0; i--) {	// ╩С
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
				for (int i = y + 1; i < M; i++) {	// ©Л
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
				for (int i = x + 1; i < N; i++) {	// го
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
			}
			else if (dir == 3) {	// аб го ©Л
				for (int i = y - 1; i >= 0; i--) {	// аб
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
				for (int i = x + 1; i < N; i++) {	// го
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
				for (int i = y + 1; i < M; i++) {	// ©Л
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
			}
			else if (dir == 4) {	// ╩С аб го
				for (int i = x - 1; i >= 0; i--) {	// ╩С
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
				for (int i = y - 1; i >= 0; i--) {	// аб
					if (copyMap[x][i] == 0) {
						copyMap[x][i] = 9;
						blankCnt--;
					}
					else if (copyMap[x][i] == 6) {
						break;
					}
				}
				for (int i = x + 1; i < N; i++) {	// го
					if (copyMap[i][y] == 0) {
						copyMap[i][y] = 9;
						blankCnt--;
					}
					else if (copyMap[i][y] == 6) {
						break;
					}
				}
			}
		}
		else if (num == 5) {
			// ╩С го аб ©Л
			for (int i = x - 1; i >= 0; i--) {	// ╩С
				if (copyMap[i][y] == 0) {
					copyMap[i][y] = 9;
					blankCnt--;
				}
				else if (copyMap[i][y] == 6) {
					break;
				}
			}
			for (int i = y + 1; i < M; i++) {	// ©Л
				if (copyMap[x][i] == 0) {
					copyMap[x][i] = 9;
					blankCnt--;
				}
				else if (copyMap[x][i] == 6) {
					break;
				}
			}
			for (int i = y - 1; i >= 0; i--) {	// аб
				if (copyMap[x][i] == 0) {
					copyMap[x][i] = 9;
					blankCnt--;
				}
				else if (copyMap[x][i] == 6) {
					break;
				}
			}
			for (int i = x + 1; i < N; i++) {	// го
				if (copyMap[i][y] == 0) {
					copyMap[i][y] = 9;
					blankCnt--;
				}
				else if (copyMap[i][y] == 6) {
					break;
				}
			}
		}
	}

	if (answer > blankCnt) {
		answer = blankCnt;
	}
}

void solution(int idx, int cnt, int cctv) {
	if (cnt >= cctv) {
		observeMap();
		return;
	}

	for (int i = 1; i <= 4; i++) {
		vc[idx].dir = i;
		solution(idx + 1, cnt + 1, cctv);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (1 <= map[i][j] && map[i][j] <= 5) {
				vc.push_back({ i, j, map[i][j], 0 });
			}
			else if (map[i][j] == 0) {
				zeroCnt++;
			}
		}
	}
	solution(0, 0, vc.size());

	cout << answer << '\n';

}