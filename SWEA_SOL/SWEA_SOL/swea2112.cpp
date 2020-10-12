#include <iostream>
using namespace std;

int d, w, k;
int flArr[15][25];
int cpFlArr[15][25];
int minVal = 987987897;
bool chkFilm() {
	for (int j = 0; j < w; j++) {
		int tmp = 1;
		int max = 0;
		for (int i = 1; i < d; i++) {
			if (cpFlArr[i][j] != cpFlArr[i - 1][j]) {
				if (max < tmp) {
					max = tmp;
				}
				tmp = 1;
				continue;
			}
			tmp += 1;
		}
		if (max < tmp) {
			max = tmp;
		}
		if (max < k) {
			return false;
		}
	}

	return true;
}
void solution(int cnt, int pos) {
	if (chkFilm()) {
		if (cnt < minVal) {
			minVal = cnt;
		}
		return;
	}

	if (cnt >= k) {
		return;
	}

	

	for (int i = pos; i < d; i++) {
		for (int j = 0; j < w; j++) {
			cpFlArr[i][j] = 0;	//A약 투여
		}
		solution(cnt + 1, i + 1);
		for (int j = 0; j < w; j++) {
			cpFlArr[i][j] = 1;	//B약 투여
		}
		solution(cnt + 1, i + 1);
		for (int j = 0; j < w; j++) {
			cpFlArr[i][j] = flArr[i][j];	//원상태
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> d >> w >> k;

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> flArr[i][j];
				cpFlArr[i][j] = flArr[i][j];
			}
		}

		solution(0, 0);

		cout << '#' << t << ' ' << minVal << '\n';
		minVal = 987987987;
	}

	return 0;
}