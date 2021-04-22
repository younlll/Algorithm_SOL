#include <iostream>

using namespace std;

int N;
int arr[4];
int numArr[100];
int Min = 9879879870, Max = -9879879870;

void solution(int result, int idx) {
	if (idx >= N) {
		if (result < Min) {
			Min = result;
		}
		if (result > Max) {
			Max = result;
		}
		return;
	}

	for (int j = 0; j < 4; j++) {
		int tmp = result;
		if (arr[j] > 0) {
			if (j == 0) {
				tmp += numArr[idx];
			}
			else if (j == 1) {
				tmp -= numArr[idx];
			}
			else if (j == 2) {
				tmp *= numArr[idx];
			}
			else if (j == 3) {
				if (tmp < 0) {
					int t = tmp * -1;
				}
				tmp /= numArr[idx];
			}
			arr[j]--;
			
			solution(tmp, idx + 1);

			arr[j]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numArr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	solution(numArr[0], 1);

	cout << Max << '\n' << Min << '\n';
}