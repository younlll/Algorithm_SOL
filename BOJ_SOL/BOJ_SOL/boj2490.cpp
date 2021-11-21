// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/2490
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	string s = "DCBAE";

	for (int i = 0; i < 3; i++) {
		a = 0;
		for (int j = 0; j < 4; j++) {
			cin >> b;
			a += b;
		}

		cout << s[a] << '\n';
	}

	return 0;
}