#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 0: 48    9: 57
// 1: true  0: false
struct Trie {
	bool fin;	//���ڿ��� ��������� ��Ÿ���� ����
	Trie* next[10];

	// ������
	Trie() {
		fin = false;
		for (int i = 0; i < 10; i++) {
			next[i] = NULL;
		}
	}

	// �Ҹ���
	~Trie() {
		for (int i = 0; i <= 9; i++) {
			if (next[i]) {
				delete next[i];
			}
		}
	}

	// ���ڿ��� Ʈ���̿� ����
	void insert(const char* ch) {
		if (*ch == NULL) {	// ���� �Է��� ��������
			fin = true;
		}
		else {
			int curr = *ch - '0';
			if (next[curr] == NULL) {	// ch�� ���ڷ� �����ϴ� ���ڿ� ���� �Է��� ��Ÿ��
				next[curr] = new Trie();
			}
			//cout << ch + 1 << '\n';
			next[curr]->insert(ch + 1);	//���� ���ڿ��� ����
		}
	}

	bool find(const char* ch) {
		if (*ch == NULL) {
			if (fin == true) {
				return true;
			}
			return false;
		}
		int curr = *ch - '0';
		if (next[curr] == NULL) {
			return false;
		}

		if (*ch != NULL && fin == true) {
			return false;
		}
		return next[curr]->find(ch + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n;
	cin >> t;

	// �Էµ� �׽�Ʈ���̽���ŭ �ݺ�
	while (t--) {
		cin >> n;

		Trie* trie = new Trie();
		vector<string> vc;
		// n���� ��ȭ��ȣ��ŭ �ݺ��Ͽ� ��ȭ��ȣ �Է�
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			vc.push_back(str);
			const char* ch = str.c_str();	// string to char
			//cout << ch << '\n';

			trie->insert(ch);
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			const char* ch = vc[i].c_str();	// string to char
			//cout << vc[i] << ' ' << trie->find(ch) << '\n';

			if (trie->find(ch)) {
				cnt++;
			}
		}

		if (cnt == n) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << "\n";
		}
	}
}