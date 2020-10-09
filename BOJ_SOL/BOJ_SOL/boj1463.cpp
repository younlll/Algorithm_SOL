#include <iostream>
using namespace std;

int dp[10000000];

int solution(int n) {
	if (n == 1) {
		return 0;
	}

	if (dp[n] > 0) {
		return dp[n];
	}

	dp[n] = solution(n - 1) + 1;

	if (n % 2 == 0) {
		int tmpR = solution(n / 2) + 1;
		if (tmpR < dp[n]) {
			dp[n] = tmpR;
		}
	}

	if (n % 3 == 0) {
		int tmpR = solution(n / 3) + 1;
		if (tmpR < dp[n]) {
			dp[n] = tmpR;
		}
	}

	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int result = solution(n);
	cout << result << '\n';

	return 0;
}