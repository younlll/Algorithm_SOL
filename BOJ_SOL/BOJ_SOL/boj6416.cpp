#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<int, int> m;
	set<int> s;
	int tc = 1;

	while (1) {
		int u, v;
		cin >> u >> v;

		//
		if (u == -1 && v == -1) {
			break;
		}

		if (u == 0 && v == 0) {
			bool chk = false;
			int cnt = 0;

			// s�� ũ�⸸ŭ �ݺ��ϸ鼭 m�� ���� ���� �ִ� ��� ã��
			// m�� ������� ���� s�� ��Ʈ�� ��Ÿ����
			// ��Ʈ�� �����ϹǷ� chk(Ʈ������ üũ)�� true�� �ٲٱ�
			// ��Ʈ�� ������ Ȯ���ϱ� ���� cnt�� ���ؼ� ������ ī�������ش�
			for (auto iter : s) {
				if (m.find(iter) == m.end()) {
					chk = true;
					cnt++;
				}
			}

			// m�� ũ�⸸ŭ value(�����ִ� �θ����� ��)�� 1�� �ʰ��� ��� ã��
			// value�� 1�� �ʰ���� chk(Ʈ������ üũ)�� false�� �ٲ۴�
			for (auto iter : m) {
				if (iter.second > 1) {
					chk = false;
				}
			}

			// ��尡 1�� �̻��̸鼭 ��Ʈ�� 2�� �̻� �̰ų� chk�� false�� ���� tree�� �ƴѰ��
			// ��尡 0�� �̰ų� 1�� �̻��϶� ��Ʈ�� 1���̸鼭 chk�� true��� tree�̴�
			if (s.size() > 0 && (cnt > 1 || !chk)) {
				cout << "Case " << tc << " is not a tree.\n";
			}
			else {
				cout << "Case " << tc << " is a tree.\n";
			}
			tc++;
			m.clear();
			s.clear();

			continue;
		}

		if (m.find(v) == m.end()) {
			m.insert({ v, 1 });
		}
		else {
			m[v]++;
		}

		s.insert(v);
		s.insert(u);
	}
}