// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/1475
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[10] = {};
	int num;
	cin >> num;

	while (num > 0) {
		arr[num % 10]++;
		num /= 10;
	}

	int a = (arr[6] + arr[9]) / 2;
	arr[6] = arr[9] = (arr[6] + arr[9]) % 2 == 0 ? a : a + 1;

	int result = *max_element(arr, arr + 10);

	cout << result << '\n';

	return 0;
}