// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/1919
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str1, str2;
	cin >> str1 >> str2;

	int arr[27] = {};
	for (char c : str1) {
		arr[c - 'a']++;
	}

	int cnt = 0;
	for (char c : str2) {
		if (arr[c - 'a'] > 0) {
			arr[c - 'a']--;
			cnt++;
		}
	}

	cout << str1.length() + str2.length() - (2 * cnt) << '\n';

	return 0;
}