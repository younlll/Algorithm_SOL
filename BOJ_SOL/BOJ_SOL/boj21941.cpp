#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string S;
int M;
map<string, int> m;
vector<string> vc;
int pointArr[1001];

int solution(int num) {
	/* �Էµ� ���ڿ� Ž�� ���� ��ġ�� �Է� ���ڿ��� �� ���̿� ���ų� ũ�ٸ�
	 * �� �̻� Ž���� ���ڿ��� ���ٴ� ���̹Ƿ� 0 ���� */
	if (num >= S.length()) {
		return 0;
	}

	if (pointArr[num] != 0) {
		return pointArr[num];
	}

	// �Էµ� ���� ���ڿ� ũ�⸸ŭ �ݺ�
	for (int i = 0; i < vc.size(); i++) {
		string key = vc[i];	//�������ڿ�
		int point = m[key];	//�������ڿ� ����Ʈ

		/* num(Ž��������ġ) + key.length()(�������ڿ� ����) <= S.length()(�Է¹��ڿ� ����)
		 * �ش� ���� �����Ǿ�� �������ڿ����� �ľ��� �ȴ�
		 * num(Ž��������ġ) + key.length()(�������ڿ� ����) �� ���� �� ũ�ٸ� �������ڿ��� ã�� ����
		 * �Է¹��ڿ��� ������ */
		bool tog = false;
		if (num + key.length() <= S.length()) {
			for (int j = 0; j < key.length(); j++) {
				if (key[j] != S[num + j]) {
					tog = true;
					break;
				}
			}

			//�Է¹��ڿ����� �������ڿ��� ã�� ���
			if (!tog) {
				pointArr[num] = max(pointArr[num], solution(num + key.length()) + point);
			}
		}
	}

	pointArr[num] = max(pointArr[num], solution(num + 1) + 1);

	return pointArr[num];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> M;
	
	string str_tmp;
	int int_tmp;
	for (int i = 0; i < M; i++) {
		cin >> str_tmp >> int_tmp;
		vc.push_back(str_tmp);
		m.insert({ str_tmp, int_tmp });
	}

	int answer = solution(0);

	cout << answer << '\n';
}