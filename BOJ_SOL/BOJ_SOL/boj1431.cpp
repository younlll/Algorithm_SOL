#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length()) {	// 1)두 시리얼넘버의 길이가 다른경우 더 짧은것이 앞으로 오도록 정렬
		return a.length() < b.length();
	}
	else {	//두 시리얼넘버의 길이가 같은 경우
		// 2)
		int sumA = 0;
		int sumB = 0;
		//각 자리의 숫자인 것의 합을 구한다
		for (int i = 0; i < a.length(); i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
				sumA += (a[i] - '0');
			}
			if (b[i] - '0' >= 0 && b[i] - '0' <= 9) {
				sumB += (b[i] - '0');
			}
		}
		//숫자 합이 같지 않는 경우, 더 작은것이 먼저 오도록 정렬
		if (sumA != sumB) {
			return sumA < sumB;
		}

		// 1), 2) 조건을 둘다 만족 못하는 경우, 사전 순서로 정렬
		return a < b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<string> vc;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		vc.push_back(tmp);
	}

	sort(vc.begin(), vc.end(), compare);

	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << '\n';
	}
}