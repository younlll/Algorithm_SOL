#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;	// 사람 수

	vector<int> vc;	// 인출시간을 담을 곳

	// 0부터 N(사람수) 만큼 반복하여 인출시간 입력
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vc.push_back(tmp);
	}

	sort(vc.begin(), vc.end());

	int answer = 0;
	int tmpSum = 0;
	for (int i = 0; i < N; i++) {
		tmpSum += vc[i];
		answer += tmpSum;
	}

	cout << answer << '\n';

	return 0;
}