#include <iostream>

using namespace std;

int N;
int arr[16][2] = { 0, };
int result = 0;

void solution(int idx, int cost) {
	if (idx >= N) {
		if (result < cost) {
			result = cost;
		}
		return;
	}

	if (idx + arr[idx][0] <= N) {
		solution(idx + arr[idx][0], cost + arr[idx][1]);
	}
	if (idx + 1 <= N) {
		solution(idx + 1, cost);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int T, P;
	for (int i = 0; i < N; i++) {
		cin >> T >> P;
		arr[i][0] = T;
		arr[i][1] = P;
	}

	solution(0, 0);
	cout << result << '\n';

	return 0;
}