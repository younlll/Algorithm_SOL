#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int amap[101][101];
int cmap[101][101];
bool chkMap[101][101];
int answer = 0;


void solution(int map[][101]) {
	fill(&chkMap[0][0], &chkMap[0][0] + 10201, false);
	for (int i = 0; i < N; i++) {
		bool rflag = true;
		for (int j = 0; j < N; j++) {
			if (j - 1 >= 0) {	//������ �񱳸� ���� ��ġ
				if (map[i][j] == map[i][j - 1]) {	//���̰� ���� ���
					rflag = true;
				}
				else if (map[i][j-1] - map[i][j] == 1) {	//������� ����
					int tCnt = 0;
					int th = map[i][j];
					for (int k = j; k < N; k++) {
						if (th == map[i][k] && !chkMap[i][k]) {	//���ΰ� ���� ������� ���� �� üũ
							tCnt++;
						}
						else {
							break;
						}
					}
					if (tCnt < L) {	//���� X
						rflag = false;
						break;
					}
					else {
						for (int k = j; k < j + L; k++) {
							chkMap[i][k] = true;
						}
						j = j + L - 1;
					}
				}
				else if (map[i][j] - map[i][j-1] == 1) {	//������� ����
					int tCnt = 0;
					int th = map[i][j - 1];
					for (int k = j - 1; k >= 0; k--) {
						if (th == map[i][k] && !chkMap[i][k]) {
							tCnt++;
						}
						else {
							break;
						}
					}
					if (tCnt < L) {	//���� X
						rflag = false;
						break;
					}
					else {
						for (int k = j - 1; k >= j - L; k--) {
							chkMap[i][k] = true;
						}
					}
				}
				else {
					rflag = false;
					break;
				}
			}
		}

		if (rflag) {
			answer++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> amap[i][j];
			cmap[j][i] = amap[i][j];
		}
	}

	solution(amap);
	solution(cmap);
	cout << answer << '\n';

	return 0;
}