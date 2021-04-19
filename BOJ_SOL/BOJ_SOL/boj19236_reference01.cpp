#include <iostream>
#include <algorithm>

using namespace std;

struct Fish {
	int x, y, dir;
	bool live;
};

int answer;
int arr[4][4];
Fish fish[20];

//			    ��  ��  �� �� �� ��  �� ��
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void solution(int shX, int shY, int shDir, int sum) {
	
	answer = max(answer, sum);

	int copyArr[4][4];
	Fish copyFish[20];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copyArr[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		copyFish[i] = fish[i];
	}

	//����� �̵��ϱ�
	for (int i = 1; i <= 16; i++) {
		if (!fish[i].live) {
			continue;
		}

		//������ ����� ����
		int cx = fish[i].x;
		int cy = fish[i].y;
		int cd = fish[i].dir;
		
		//�̵��� ��ġ�� ����
		for (int j = 0; j < 8; j++) {
			//������ ���� ���ϱ�
			int tmpDir = cd + j;
			if (tmpDir > 8) {
				tmpDir -= 8;
			}

			//������ ��ġ ���ϱ�
			int nx = cx + dx[tmpDir];
			int ny = cy + dy[tmpDir];
			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {	//�� ������ ���ԵǴ� ���
				if (arr[nx][ny] == 0) {	//����Ⱑ ���� ���
					fish[i].x = nx;
					fish[i].y = ny;
					fish[i].dir = tmpDir;
					arr[nx][ny] = i;
					arr[cx][cy] = 0;
					break;
				}
				else if (arr[nx][ny] != -1) {	//����Ⱑ �����鼭 �� �ƴ� ���
					fish[i].dir = tmpDir;	//��ȭ�� ���� ����

					//����� swap
					Fish tmpFish = fish[i];
					fish[i].x = fish[arr[nx][ny]].x;
					fish[i].y = fish[arr[nx][ny]].y;
					fish[arr[nx][ny]].x = tmpFish.x;
					fish[arr[nx][ny]].y = tmpFish.y;

					int tmp = arr[cx][cy];
					arr[cx][cy] = arr[nx][ny];
					arr[nx][ny] = tmp;
					break;
				}
			}
		}
		
	}

	//�� ����� ����ŭ �̵���Ű��
	for (int i = 1; i <= 3; i++) {
		int n_shX = shX + (dx[shDir] * i);
		int n_shY = shY + (dy[shDir] * i);
		if (n_shX >= 0 && n_shX < 4 && n_shY >= 0 && n_shY < 4) {
			if (arr[n_shX][n_shY] == 0) {	//����Ⱑ ���� ��� �̵�X
				continue;
			} 
			
			int tmpNum = arr[n_shX][n_shY]; // 12
			arr[shX][shY] = 0;	//(0, 0) 0
			arr[n_shX][n_shY] = -1;	//(1, 1) -1
			fish[tmpNum].live = false;
			int n_shDir = fish[tmpNum].dir;	// 12�� �Ÿ� 2
			solution(n_shX, n_shY, n_shDir, sum + tmpNum);
			arr[shX][shY] = -1;
			arr[n_shX][n_shY] = tmpNum;
			fish[arr[n_shX][n_shY]].live = true;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = copyArr[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		fish[i] = copyFish[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// ����� �� ���� �Է�
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			arr[i][j] = a;
			fish[a] = { i, j, b, true };
		}
	}

	//(0,0)����� ���� ��Ƹ���
	int tmp = arr[0][0];
	fish[arr[0][0]].live = false;
	arr[0][0] = -1;
	solution(0, 0, fish[tmp].dir, tmp);

	cout << answer << '\n';
}