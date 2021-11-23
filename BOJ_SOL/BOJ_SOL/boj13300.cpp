// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/13300
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[14] = {};
	int N, K, result = 0;
	int S, Y;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> S >> Y;

		if (S == 0) {
			arr[Y]++;
		}
		else {
			arr[Y + 6]++;
		}
	}

	for (int i = 1; i <= 6; i++) {
		result += arr[i] / K;
		result += arr[i + 6] / K;

		if (arr[i] % K != 0) {
			result++;
		}
		if (arr[i + 6] % K != 0) {
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}