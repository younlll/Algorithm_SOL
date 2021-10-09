#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[100][100];
int N, pinx, piny, point = 0;

//          ��  ��  �� ��
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<pair<int, pair<int, int>>> wholl;

int chkDir(int x, int y, int dir) {
	int num = map[x][y];

	if (dir == 0) {	// ��
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
	else if (dir == 1) {	// ��
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
	else if (dir == 2) {	// ��
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
	else if (dir == 3) {	// ��
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
		// �ɺ� �̵���Ű��
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		int nd = dir;
		//dir = chkDir(x, y, dir);	// ��ǥ���� ���Ե� ���� ���ϱ�

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {	// �ɺ��� �ܰ� ���� �ε��� ���, ��ǥ ��ġ ����
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
			if (nx == pinx && ny == piny) {	// �̵��� ��ǥ�� �ɺ� ������ġ�� ��� ����
				break;
			}
			else if (map[nx][ny] == -1) {	// �̵��� ��ǥ�� ��Ȧ�� ��� ����
				break;
			}
			else if (1 <= map[nx][ny] && map[nx][ny] <= 5) {	// �ɺ��� ���� �ε��� ���
				nd = chkDir(nx, ny, dir);
				point++;
			}
			else if (6 <= map[nx][ny] && map[nx][ny] <= 10) {	// ��Ȧ�� ���, �̵�
				for (int i = 0; i < wholl.size(); i++) {
					if (wholl[i].first == map[nx][ny]) {	// ���� ��Ȧ ��ȣ
						if (nx != wholl[i].second.first || ny != wholl[i].second.second) {	// �ٸ� ��Ȧ ��ġ�϶� ��ǥ ����
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

				if (map[i][j] >= 6) {	//��Ȧ��ǥ ����
					wholl.push_back({ map[i][j], {i, j} });
				}
			}
		}

		sort(wholl.begin(), wholl.end());	//��Ȧ ��ȣ �������� ����

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