#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct boxXY {	// 토마토 박스의 좌표
	int x;
	int y;
};

int zeroCnt = 0;
int result = 0;
int N, M;
int arr[1000][1000];
vector<boxXY> vc;

//           좌  상  우 하
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void solution() {
	queue<boxXY> Queue;
	boxXY bxy;
	for (int i = 0; i < vc.size(); i++) {	//현재 익은 토마토의 모든 좌표를 큐에 넣는다
		bxy.x = vc[i].x;
		bxy.y = vc[i].y;
		Queue.push(bxy);
	}

	while (!Queue.empty()) {
		int cur_x = Queue.front().x;
		int cur_y = Queue.front().y;
		int num = arr[cur_x][cur_y];
		Queue.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {	//상자의 밖의 영역인 경우 continue
				continue;
			}

			//이동할 자리의 토마토가 익는데 걸린 일수(0이 아닌경우)가
			//현재 위치의 토마토를 통해 익는데 걸린 일수보다 작을 경우 continue
			if (arr[nx][ny] > 1 && arr[nx][ny] <= num + 1) {
				continue;
			}

			if (arr[nx][ny] == -1 || arr[nx][ny] == 1) {	//토마토가 없거나(-1) 초기부터 익은 토마토인경우(1) continue
				continue;
			}

			arr[nx][ny] = num + 1;	//이동한 위치의 토마토가 익는데 걸린 일수 계싼
			zeroCnt--;	//토마토가 익었기 때문에 (안익은 토마토 갯수 - 1)
			bxy.x = nx;
			bxy.y = ny;
			Queue.push(bxy);	//이동한 위치의 토마토 칸을 큐에 넎는다
			if (result < num) {	//지금까지 토마토가 익는데 걸린 최대 일수 체크
				result = num;
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	boxXY bxy;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 0) {	//안익은 토마토의 갯수 체크
				zeroCnt++;
			}

			if (arr[i][j] == 1) {	//익은 토마토의 좌표 저장
				bxy.x = i;
				bxy.y = j;
				vc.push_back(bxy);
			}
		}
	}

	if (zeroCnt == 0) {	//처음 제공된 상자의 모든 토마토가 익은 상태라면 0 출력
		cout << 0 << '\n';
		return 0;
	}

	solution();

	if (zeroCnt == 0) {	//모든 토마토가 익은 경우, 최대 일수 출력
		cout << result << '\n';
	}
	else {	//토마토 일부가 익지 않은 경우, -1 출력
		cout << -1 << '\n';
	}

	return 0;
}