#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int r, c, k, answer;
int map[100][100];
int numArr[100];

void solution() {
	int sec = 0;
	int rlen = 3;
	int llen = 3;
	while (1) {
		if (map[r - 1][c - 1] == k) {
			answer = sec;
			break;
		}
		if (sec > 100) {
			answer = -1;
			break;
		}

		vector<int> Size;
		if (rlen >= llen) {	// R����
			for (int i = 0; i < rlen; i++) {	// ��� ������
				vector<pair<int, int>> vc2;
				memset(numArr, 0, sizeof(numArr));	// �ڿ��� ������ �迭 �ʱ�ȭ
				for (int j = 0; j < llen; j++) {
					numArr[map[i][j] - 1]++;	// �ڿ����� ���� ī����
				}
				for (int j = 0; j < 100; j++) {
					if (numArr[j] == 0) {
						continue;
					}
					vc2.push_back({ numArr[j], j + 1 });	// ����, �ڿ��� ����
				}
				sort(vc2.begin(), vc2.end());	// ������ ������, ���ٸ� �ڿ��� ������������ ����

				for (int j = 0; j < llen; j++) {
					map[i][j] = 0;
				}

				int idx = 0;
				for (int j = 0; j < vc2.size(); j++) {	// �࿡ ���� �ڿ��� ������ŭ �ݺ�
					map[i][idx++] = vc2[j].second;	// �ڿ���
					map[i][idx++] = vc2[j].first;	// �ڿ����� ���� ����
				}

				Size.push_back(idx);
			}
			sort(Size.begin(), Size.end());
			llen = Size.back();
		}
		else {	// L����
			for (int i = 0; i < llen; i++) {	//��� ������
				vector<pair<int, int>> vc2;
				memset(numArr, 0, sizeof(numArr));	// �ڿ��� ������ �迭 �ʱ�ȭ
				for (int j = 0; j < rlen; j++) {
					numArr[map[j][i] - 1]++;	// �ڿ����� ���� ī����
				}
				for (int j = 0; j < 100; j++) {
					if (numArr[j] == 0) {
						continue;
					}
					vc2.push_back({ numArr[j], j + 1 });	// ����, �ڿ��� ����
				}
				sort(vc2.begin(), vc2.end());	// ������ ������, ���ٸ� �ڿ��� ������������ ����

				for (int j = 0; j < rlen; j++) {
					map[j][i] = 0;
				}

				int idx = 0;
				for (int j = 0; j < vc2.size(); j++) {	// �࿡ ���� �ڿ��� ������ŭ �ݺ�
					map[idx++][i] = vc2[j].second;	// �ڿ���
					map[idx++][i] = vc2[j].first;	// �ڿ����� ���� ����
				}

				Size.push_back(idx);
			}
			sort(Size.begin(), Size.end());
			rlen = Size.back();
		}

		sec++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}

	if (map[r - 1][c - 1] == k) {
		answer = 0;
		cout << answer << '\n';
		return 0;
	}

	solution();

	cout << answer << '\n';

	return 0;
}