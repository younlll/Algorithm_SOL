// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/2576
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int result = 0, minValue = 987987987, tmp;
	for (int i = 0; i < 7; i++) {
		cin >> tmp;
		if (tmp % 2 == 1) {
			result += tmp;
			if (minValue > tmp) minValue = tmp;
		}
		
	}
	
	if (result == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << result << '\n' << minValue << '\n';
	}

	return 0;
}