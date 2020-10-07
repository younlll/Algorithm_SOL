#include <iostream>
using namespace std;

int Max = 0;
int cardArr[101];
bool chkCard[101];

void solution(int n, int m, int cnt, int sum) {
	if (cnt == 3) {
		if (Max < sum && sum <= m) {
			Max = sum;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!chkCard[i]) {
			chkCard[i] = true;
			solution(n, m, cnt + 1, sum + cardArr[i]);
			chkCard[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cardArr[i];
	}
	solution(n, m, 0, 0);

	cout << Max << '\n';

	return 0;
}