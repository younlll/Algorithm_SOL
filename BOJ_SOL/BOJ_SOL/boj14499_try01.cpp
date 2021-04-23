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
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {	// ������ ����� ���, �ֻ��� �������� �ʱ�
			continue;
		}

		/**********
		*    [0] [1] [2]
		* [0] 0  ��  0
		* [1] �� ��  ��
		* [2] 0  ��  0
		* [3] 0  ��  0
		*
		***********/

		//�ֻ��� �̵�
		if (order[i] == 1) {	// ��
			               // [0] �ٴ�   [1] ��      [2] ��     [3] ��
			int tmp[4] = { nemo[3][1], nemo[1][0], nemo[1][1], nemo[1][2] };
			// �� -> ��
			nemo[3][1] = tmp[3];
			// �� -> ��
			nemo[1][0] = tmp[0];
			// �� -> ��
			nemo[1][1] = tmp[1];
			// �� -> ��
			nemo[1][2] = tmp[2];
		}
		else if (order[i] == 2) {	// ��
						   // [0] �ٴ�   [1] ��      [2] ��     [3] ��
			int tmp[4] = { nemo[3][1], nemo[1][0], nemo[1][1], nemo[1][2] };
			// �� -> ��
			nemo[3][1] = tmp[1];
			// �� -> ��
			nemo[1][0] = tmp[2];
			// �� -> ��
			nemo[1][1] = tmp[3];
			// �� -> ��
			nemo[1][2] = tmp[0];
		}
		else if (order[i] == 3) {	// ��
			int tmp = nemo[0][1];
			for (int i = 0; i < 3; i++) {
				nemo[i][1] = nemo[i + 1][1];
			}
			nemo[3][1] = tmp;
		}
		else if (order[i] == 4) {	// ��
			int tmp = nemo[3][1];
			for (int i = 3; i > 0; i--) {
				nemo[i][1] = nemo[i - 1][1];
			}
			nemo[0][1] = tmp;
		}

		if (map[nx][ny] == 0) {	// �̵��� ĭ�� ���� 0�̸�, �ֻ��� �ٴڸ� ���ڸ� �ʿ� ����
			map[nx][ny] = nemo[3][1];
		}
		else {	// �̵��� ĭ�� ���� 0�� �ƴ϶��, ���� ���ڸ� �ֻ��� �ٴڸ鿡 ����
			nemo[3][1] = map[nx][ny];
			map[nx][ny] = 0;
		}

		x = nx;
		y = ny;

		cout << nemo[1][1] << '\n';
	}
}