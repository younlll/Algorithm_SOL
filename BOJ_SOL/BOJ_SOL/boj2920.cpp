#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[8];
	int gap;
	string result;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		if (i != 0) {
			if (result == "ascending") {
				if (arr[i] - arr[i - 1] != 1) {
					result = "mixed";
				}
			}
			else if (result == "descending") {
				if (arr[i - 1] - arr[i] != 1) {
					result = "mixed";
				}
			}
		}
		else if (i == 0) {
			if (arr[i] == 1) {
				result = "ascending";
			}
			else if (arr[i] == 8) {
				result = "descending";
			}
			else {
				result = "mixed";
			}
		}
	}

	cout << result << '\n';

	return 0;
}