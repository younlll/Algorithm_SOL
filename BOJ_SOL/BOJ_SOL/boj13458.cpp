#include <iostream>
using namespace std;

long long arr[1000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, b, c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> b >> c;

	long long result = 0;
	for (int i = 0; i < n; i++) {
		result += 1;
		arr[i] -= b;
		if (arr[i] > 0) {
			result += (arr[i] / c);
			if (arr[i] % c != 0) {
				result++;
			}
		}
	}

	cout << result << '\n';
}