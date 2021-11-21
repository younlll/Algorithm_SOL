#include <iostream>
#include <vector>

using namespace std;

string answer[3];
vector<int> vc[26];

// ���� ��ȸ
void solution_pre(int idx) {
	if (idx == -1) {	// ����� �ڽ� ��尡 ���� ���(��Ʈ�� -1�� ���� ���)
		return;
	}

	answer[0] += (char(idx + 65));	// ��Ʈ ��带 �߰�
	solution_pre(vc[idx][0]);	// ���� �ڽĳ��
	solution_pre(vc[idx][1]);	// ������ �ڽĳ��
}

// ���� ��ȸ
void solution_ind(int idx) {
	if (idx == -1) {	// �� �̻� Ž���� ��尡 ���� ���
		return;
	}

	solution_ind(vc[idx][0]);	// ���� �ڽĳ�� Ž��
	
	//���� �ڽĳ���� Ž���� ���� ���
	answer[1] += (char(idx + 65));
	solution_ind(vc[idx][1]);	// ������ �ڽĳ�� Ž��
}

// ���� ��ȸ
void solution_post(int idx) {
	if (idx == -1) {	// �� �̻� Ž���� ��尡 ���� ���
		return;
	}

	solution_post(vc[idx][0]);	// ���� �ڽ� ��� Ž��
	solution_post(vc[idx][1]);	// ������ �ڽ� ��� Ž��
	answer[2] += (char(idx + 65));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;	// ����� ����

	char ch1, ch2, ch3;
	for (int i = 0; i < N; i++) {
		cin >> ch1 >> ch2 >> ch3;

		if (ch2 != '.') {
			vc[ch1 - 65].push_back(ch2 - 65);
		}
		else {
			vc[ch1 - 65].push_back(-1);
		}
		if (ch3 != '.') {
			vc[ch1 - 65].push_back(ch3 - 65);
		}
		else {
			vc[ch1 - 65].push_back(-1);
		}
	}

	solution_pre(0);
	solution_ind(0);
	solution_post(0);

	for (int i = 0; i < 3; i++) {
		cout << answer[i] << '\n';
	}
}