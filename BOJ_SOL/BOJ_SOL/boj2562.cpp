// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/2562
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num, maxValue = 0, maxIdx = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> num;
		if (maxValue < num) {
			maxValue = num;
			maxIdx = i;
		}
	}

	cout << maxValue << '\n' << maxIdx << '\n';

	return 0;
}