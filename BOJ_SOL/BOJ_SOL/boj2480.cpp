// Authored by : youn
// Co-authored by : -
// http://boj.kr/0b6d46b39f7c4fc8afd6d0c7d21e7bad

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c) {
		cout << 10000 + a * 1000;
	}
	else if (a == b || a == c) {
		cout << 1000 + a * 100;
	}
	else if (b == c) {
		cout << 1000 + b * 100;
	}
	else {
		cout << max({ a, b, c }) * 100;
	}

	return 0;
}

