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
			if (st.empty()) {	//스택이 비어있으면 비교군이 없으므로 PUSH
				st.push(num++);	//다음에 들어갈 숫자를 나타내기 위해 num++
				result[j++] = '+';	//result의 다음 index를 가리키기 위해 j++
				continue;
			}

			if (st.top() > arr[i]) {	//스택에 들어가는 수는 오름차순 기준이므로 st.top() > arr[i]이면 나태낼 수 없다
				cout << "NO\n";
				return 0;
			}
			else if (st.top() == arr[i]) {	//st.top() == arr[i]이면 일치하므로 POP
				st.pop();
				result[j++] = '-';
				break;
			}
			else {	//현재 stack의 가장 큰 값보다 비교숫자가 큰 경우 PUSH
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