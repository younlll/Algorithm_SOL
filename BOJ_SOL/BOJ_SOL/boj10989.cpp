//#include <iostream>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int N;
//	cin >> N;
//	map<int, int> m;
//
//	for (int i = 0; i < N; i++) {
//		int tmp;
//		cin >> tmp;
//		if (m.find(tmp) == m.end()) {	//map m�� tmp�� ���� ���
//			m[tmp] = 1;
//		}
//		else {	//map m�� tmp�� �ִ� ���
//			m[tmp]++;
//		}
//	}
//
//	for (auto& p : m) {
//		for (int i = 0; i < p.second; i++) {
//			cout << p.first << '\n';
//		}
//	}
//} --> �ð��ʰ��� ���Դ�....�Ф�

#include <iostream>
#include <set>

using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	set<int> s;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
		s.insert(tmp);
	}

	for (auto& p : s) {
		for (int i = 0; i < arr[p]; i++) {
			cout << p << '\n';
		}
	}
}