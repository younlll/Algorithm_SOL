#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int N, Q, answer = 0, sum = 0;
int map[70][70];
bool chkMap[70][70];
int order[1000];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void chkArea(int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (map[i][j] != 0 && !chkMap[i][j]) {
				int cnt = 1;
				queue<pair<int, int>> Queue;
				Queue.push({ i, j });
				chkMap[i][j] = true;

				while (!Queue.empty()) {
					int cx = Queue.front().first;
					int cy = Queue.front().second;
					sum += map[cx][cy];
					Queue.pop();

					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];

						if (nx >= 0 && nx < len && ny >= 0 && ny < len) {
							if (map[nx][ny] > 0 && !chkMap[nx][ny]) {
								chkMap[nx][ny] = true;
								Queue.push({ nx, ny });
								cnt++;	//����� ĭ�� �� ī����
							}
						}
					}
				}

				if (answer < cnt) {	// ����� ����ĭ �ִ밪 ���ϱ�
					answer = cnt;
				}
			}
		}
	}
}

void chkIce(int len) {
	vector<pair<int, int>> vc;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			int cx = i;
			int cy = j;
			int cnt = 0;
			if (map[cx][cy] == 0) {	// ������ 0���� ĭ�� Ȯ������ �ʾƵ� �ȴ�
				continue;
			}
			for (int k = 0; k < 4; k++) {	// �����¿쿡 ���� ������ �ִ��� Ž��
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && nx < len && ny >= 0 && ny < len) {
					if (map[nx][ny] > 0) {	//������ �ִ�ĭ ī����
						cnt++;
					}
				}
			}

			if (cnt < 3) {	// ������ ����ĭ�� 3�� �̻��� �ƴ� ĭ�� ��ǥ ����
				vc.push_back({ cx, cy });
			}
		}
	}

	for (int i = 0; i < vc.size(); i++) {	// ������ ����ĭ�� 3�� �̻��� �ƴ�ĭ�� ���� ���� -1
		map[vc[i].first][vc[i].second]--;
	}
}

void tornado(int x, int y, int q) {
	int rlen = x + pow(2, q);
	int llen = y + pow(2, q);
	vector<vector<int>> vc;
	for (int i = y; i < llen; i++) {
		vector<int> tmpVc;
		for (int j = rlen - 1; j >= x; j--) {
			tmpVc.push_back(map[j][i]);
		}
		vc.push_back(tmpVc);
	}

	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[i].size(); j++) {
			map[x + i][y + j] = vc[i][j];
		}
	}
}

void divideMap(int len) {
	for (int k = 0; k < Q; k++) {	// ��ɾ� ����ŭ �ݺ�
		if (order[k] == 0) {	// 0�� 90�� ȸ���� �����Ƿ� ����̵��� �Ͼ�� �ʴ´�
			chkIce(len);
			continue;
		}
		int g = pow(2, order[k]);	// ��ɾ ���� ���� ���ϱ� 2^L
		for (int i = 0; i < len; i += g) {
			for (int j = 0; j < len; j += g) {
				tornado(i, j, order[k]);
			}
		}

		chkIce(len);
	}

	chkArea(len);
	cout << sum << '\n';
	cout << answer << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;

	int len = pow(2, N);

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {
		cin >> order[i];
	}

	divideMap(len);
}