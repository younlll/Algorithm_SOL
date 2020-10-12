#include <iostream>
#include <climits>
using namespace std;

int sMap[31][11];
int n, m, h;
int minCnt = INT_MAX;

bool matchLine() {
	int start;
	for (int i = 1; i <= n; i++) {
		start = i;
		for (int j = 1; j <= h; j++) {
			if (sMap[j][start] != 0) {
				start++;
			}
			else if (sMap[j][start - 1] != 0) {
				start--;
			}
		}

		if (start != i) {
			return false;
		}
	}

	return true;
}

void chkMap(int cnt, int sX, int sY) {

	if (cnt >= minCnt) {
		return;
	}

	if (matchLine()) {
		minCnt = cnt;
		return;
	}

	if (cnt == 3) {
		return;
	}

	for (int i = sX; i <= h; i++) {
		for (int j = sY; j < n; j++) {
			if (sMap[i][j] == 1 || sMap[i][j+1] == 1|| sMap[i][j-1] == 1) {
				continue;
			}

			sMap[i][j] = 1;
			chkMap(cnt + 1, i, j + 2);
			sMap[i][j] = 0;
		}
		sY = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> h;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		sMap[x][y] = 1;
	}

	if (m == 0) {
		cout << 0 << '\n';
		return 0;
	}

	chkMap(0, 1, 1);
	if (minCnt > 3) {
		cout << "-1\n";
		return 0;
	}
	cout << minCnt << '\n';

	return 0;
}