#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int N, M, gas;
int arr[20][20];

struct taxiInfo {
	int x;
	int y;
	int oil;
};

map<pair<int, int>, pair<int, int>> custInfo;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int start_taxi_x, start_taxi_y;

bool operator <(taxiInfo a, taxiInfo b) {
	if (a.oil < b.oil) {
		return true;
	}

	if (a.oil == b.oil) {
		if (a.y > b.y) {
			return true;
		}
		if (a.y == b.y) {
			if (a.x > b.x) {
				return true;
			}
		}
	}
	return false;
}

bool solution(int sx, int sy) {
	queue<pair<taxiInfo, int>> qu2;
	qu2.push({ { sx, sy, gas }, 0 });
	bool visited[20][20];
	memset(visited, false, sizeof(visited));
	
	visited[qu2.front().first.x][qu2.front().first.y] = true;
	int cnt = 0;

	//cout << "2)start_x: " << start_taxi_x << " strt_y: " << start_taxi_y << '\n';

	while (!qu2.empty()) {
		int cx = qu2.front().first.x;
		int cy = qu2.front().first.y;
		int coil = qu2.front().first.oil;
		int ccnt = qu2.front().second;
		qu2.pop();

		if (coil < 0) {
			return false;
		}
		if (cx == custInfo[{sx, sy}].first&& cy == custInfo[{sx, sy}].second) {
			gas = coil + (ccnt * 2);
			start_taxi_x = cx;
			start_taxi_y = cy;
			//custInfo.erase({ sx, sy });
			custInfo[{sx, sy}] = { -1, -1 };
			/*if (custInfo.count({ cx, cy }) == 1 && custInfo[{cx, cy}].first != -1) {
				
			}
			else {
				custInfo[{sx, sy}] = { -1, -1 };
			}*/
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				continue;
			}
			if (visited[nx][ny] || arr[nx][ny] == 1) {
				continue;
			}

			visited[nx][ny] = true;
			qu2.push({ {nx, ny, coil - 1}, ccnt + 1 });
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> gas;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	
	cin >> start_taxi_x >> start_taxi_y;
	start_taxi_x--;
	start_taxi_y--;
	taxiInfo ti;
	
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		custInfo[{x1 - 1, y1 - 1}] = { x2 - 1, y2 - 1 };
	}

	while(1){
		priority_queue<taxiInfo> qu1;
		qu1.push({ start_taxi_x, start_taxi_y, gas });
		bool visited[20][20];
		memset(visited, false, sizeof(visited));

		bool flag = false;

		//cout << "1)start_x: " << start_taxi_x << " strt_y: " << start_taxi_y << '\n';

		while (!qu1.empty()) {
			int cx = qu1.top().x;
			int cy = qu1.top().y;
			int coil = qu1.top().oil;
			qu1.pop();

			if (coil < 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (custInfo.count({ cx, cy }) == 1 && custInfo[{cx, cy}].second != -1) {
				start_taxi_x = cx;
				start_taxi_y = cy;
				gas = coil;
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
					continue;
				}
				if (visited[nx][ny] || arr[nx][ny] == 1) {
					continue;
				}
				
				visited[nx][ny] = true;
				qu1.push({ nx, ny, coil - 1 });
			}
		}
		
		if (!flag) {
			cout << -1 << '\n';
			return 0;
		}

		if (solution(start_taxi_x, start_taxi_y) == false) {
			cout << -1 << '\n';
			return 0;
		}

		if (--M == 0) {
			cout << gas << '\n';
			return 0;
		}

		
		//cout << "4)start_x: " << start_taxi_x << " strt_y: " << start_taxi_y << '\n';
	}
}