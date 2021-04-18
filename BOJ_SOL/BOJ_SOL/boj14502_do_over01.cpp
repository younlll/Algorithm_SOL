#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10][10];
int virusArr[10][10];
int answer = 0;
vector<pair<int, int>> virusXY;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int virusCnt = 0;
int wallCnt = 0;

void spreadVirus() {
	queue<pair<int, int>> Queue;
	for (int i = 0; i < virusXY.size(); i++) {	//���� �����ϴ� ���̷��� ����ŭ ť�� ����
		Queue.push(virusXY[i]);
	}
	virusCnt = virusXY.size();
	while (!Queue.empty()) {
		int cx = Queue.front().first;
		int cy = Queue.front().second;
		Queue.pop();
		
		for (int i = 0; i < 4; i++) {
			//���� �̵���ǥ ���ϱ�
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {	//�� ���� �ȿ� ���ԵǴ� ���
				if (virusArr[nx][ny] == 0) {	//�̵������� ��ĭ�� ���
					virusArr[nx][ny] = 2;	//���̷��� Ȯ��
					Queue.push({ nx, ny });	//���� ���̷��� Ȯ���� ���� ť�� �־��ش�
					virusCnt++;
				}
			}
		}
	}
}

void solution(int x, int y, int cnt) {
	if (cnt > 3) {	//���� 3�� ���� ��
		//���̷��� ��Ʈ����

		copy(&arr[0][0], &arr[0][0] + 100, &virusArr[0][0]);	//���̷��� ��Ʈ�� �� ����
		spreadVirus();

		//�������� üũ
		int safetyAreaCnt = (N * M) - wallCnt - virusCnt;
		answer = max(answer, safetyAreaCnt);

		return;
	}


	//�� ��ġ�ϱ�
	for (int i = x; i < N; i++) {
		for (int j = y; j < M; j++) {
			if (arr[i][j] == 0) {	// (i, j)�� 0(��ĭ)�̶��
				arr[i][j] = 1;	//�������
				solution(i, j + 1, cnt + 1);	//cnt+1��° �� ����� ����� ���� ���ϱ� ���� ����� �Լ� ȣ��
				arr[i][j] = 0;	//cnt��° ���� �� �ʱ�ȭ
			}
		}
		y = 0;	//i�࿡�� ����� �ִ� ����� �� ã�Ⱑ ���� i+1���� 0��° ������ Ž���ؾ߹Ƿ� 0���� �ʱ�ȭ
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {	//���̷����� �ִ� ĭ ����
				virusXY.push_back({ i, j });
			}
			else if (arr[i][j] == 1) {
				wallCnt++;
			}
		}
	}
	wallCnt += 3;
	solution(0, 0, 1);

	cout << answer << '\n';

	return 0;
}