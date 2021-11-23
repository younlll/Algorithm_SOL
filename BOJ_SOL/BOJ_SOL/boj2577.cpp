// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/2577
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[10] = {};
	int multi = 1;
	int tmp;
	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		multi *= tmp;
	}

	while (multi > 0) {
		arr[multi % 10]++;
		multi /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}