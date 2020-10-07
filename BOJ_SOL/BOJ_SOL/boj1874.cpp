#include <iostream>
#include <stack>
using namespace std;

int arr[100001];
char result[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int num = 1;
	int j = 0;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while(1) {
			if (st.empty()) {	//������ ��������� �񱳱��� �����Ƿ� PUSH
				st.push(num++);	//������ �� ���ڸ� ��Ÿ���� ���� num++
				result[j++] = '+';	//result�� ���� index�� ����Ű�� ���� j++
				continue;
			}

			if (st.top() > arr[i]) {	//���ÿ� ���� ���� �������� �����̹Ƿ� st.top() > arr[i]�̸� ���³� �� ����
				cout << "NO\n";
				return 0;
			}
			else if (st.top() == arr[i]) {	//st.top() == arr[i]�̸� ��ġ�ϹǷ� POP
				st.pop();
				result[j++] = '-';
				break;
			}
			else {	//���� stack�� ���� ū ������ �񱳼��ڰ� ū ��� PUSH
				st.push(num++);
				result[j++] = '+';
			}
		}
	}

	if (!st.empty()) {
		cout << "NO\n";
		return 0;
	}

	for (int i = 0; i < j; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}