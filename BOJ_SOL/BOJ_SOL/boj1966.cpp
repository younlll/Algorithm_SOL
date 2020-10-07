#include <iostream>
#include <queue>
using namespace std;

bool cmp(int n1, int n2) {
	return n1 > n2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	int n, m;
	while (T--) {
		int result = 0;
		cin >> n >> m;
		
		queue<int> idxQ;		//������ ó�� ��ġ�� ����
		queue<int> printQ;		//���� �켱������ ����
		priority_queue<int> pq;		//���� �߿䵵 �������� ����
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			printQ.push(tmp);
			pq.push(tmp);
			idxQ.push(i);
		}

		//ť�� �����Ͱ� �ִ� ���� �ݺ�
		while (!printQ.empty()) {

			if (pq.top() == printQ.front()) {	//���� �켱������ ����Ʈ �켱������ ���� ���

				int idx = idxQ.front();	//���� �ʱ� ��ġ

				//���
				idxQ.pop();
				printQ.pop();
				pq.pop();
				result++;	//���° ������� üũ

				if (idx == m) {	//����� ���� ��ġ�� �ñ��� ���� ������ ���� ��� ����
					break;
				}
			}
			else {	//���� �켱������ ����Ʈ �켱������ �ٸ� ���

				//����Ʈ ť ���� ���������� �ű�
				idxQ.push(idxQ.front());
				printQ.push(printQ.front());
				idxQ.pop();
				printQ.pop();
			}
		}
		
		cout << result << '\n';
	}

	return 0;
}