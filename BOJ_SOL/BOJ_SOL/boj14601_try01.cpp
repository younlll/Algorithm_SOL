#include <iostream>

using namespace std;

struct WORK {
	int day;
	int pay;
};

WORK work[15];
int N, answer = 0;

void solution(int idx, int workDay, int workPay) {
	if (workDay >= N || idx > N - 1) {	//
		if (answer < workPay) {
			answer = workPay;
		}
		return;
	}

	for (int i = idx; i < N; i++) {
		if (i + work[i].day <= N) {
			solution(i + work[i].day, workDay + work[i].day, workPay + work[i].pay);
		}
		else {
			solution(i + 1, workDay, workPay);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> work[i].day >> work[i].pay;
	}

	solution(0, 0, 0);

	cout << answer << '\n';
}