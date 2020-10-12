#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//けけけけ
			if (j <= m - 4) {
				int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
				if (result < sum) {
					result = sum;
				}
			}
			/*け
			  け
			  け
			  け*/
			if (i <= n - 4) {
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
				if (result < sum) {
					result = sum;
				}
			}

			/*けけ
			  けけ*/
			if (i <= n - 2 && j <= m - 2) {
				int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j];
				if (result < sum) {
					result = sum;
				}
			}

			/*  け    けけけ
			  けけけ    け*/
			if (j <= m - 3) {
				int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
				if (i == 0) {
					sum += arr[i + 1][j + 1];
				}
				else if (i == n - 1) {
					sum += arr[i - 1][j + 1];
				}
				else {
					int tmp = max(arr[i + 1][j + 1], arr[i - 1][j + 1]);
					sum += tmp;
				}

				if (result < sum) {
					result = sum;
				}
			}

			/*  け   け
			  けけ   けけ
				け   け*/
			if (i <= n - 3) {
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
				if (j == 0) {
					sum += arr[i + 1][j + 1];
				}
				else if (j == m - 1) {
					sum += arr[i + 1][j - 1];
				}
				else {
					int tmp = max(arr[i + 1][j + 1], arr[i + 1][j - 1]);
					sum += tmp;
				}

				if (result < sum) {
					result = sum;
				}
			}
			/*け      けけけ      け  けけけ
			  けけけ      け  けけけ  け      */
			if (i <= n - 2 && j <= m - 3) {
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
				if (result < sum) {
					result = sum;
				}
				sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
				if (result < sum) {
					result = sum;
				}
				sum = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 2];
				if (result < sum) {
					result = sum;
				}
				sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
				if (result < sum) {
					result = sum;
				}
			}
			/* け      け  けけ  けけ
			   け      け  け      け
			   けけ  けけ  け      け*/
			if (i <= n - 3 && j <= m - 2) {
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
				if (result < sum) {
					result = sum;
				}
				sum = arr[i + 2][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
				if (result < sum) {
					result = sum;
				}
				sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1];
				if (result < sum) {
					result = sum;
				}
				sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
				if (result < sum) {
					result = sum;
				}
			}
			/* け      け
			   けけ  けけ
				 け  け    */
			if (i <= n - 3 && j <= m - 2) {
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
				if (result < sum) {
					result = sum;
				}
				sum = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j];
				if (result < sum) {
					result = sum;
				}
			}
			
			/* けけ      けけ
				 けけ  けけ   */
			if (i <= n - 2 && j <= m - 3) {
				int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
				if (result < sum) {
					result = sum;
				}
				sum = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2];
				if (result < sum) {
					result = sum;
				}
			}
		}
	}

	cout << result << '\n';

	return 0;
}