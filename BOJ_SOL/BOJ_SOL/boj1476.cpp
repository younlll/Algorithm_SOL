#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int E, S, M;
	cin >> E >> S >> M;
	//제한범위 예외처리를 위함
	E--;
	S--;
	M--;

	int year = 0;
	while (1) {
		int tmpE, tmpS, tmpM;
		tmpE = year % 15;
		tmpS = year % 28;
		tmpM = year % 19;
		if (tmpE == E && tmpS == S && tmpM == M) {
			cout << (year + 1) << '\n';
			return 0;
		}
		year++;
	}

	return 0;
}