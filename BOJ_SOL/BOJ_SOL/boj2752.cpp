#include <iostream>

#define INF 987987987
using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr);

	int arr[3];
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 3; i++) {
		int min = INF;
		int idx = 0;

		for (int j = i; j < 3; j++) {
			if (min > arr[j]) {
				min = arr[j];
				idx = j;
			}
		}

		int tmp = arr[idx];
		arr[idx] = arr[i];
		arr[i] = tmp;
	}

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}