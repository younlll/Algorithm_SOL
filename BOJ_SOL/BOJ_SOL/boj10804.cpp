// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/1267
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[21];
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}
	
	int first, end;
	for (int i = 0; i < 10; i++) {
		cin >> first >> end;
		reverse(arr + first, arr + end + 1);
	}

	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}