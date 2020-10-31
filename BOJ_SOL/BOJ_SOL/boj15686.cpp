#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[55][55];
vector<pair<int, int>> vc;
vector<pair<int, int>> vcP;
vector<pair<int, int>> vcCh;
int dirX[4] = { 0, -1, 0 ,1 };
int dirY[4] = { -1, 0, 1, 0 };
int n, m;
int minDir = 987987897;

void solution(int cnt, int k, int start, int m) {
	if (cnt == k) {	// k�� ��ŭ�� ġŲ���� ������ ���
		int sum = 0;
		//�� ������ ġŲ�Ÿ� ���ϱ�
		for (int i = 0; i < vcP.size(); i++) {
			int subMin = 987897987;

			//�ϳ��� �� ��ǥ�� �������� ���õ� ġŲ���� �� ġŲ�Ÿ� ���ϱ�
			for (int j = 0; j < vcCh.size(); j++) {
				int dirGap = abs(vcP[i].first - vcCh[j].first) + abs(vcP[i].second - vcCh[j].second);
				if (dirGap < subMin) {
					subMin = dirGap;
				}
			}
			sum += subMin;
		}
		if (minDir > sum) {
			minDir = sum;
		}

		return;
	}

	for (int i = start; i < vc.size(); i++) {
		vcCh.push_back(make_pair(vc[i].first, vc[i].second));	//ġŲ�� ����
		solution(cnt + 1, k, i + 1, m);
		vcCh.erase(vcCh.begin() + (vcCh.size() - 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				vc.push_back(make_pair(i, j));	//ġŲ�� ��ǥ ����
			}
			if (arr[i][j] == 1) {
				vcP.push_back(make_pair(i, j));	//�� ��ǥ ����
			}
		}
	}

	//ġŲ���� 1������ �ִ� m�� ����
	for (int i = 1; i <= m; i++) {
		solution(0, i, 0, m);
	}

	cout << minDir << '\n';

	return 0;
}