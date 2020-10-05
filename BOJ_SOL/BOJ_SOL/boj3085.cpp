#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vc;
int n;

int checkCandy() {	//연속되는 사탕 확인하는 함수
	int result = 0;
	int chk = 1;
	for (int i = 0; i < n; i++) {
		chk = 1;
		//행 확인
		for (int j = 1; j < n; j++) {
			if (vc[i][j] != vc[i][j - 1]) {
				chk = 1;
			}
			else {
				chk++;
			}

			if (result < chk) {
				result = chk;
			}
		}

		chk = 1;
		//열 확인
		for (int j = 1; j < n; j++) {
			if(vc[j][i] != vc[j-1][i]){
				chk = 1;
			}
			else {
				chk++;
			}

			if (result < chk) {
				result = chk;
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		vc.push_back(str);
	}

	char tmp;
	int max = 0;
	int tmpCandy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//오른쪽바꾸기
			if (j < n - 1) {
				swap(vc[i][j], vc[i][j + 1]);

				tmpCandy = checkCandy();
				if (max < tmpCandy) {
					max = tmpCandy;
				}

				swap(vc[i][j], vc[i][j + 1]);
			}

			//아래 바꾸기
			if (i < n - 1) {
				swap(vc[i][j], vc[i + 1][j]);

				tmpCandy = checkCandy();
				if (max < tmpCandy) {
					max = tmpCandy;
				}

				swap(vc[i][j], vc[i + 1][j]);
			}
		}
	}

	cout << max << '\n';

	return 0;
}