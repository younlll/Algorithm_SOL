// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/2576
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[5], result = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		result += arr[i];
	}

	sort(arr, arr + 5);

	cout << result / 5 << '\n' << arr[2] << '\n';

	return 0;
}