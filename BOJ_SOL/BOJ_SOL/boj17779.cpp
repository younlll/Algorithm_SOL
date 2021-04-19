#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[21][21];
int voteMap[21][21];
int N, sum = 0, answer = 978987987;
int voteNum[6];

void areaDiv(int x, int y, int d1, int d2) {
	
	if (x < 1 || x >= x + d1 + d2 || x + d1 + d2 > N) {
		return;
	}
	if (y - d1 < 1 || y >= y + d2 || y + d2 > N) {
		return;
	}

	memset(voteMap, 0, sizeof(voteMap));
	memset(voteNum, 0, sizeof(voteNum));

	// 5area
	// line1
	for (int i = 0; i <= d1; i++) {
		int tx = x + i;
		int ty = y - i;
		if (tx > 0 && tx <= N && ty > 0 && ty <= N) {
			voteMap[tx][ty] = 5;
		}
	}
	// line2
	for (int i = 0; i <= d2; i++) {
		int tx = x + i;
		int ty = y + i;
		if (tx > 0 && tx <= N && ty > 0 && ty <= N) {
			voteMap[tx][ty] = 5;
		}
	}
	// line3
	for (int i = 0; i <= d2; i++) {
		int tx = x + d1 + i;
		int ty = y - d1 + i;
		if (tx > 0 && tx <= N && ty > 0 && ty <= N) {
			if (i > 0) {
				int tmp = tx - 1;
				while (voteMap[tmp][ty] != 5) {
					voteMap[tmp--][ty] = 5;	//5영역 채우기
				}
			}
			voteMap[tx][ty] = 5;
		}
	}
	// line4
	for (int i = 0; i <= d1; i++) {
		int tx = x + d2 + i;
		int ty = y + d2 - i;
		if (tx > 0 && tx <= N && ty > 0 && ty <= N) {
			if (i > 0) {
				int tmp = tx - 1;
				while (voteMap[tmp][ty] != 5) {
					voteMap[tmp--][ty] = 5;	//5영역 채우기
				}
			}
			voteMap[tx][ty] = 5;
		}
	}


	// 1area
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (1 <= i && i < x + d1 && 1 <= j && j <= y && voteMap[i][j] != 5) {
				voteMap[i][j] = 1;
				voteNum[1] += map[i][j];
			}
		}
	}
	// 2area
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (1 <= i && i <= x + d2 && y < j && j <= N && voteMap[i][j] != 5) {
				voteMap[i][j] = 2;
				voteNum[2] += map[i][j];
			}
		} 
	}
	// 3area
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (x + d1 <= i && i <= N && 1 <= j && j < y - d1 + d2 && voteMap[i][j] != 5) {
				voteMap[i][j] = 3;
				voteNum[3] += map[i][j];
			}
		}
	}
	// 4area
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (x + d2 < i && i <= N && y - d1 + d2 <= j && j <= N && voteMap[i][j] != 5) {
				voteMap[i][j] = 4;
				voteNum[4] += map[i][j];
			}
		}
	}

	int fiveNum = sum - (voteNum[1] + voteNum[2] + voteNum[3] + voteNum[4]);	//5영역 합을 구하기 -> 전체 - (1~4영역의 합)
	int maxNum = 0, minNum = 987987987;
	voteNum[5] = fiveNum;
	for (int i = 1; i <= 5; i++) {
		maxNum = max(maxNum, voteNum[i]);	//최대투표자
		minNum = min(minNum, voteNum[i]);	//최소투표자
	}
	answer = min(answer, (maxNum - minNum));
}

void solution() {
	//x와 y고르기
	for (int d1 = 1; d1 < N; d1++) {
		for (int d2 = 1; d2 < N; d2++) { 
			for (int x = 1; x <= N; x++) {
				for (int y = 1; y <= N; y++) {
					areaDiv(x, y, d1, d2);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			sum += map[i][j];
		}
	}

	solution();

	cout << answer << '\n';

	return 0;
}