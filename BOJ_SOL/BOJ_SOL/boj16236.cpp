#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 20
#define INF 987987987

using namespace std;

struct SHARK_INFO {
	int x;
	int y;
	int s;
	int eat;
};

int N, answer = 0, food = 0;
int map[MAX][MAX];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
SHARK_INFO shark;

void findFish() {
	queue<pair<int, int>> Queue;
	queue<int> Qdist;
	bool chkMap[MAX][MAX];

	int Min = INF;
	int minX = INF, minY = INF;
	Queue.push({ shark.x, shark.y });
	Qdist.push(0);
	chkMap[shark.x][shark.y] = true;

	while (!Queue.empty()) {
		int cx = Queue.front().first;
		int cy = Queue.front().second;
		int cdist = Qdist.front();
		Queue.pop();
		Qdist.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int ndist = cdist + 1;

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				continue;
			}
			if (map[nx][ny] > shark.s) {
				continue;
			}
			if (!chkMap[nx][ny]) {
				if (map[nx][ny] == shark.s || map[nx][ny] == 0) {
					Queue.push({ nx, ny });
					Qdist.push(ndist);
					chkMap[nx][ny] = true;
				}
				else if (map[nx][ny] < shark.s) {
					if (Min > ndist) {
						Min = ndist;
						minX = nx;
						minY = ny;
					}
					else if (Min == ndist) {
						if (minX > nx) {
							minX = nx;
							minY = ny;
						}
						else if (minX == nx) {
							if (minY > ny) {
								minX = nx;
								minY = ny;
							}
						}
					}
				}
			}
		}
	}

	shark.x = minX;
	shark.y = minY;
	answer += Min;
}

void solution() {
	while (1) {
		int cx = shark.x;
		int cy = shark.y;
		findFish();
		
		if (map[shark.x][shark.y] != 9) {	// �̵��� �����ġ�� ��� ��ġ�� �ٸ����(�̵��� �� ���)
			map[cx][cy] = 0;
			map[shark.x][shark.y] = 9;	// �ʿ��� �Ʊ��� ��ġ ����
			shark.eat++;	// �Ʊ�� ���� ����� �� ī����
			food--;
			if (shark.s == shark.eat) {	// �Ʊ��� ũ�⸸ŭ ����⸦ ���� ���
				shark.s++;	//��� ũ�� +1
				shark.eat = 0;	//��������� �ʱ�ȭ
			}			
		}
		else {
			break;
		}

		if (food == 0) {
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
			cin >> map[i][j];
			if(map[i][j] == 9){
				shark = { i, j, 2, 0 };
			}
			else if (map[i][j] > 0) {
				food++;
			}
		}
	}

	if (food == 0) {	// ����Ⱑ ���� ���, 0�ʸ��� ������� ȣ��
		cout << answer << '\n';
	}
	else {
		solution();
		cout << answer << '\n';
	}

	return 0;
}