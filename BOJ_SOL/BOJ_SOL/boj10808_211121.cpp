// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/10808
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	int arr[26] = {};
	cin >> str;

	for (char c : str) {
		arr[c - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}