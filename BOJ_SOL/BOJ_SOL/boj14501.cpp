#include <iostream>
#include <cmath>
using namespace std;

int arrT[15];
int arrP[15];
int dp[15];
int n;
int maxResult = 0;
int maxCnt = 0;
void solution(int idx, int cost) {
	if (idx >= n + 1) {
		if (maxResult < cost) {
			maxResult = cost;
		}
		return;
	}

	if (idx + arrT[idx] <= n + 1) {
		solution(idx + arrT[idx], cost + arrP[idx]);
	}
	if (idx + 1 <= n + 1) {
		solution(idx + 1, cost);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;

	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		arrT[i] = a;
		arrP[i] = b;
	}

	solution(1, 0);
	cout << maxResult << '\n';
}