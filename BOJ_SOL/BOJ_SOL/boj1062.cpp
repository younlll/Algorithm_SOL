#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, answer = 0;
vector<string> v;
int flag;


void solution(int cnt, int start) {
	int chk = 0;
	if (cnt >= K) {
		for (int i = 0; i < v.size(); i++) {
			string tmp = v[i];
			int c = 0;
			for (int j = 0; j < tmp.length(); j++) {
				int tmpNum = tmp[j] - 'a';

				if ((1 << tmpNum) & flag) {	//�ش� ���ĺ��� ��Ʈ�� �����ִ��� Ȯ��
					c++;
				}
			}

			// ��� ���ڷ� �ܾ ���� �� �ִ� ��� ī����
			if (c == tmp.length()) {
				chk++;
			}
		}

		answer = max(answer, chk);	// ���� �� �ִ� �ܾ��� �ִ밪 ���ϱ�

		return;
	}

	for (int i = start; i < 26; i++) {
		if ((flag & (1 << i)) == 0) {
			flag |= (1 << i);	// ��Ʈ�ѱ�
			solution(cnt + 1, i + 1);
			flag &= ~(1 << i);	// ��Ʈ����
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
	}

	// ���� ���ڰ� 5�� �̸��̸� anta/tica�� ���� �� ���� ���
	if (K < 5) {
		cout << 0 << '\n';
		return 0;
	}
	else if (K == 26) {
		cout << N << '\n';
		return 0;
	}

	// or������ ���� ��Ʈ �ѱ�
	flag |= 1 << ('a' - 'a');
	flag |= 1 << ('n' - 'a');
	flag |= 1 << ('t' - 'a');
	flag |= 1 << ('i' - 'a');
	flag |= 1 << ('c' - 'a');

	solution(5, 0);
	cout << answer << '\n';

	return 0;
}