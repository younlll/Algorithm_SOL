#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 51

using namespace std;

struct CHINFO {
	int x;
	int y;
	bool life;
};

int N, M, answer = 987987987;
int map[MAX][MAX];
vector<CHINFO> vc;
vector<pair<int, int>> hinfo;

void mesureDir() {
	int sum = 0;
	vector<int> vSize;
	vSize.resize(hinfo.size(), 987987987);	// �� ���� ġŲ�Ÿ� ���庯�� �ʱ�ȭ
	for (int i = 0; i < vc.size(); i++) {
		if (vc[i].life) {	//������� ���� ġŲ���̶��
			for (int j = 0; j < hinfo.size(); j++) {
				int tmp = abs(hinfo[j].first - vc[i].x) + abs(hinfo[j].second - vc[i].y);	//ġŲ������ �Ÿ� ���ϱ�
				if (vSize[j] > tmp) {	//�ּ� ġŲ������ �Ÿ� ����
					vSize[j] = tmp;
				}
			}
		}
	}

	for (int i = 0; i < vSize.size(); i++) {	//�� ���� ġŲ�Ÿ��� �� ���ϱ�
		sum += vSize[i];
	}
	
	if (answer > sum) {	//�ּ� ġŲ�Ÿ� ���ϱ�
		answer = sum;
	}
}

void solution(int cnt, int idx, int nc) {
	if (cnt >= nc) {	//������ ġŲ�� ��(nc)�� ������� ���� ġŲ�� ��(nc)�� �������
		mesureDir();
		return;
	}

	for (int i = idx; i < vc.size(); i++) {
		vc[i].life = true;	// ������� ���� ġŲ�� ����
		solution(cnt + 1, i + 1, nc);
		vc[i].life = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				vc.push_back({ i, j, false });	//ġŲ�� ���� �Է�(x��ǥ, y��ǥ, �������)
			}
			else if (map[i][j] == 1) {
				hinfo.push_back({ i, j });	//�� ��ǥ
			}
		}
	}

	for (int i = 1; i <= M; i++) {	// 1������ �ִ� M�� ���� ġŲ�� ����
		solution(0, 0, i);
	}

	cout << answer << '\n';

	return 0;
}