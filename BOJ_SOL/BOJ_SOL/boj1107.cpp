#include <iostream>
using namespace std;

bool breakArr[10];

int  checkChannel(int tmpCh) {
	if (tmpCh == 0) {
		if (breakArr[0]) {
			return 0;
		}
		return 1;
	}

	int len = 0;
	while (tmpCh > 0) {
		if (breakArr[tmpCh % 10]) {
			return 0;
		}
		len++;
		tmpCh /= 10;
	}

	return len;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int wantCh;
	int breakCnt;

	cin >> wantCh >> breakCnt;
	int tmp = 0;
	for (int i = 0; i < breakCnt; i++) {
		cin >> tmp;
		breakArr[tmp] = true;
	}

	if (wantCh == 100) {
		cout << 0 << '\n';
		return 0;
	}

	int min = abs(wantCh - 100);
	for (int i = 0; i < 1000000; i++) {
		int tmpCh = i;
		int len = checkChannel(tmpCh);
		if (len > 0) {
			int gap = abs(wantCh - tmpCh);
			if (min > len + gap) {
				min = len + gap;
			}
		}
	}

	cout << min << '\n';

	return 0;
}