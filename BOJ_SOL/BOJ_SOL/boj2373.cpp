// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/3273
#include <bits/stdc++.h>

using namespace std;

int arr[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, result = 0;;
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp]++;

	}

	cin >> x;
	for (int i = 1; i <= 1000000; i++) {
		int idx = x - i;
		if (idx > 1000000 || idx <= 0) {
			continue;
		}

		if (i != idx && arr[i] > 0 && arr[idx] > 0) {
			arr[i]--;
			arr[idx]--;
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}