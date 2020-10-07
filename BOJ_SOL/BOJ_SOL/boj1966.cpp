#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	string input; //�Է� ������ ����
	while (T--) {
		stack<char> frontCh;	//Ŀ�� �� ����
		stack<char> backCh;		//Ŀ�� �� ����

		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '<') {	//Ŀ�� ��ĭ ������ �̵�
				if (!frontCh.empty()) {	//Ŀ�� �տ� ���ڰ� �ִ� ���
					//Ŀ�� �տ� �ִ� ���ڸ� Ŀ�� �ڷ� ������
					backCh.push(frontCh.top());
					frontCh.pop();
				}
			}
			else if (input[i] == '>') {	//Ŀ�� ��ĭ �ڷ� ������
				if (!backCh.empty()) {	//Ŀ�� �ڿ� ���ڰ� �ִ� ���
					//Ŀ�� �� ���ڸ� Ŀ�� ������ ������
					frontCh.push(backCh.top());
					backCh.pop();
				}
			}
			else if (input[i] == '-') {	//�齺���̽�
				if (!frontCh.empty()) {	//Ŀ�� �� ���ڰ� �ִ� ���
					frontCh.pop();	//Ŀ�� �� ���� ����
				}
			}
			else {
				frontCh.push(input[i]);	//�����Է�
			}
		}

		while (!frontCh.empty()) {	//�ùٸ� ����� ���� Ŀ�� �� ���ڵ��� Ŀ�� �ڷ� ����
			backCh.push(frontCh.top());
			frontCh.pop();
		}

		//���
		while (!backCh.empty()) {
			cout << backCh.top();
			backCh.pop();
		}
		cout << '\n';
	}

	return 0;
}