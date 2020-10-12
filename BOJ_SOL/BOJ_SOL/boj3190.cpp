#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int mapArr[110][110];

//           ��  ��  ��  ��
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, l;
	cin >> n >> k;

	//�����ǥ �Է�
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		mapArr[x][y] = 1;
	}

	cin >> l;
	vector<pair<int, char>> vc;

	//���̵� ��� �Է�
	for (int i = 0; i < l; i++) {
		pair<int, char> p;
		cin >> p.first >> p.second;
		vc.push_back(p);
	}

	deque<pair<int, int>> Deque;
	pair<int, int> dPair;
	dPair.first = dPair.second = 1;	//ó�� ���� ���� ��ġ �Է�
	mapArr[1][1] = 2;
	Deque.push_back(dPair);

	int len = vc.size();
	int vec = 0;
	int result = 0;
	//�Էµ� �̵���ŭ �ݺ�
	int i = 0;
	int move = vc[i].first;
	while (1) {
		//���� �̵��� ��
		int next_x = Deque.front().first + dx[vec];
		int next_y = Deque.front().second + dy[vec];

		result++;	//�̵�Ƚ�� ����

		
		if (next_x < 1 || next_x > n || next_y < 1 || next_y > n) {	//������ ��� ����
			cout << result << '\n';
			return 0;
		}		
		else if (mapArr[next_x][next_y] == 2) {	//�� ���뿡 �ε��� ���
			cout << result << '\n';
			return 0;
		}
		else if (mapArr[next_x][next_y] == 1) {	//����� �ִٸ� �����ġ�� ���� �Ӹ���
			dPair.first = next_x;
			dPair.second = next_y;
			Deque.push_front(dPair);
			mapArr[next_x][next_y] = 2;
		}
		else {
			//����ĭ �̵�
			dPair.first = next_x;
			dPair.second = next_y;
			Deque.push_front(dPair);
			mapArr[next_x][next_y] = 2;
			mapArr[Deque.back().first][Deque.back().second] = 0;
			Deque.pop_back();
		}

		if ((result == move && vc.size() > i)) {
			//���� ���⼺ ����
			if (vc[i].second == 'D') {
				vec++;
				if (vec > 3) {
					vec = 0;
				}
			}
			else if (vc[i].second == 'L') {
				vec--;
				if (vec < 0) {
					vec = 3;
				}
			}
			if (i < vc.size() - 1) {
				move = vc[++i].first;
			}
		}
	}

	cout << result << '\n';

	return 0;

}