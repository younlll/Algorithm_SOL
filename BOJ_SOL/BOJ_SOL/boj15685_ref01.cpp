#include <iostream>
#include <vector>

using namespace std;

int N;
int map[101][101];
int answer = 0;
vector<int> dir_info;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int x, y, d, g;
	for (int i = 0; i < N; i++) {
		cin >> y >> x >> d >> g;
		dir_info.clear();

		map[x][y] = 1;	//현재입력 좌표 표시
		x = x + dx[d];	//입력받은 좌표 방향으로 이동
		y = y + dy[d];
		map[x][y] = 1;

		dir_info.push_back(d);
		for (int j = 0; j < g; j++) {
			//드레곤커브 만들기
			/*****************************************************************
			* 0세대 : 0
			* 1세대 : 0 1
			* 2세대 : 0 1 2 1
			* 3세대 : 0 1 2 1 2 3 2 1
			* 위 예시를 보면 알수 있다싶이
			* 이전세대 이후 진행방향은
			* 이전세대 진행방향을 역순으로 읽어가며 +1한 방향을 갖는다
			* 단, 4 방향은 없으므로 0이 된다
			*****************************************************************/
			for (int k = dir_info.size() - 1; k >= 0; k--) {
				int nd = (dir_info[k] + 1) % 4;
				x = x + dx[nd];
				y = y + dy[nd];
				map[x][y] = 1;
				dir_info.push_back(nd);
			}
		}
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1) {
				answer++;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}