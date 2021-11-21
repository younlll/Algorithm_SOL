#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int year, result = 0;
	cin >> year;
	
	if (year % 4 == 0 && year % 100 != 0) {
		result = 1;
	}
	else if (year % 400 == 0) {
		result = 1;
	}

	cout << result << '\n';

	return 0;
}