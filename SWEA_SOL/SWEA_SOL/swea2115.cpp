#include <iostream>
#include <vector>
using namespace std;

int n, m, c;
int arr[10][10];
int selTmp = 0;
int selTmpMax = 0;
int priceA = 0;
int priceB = 0;
int result = 0;

void selection(int cnt, int lmt, int row, int col, int sum, int start) {
	if (cnt == lmt) {
		if (selTmp > selTmpMax) {
			selTmpMax = selTmp;
		}
		return;
	}

	for (int i = col; i < start + m; i++) {
		if (sum + arr[row][i] > c) {
			continue;
		}
		if (i + lmt > start + m && cnt == 0) {
			return;
		}
		selTmp += (arr[row][i] * arr[row][i]);
		selection(cnt + 1, lmt, row, i + 1, sum + arr[row][i], start);
		selTmp -= (arr[row][i] * arr[row][i]);
	}
}

int solution(int row, int col) {
	int tmpPrice = 0;
	for (int i = 1; i <= m; i++) {
		selTmp = selTmpMax = 0;
		selection(0, i, row, col, 0, col);
		if (tmpPrice < selTmpMax) {
			tmpPrice = selTmpMax;
		}
	}

	return tmpPrice;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> c;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				int tmp1 = solution(i, j);
				if (priceA < tmp1) {
					priceA = tmp1;
				}
				int qq = j + m;
				for (int p = i; p < n; p++, qq = 0) {
					for (int q = qq; q <= n - m; q++) {
						int tmp2 = solution(p, q);
						if (priceB < tmp2) {
							priceB = tmp2;
						}
					}
				}
				if (result < priceA + priceB) {
					result = priceA + priceB;
				}
				priceA = priceB = 0;
			}
		}
		cout << '#' << t << ' ' << result << '\n';
		priceA = priceB = result = 0;
	}
}