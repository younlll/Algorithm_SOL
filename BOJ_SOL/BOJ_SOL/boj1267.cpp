// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/1267
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Y = 0, M = 0, tmp;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		Y += 10;
		M += 15;
		if (tmp / 30 > 0) {
			Y += (tmp / 30 * 10);
		}
		if (tmp / 60 > 0) {
			M += (tmp / 60 * 15);
		}
	}

	if (Y < M) {
		cout << "Y " << Y << '\n';
	}
	else if (Y > M) {
		cout << "M " << M << '\n';
	}
	else {
		cout << "Y M " << Y << '\n';
	}

	return 0;
}