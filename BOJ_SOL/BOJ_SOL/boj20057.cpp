#include <iostream>

#define MAX 500
using namespace std;

int arr[MAX][MAX];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int N;
int answer = 0;

void moveSend(int x, int y, int dir) {
	if (arr[x + dx[dir]][y + dy[dir]] == 0) {
		return;
	}
	//모레뿌리기 시작
	int send;
	int tmpSend;
	int tmpX, tmpY, tmpS;
	if (dir == 0 || dir == 2) {	//좌 or 우로 이동하는 경우
		send = arr[x + dx[dir]][y + dy[dir]];
		tmpSend = send;
		for (int i = 0; i < 2; i++) {	//두번 반복을 통해 뿌려진 모레를 구한다
			// 1%
			tmpX = i == 0 ? x - 1 : x + 1;
			tmpY = y;
			tmpS = (tmpSend * 1) / 100;
			if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
				arr[tmpX][tmpY] += tmpS;
			}
			else {
				answer += tmpS;
			}
			send -= tmpS;

			// 7%
			tmpX = i == 0 ? x - 1 : x + 1;
			tmpY = y + dy[dir];
			tmpS = (tmpSend * 7) / 100;
			if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
				arr[tmpX][tmpY] += tmpS;
			}
			else {
				answer += tmpS;
			}
			send -= tmpS;

			// 2%
			tmpX = i == 0 ? x - 2 : x + 2;
			tmpY = y + dy[dir];
			tmpS = (tmpSend * 2) / 100;
			if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
				arr[tmpX][tmpY] += tmpS;
			}
			else {
				answer += tmpS;
			}
			send -= tmpS;

			// 10%
			tmpX = i == 0 ? x - 1 : x + 1;
			tmpY = y + (dy[dir] * 2);
			tmpS = (tmpSend * 10) / 100;
			if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
				arr[tmpX][tmpY] += tmpS;
			}
			else {
				answer += tmpS;
			}
			send -= tmpS;
		}

		// 5%
		tmpX = x;
		tmpY = y + (dy[dir] * 3);
		tmpS = (tmpSend * 5) / 100;
		if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
			arr[tmpX][tmpY] += tmpS;
		}
		else {
			answer += tmpS;
		}
		send -= tmpS;

		// alpha
		tmpX = x;
		tmpY = y + (dy[dir] * 2);
		if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
			arr[tmpX][tmpY] += send;
		}
		else {
			answer += send;
		}
		arr[x + dx[dir]][y + dy[dir]] = 0;	//이동한 공간의 모레는 0이된다
	}
	else if (dir == 1 || dir == 3) {	//상 or 하로 이동하는 경우
		send = arr[x + dx[dir]][y + dy[dir]];
		tmpSend = send;
		for (int i = 0; i < 2; i++) {	//두번 반복을 통해 뿌려진 모레를 구한다
			// 1%
			tmpX = x;
			tmpY = i == 0 ? y - 1 : y + 1;
			tmpS = (tmpSend * 1) / 100;
			if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
				arr[tmpX][tmpY] += tmpS;
			}
			else {
				answer += tmpS;
			}
			send -= tmpS;

			// 7%
			tmpX = x + dx[dir];
			tmpY = i == 0 ? y - 1 : y + 1;
			tmpS = (tmpSend * 7) / 100;
			if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
				arr[tmpX][tmpY] += tmpS;
			}
			else {
				answer += tmpS;
			}
			send -= tmpS;

			// 2%
			tmpX = x + dx[dir];
			tmpY = i == 0 ? y - 2 : y + 2;
			tmpS = (tmpSend * 2) / 100;
			if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
				arr[tmpX][tmpY] += tmpS;
			}
			else {
				answer += tmpS;
			}
			send -= tmpS;

			// 10%
			tmpX = x + (dx[dir] * 2);
			tmpY = i == 0 ? y - 1 : y + 1;
			tmpS = (tmpSend * 10) / 100;
			if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
				arr[tmpX][tmpY] += tmpS;
			}
			else {
				answer += tmpS;
			}
			send -= tmpS;
		}

		// 5%
		tmpX = x + (dx[dir] * 3);
		tmpY = y;
		tmpS = (tmpSend * 5) / 100;
		if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
			arr[tmpX][tmpY] += tmpS;
		}
		else {
			answer += tmpS;
		}
		send -= tmpS;

		// alpha
		tmpX = x + (dx[dir] * 2);
		tmpY = y;
		if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < N) {
			arr[tmpX][tmpY] += send;
		}
		else {
			answer += send;
		}
		arr[x + dx[dir]][y + dy[dir]] = 0;	//이동한 공간의 모레는 0이된다
	}
	//모레뿌리기 종료
}

void solution() {
	int x = N / 2;
	int y = N / 2;
	int dir = 0;
	int cnt = 1;
	int nx, ny;

	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < cnt; j++) {
				nx = x + dx[dir];
				ny = y + dy[dir];

				moveSend(x, y, dir);

				//현재 위치한 좌표 바꾸기
				x = nx;
				y = ny;
			}

			//이동 방향 변경
			dir++;
			if (dir > 3) {
				dir = 0;
			}
		}

		cnt++;
		if (cnt == N) {
			for (int i = 0; i < cnt; i++) {
				nx = x + dx[dir];
				ny = y + dy[dir];
				moveSend(x, y, dir);
				x = nx;
				y = ny;
			}
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	solution();

	cout << answer << '\n';

	return 0;
}