#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	int n, m, tmp;
	set<int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.insert(tmp);
	}

	cin >> m;
	vector<int> vc(m);
	for (int i = 0; i < m; i++) {
		cin >> vc[i];
	}

	for (int i = 0; i < m; i++) {
		cout << s.count(vc[i]) << '\n';
	}

	return 0;
}