#include <iostream>
#include <algorithm>

using namespace std;

int monthPlan[13];
int cost[4];
int monthPrice[13];
int arr[13];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {	//테스트케이스만큼 반복
		for (int i = 0; i < 4; i++) {
			cin >> cost[i];
		}

		for (int i = 1; i <= 12; i++) {
			cin >> monthPlan[i];
		}

		for (int i = 1; i <= 12; i++) {
			int tmp = cost[0] * monthPlan[i];
			monthPrice[i] = min(tmp, cost[1]);
		}

		/*for (int i = 1; i <= 12; i++) {
			arr[i] = arr[i - 1] + monthPrice[i];

			if (i - 3 >= 0) {
				if (cost[2] + arr[i - 3] < arr[i]) {
					arr[i] = cost[2] + arr[i - 3];
				}
			}
		}
		if (arr[12] > cost[3]) {
			arr[12] = cost[3];
		}*/

		int sum = 0;
		for (int i = 1; i <= 12; i++) {
			int tmp = 0;
			for (int j = i; j < i + 3 && j <= 12; j++) {
				tmp += monthPrice[j];
			}

			if (tmp > cost[2]) {
				sum += cost[2];
				i += 2;
			}
			else {
				sum += monthPrice[i];
			}
		}

		if (sum > cost[3]) {
			sum = cost[3];
		}

		cout << '#' << t << ' ' << arr[12] << '\n';
	}

	return 0;
}