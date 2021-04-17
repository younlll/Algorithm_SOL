#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length()) {	// 1)�� �ø���ѹ��� ���̰� �ٸ���� �� ª������ ������ ������ ����
		return a.length() < b.length();
	}
	else {	//�� �ø���ѹ��� ���̰� ���� ���
		// 2)
		int sumA = 0;
		int sumB = 0;
		//�� �ڸ��� ������ ���� ���� ���Ѵ�
		for (int i = 0; i < a.length(); i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
				sumA += (a[i] - '0');
			}
			if (b[i] - '0' >= 0 && b[i] - '0' <= 9) {
				sumB += (b[i] - '0');
			}
		}
		//���� ���� ���� �ʴ� ���, �� �������� ���� ������ ����
		if (sumA != sumB) {
			return sumA < sumB;
		}

		// 1), 2) ������ �Ѵ� ���� ���ϴ� ���, ���� ������ ����
		return a < b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<string> vc;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		vc.push_back(tmp);
	}

	sort(vc.begin(), vc.end(), compare);

	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << '\n';
	}
}