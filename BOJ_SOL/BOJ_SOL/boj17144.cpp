#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int R, C, T, answer = 0;
int map[50][50];
int chkMap[50][50];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
vector<pair<int, int>> gong;
vector<pair<int, int>> mise;

void miseSum() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				answer += map[i][j];
			}
		}
	}
}

void solution() {

	while (T--) {	//T�ʵ��� �ݺ�
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] <= 0) {
					continue;
				}
				int cx = i;
				int cy = j;
				if (map[cx][cy] < 5) {	//�̼����� ���� 5�̸��� ���, ���� �̼������� �����Ƿ� ��� pass
					chkMap[cx][cy] += map[cx][cy];
					continue;
				}

				int spreadCnt = 0;
				int miseDiv = map[cx][cy] / 5;	//���� �̼����� ��
				for (int i = 0; i < 4; i++) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx >= 0 && nx < R && ny >= 0 && ny < C) {	//�ʹ��� �ȿ� �����鼭
						if (map[nx][ny] != -1) {	//�̵��� ĭ
							chkMap[nx][ny] += miseDiv;
							spreadCnt++;
						}
					}
				}
				chkMap[cx][cy] += (map[cx][cy] - (miseDiv * spreadCnt));
			}
		}
		copy(&chkMap[0][0], &chkMap[0][0] + 2500, &map[0][0]);
		fill(&chkMap[0][0], &chkMap[0][0] + 2500, 0);
		map[gong[0].first][gong[0].second] = -1;
		map[gong[1].first][gong[1].second] = -1;

		//����û���� �۵�
		//����
		int gx = gong[0].first - 1;
		int gy = 0;
		while (map[gx][gy - 1] != -1) {
			if (gx - 1 >= 0 && gy == 0) {
				map[gx][gy] = map[gx - 1][gy];
				gx--; 
			}
			else if (gx == 0 && 0 <= gy && gy < C - 1) {
				map[gx][gy] = map[gx][gy + 1];
				gy++;
			}
			else if (0 <= gx && gx < gong[0].first && gy == C - 1) {
				map[gx][gy] = map[gx + 1][gy];
				gx++;
			}
			else if (gx == gong[0].first && 1 < gy && gy < C) {
				map[gx][gy] = map[gx][gy - 1];
				gy--;
			}
			map[gx][gy] = 0;
		}

		//�Ʒ���
		gx = gong[1].first + 1;
		gy = 0;
		while (map[gx][gy - 1] != -1) {
			if (gx + 1 < R && gy == 0) {
				map[gx][gy] = map[gx + 1][gy];
				gx++;
			}
			else if (gx == R - 1 && 0 <= gy && gy < C - 1) {
				map[gx][gy] = map[gx][gy + 1];
				gy++;
			}
			else if (gong[1].first < gx && gx < R && gy == C - 1) {
				map[gx][gy] = map[gx - 1][gy];
				gx--;
			}
			else if (gx == gong[1].first && 1 < gy && gy < C) {
				map[gx][gy] = map[gx][gy - 1];
				gy--;
			}
			map[gx][gy] = 0;
		}
	}

	miseSum();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {	//����û���� ��ġ ����
				gong.push_back({ i, j });
			}
			else if (map[i][j] != 0) {	//�̼����� ��ǥ ����
				mise.push_back({ i, j });
			}
		}
	}

	solution();

	cout << answer << '\n';

	return 0;
}