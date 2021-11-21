#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	int arr[26];
	cin >> s;

	fill(arr, arr + 26, 0);

	for (char c : s) {
		arr[(int)c - 97] += 1;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}