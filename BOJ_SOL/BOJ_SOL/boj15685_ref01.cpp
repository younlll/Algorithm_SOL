#include <iostream>
#include <vector>

using namespace std;

int N;
int map[101][101];
int answer = 0;
vector<int> dir_info;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int x, y, d, g;
	for (int i = 0; i < N; i++) {
		cin >> y >> x >> d >> g;
		dir_info.clear();

		map[x][y] = 1;	//�����Է� ��ǥ ǥ��
		x = x + dx[d];	//�Է¹��� ��ǥ �������� �̵�
		y = y + dy[d];
		map[x][y] = 1;

		dir_info.push_back(d);
		for (int j = 0; j < g; j++) {
			//�巹��Ŀ�� �����
			/*****************************************************************
			* 0���� : 0
			* 1���� : 0 1
			* 2���� : 0 1 2 1
			* 3���� : 0 1 2 1 2 3 2 1
			* �� ���ø� ���� �˼� �ִٽ���
			* �������� ���� ���������
			* �������� ��������� �������� �о�� +1�� ������ ���´�
			* ��, 4 ������ �����Ƿ� 0�� �ȴ�
			*****************************************************************/
			for (int k = dir_info.size() - 1; k >= 0; k--) {
				int nd = (dir_info[k] + 1) % 4;
				x = x + dx[nd];
				y = y + dy[nd];
				map[x][y] = 1;
				dir_info.push_back(nd);
			}
		}
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1) {
				answer++;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}