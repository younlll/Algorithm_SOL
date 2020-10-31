#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct boxXY {	// �丶�� �ڽ��� ��ǥ
	int x;
	int y;
};

int zeroCnt = 0;
int result = 0;
int N, M;
int arr[1000][1000];
vector<boxXY> vc;

//           ��  ��  �� ��
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void solution() {
	queue<boxXY> Queue;
	boxXY bxy;
	for (int i = 0; i < vc.size(); i++) {	//���� ���� �丶���� ��� ��ǥ�� ť�� �ִ´�
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

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {	//������ ���� ������ ��� continue
				continue;
			}

			//�̵��� �ڸ��� �丶�䰡 �ʹµ� �ɸ� �ϼ�(0�� �ƴѰ��)��
			//���� ��ġ�� �丶�並 ���� �ʹµ� �ɸ� �ϼ����� ���� ��� continue
			if (arr[nx][ny] > 1 && arr[nx][ny] <= num + 1) {
				continue;
			}

			if (arr[nx][ny] == -1 || arr[nx][ny] == 1) {	//�丶�䰡 ���ų�(-1) �ʱ���� ���� �丶���ΰ��(1) continue
				continue;
			}

			arr[nx][ny] = num + 1;	//�̵��� ��ġ�� �丶�䰡 �ʹµ� �ɸ� �ϼ� ���
			zeroCnt--;	//�丶�䰡 �;��� ������ (������ �丶�� ���� - 1)
			bxy.x = nx;
			bxy.y = ny;
			Queue.push(bxy);	//�̵��� ��ġ�� �丶�� ĭ�� ť�� ���´�
			if (result < num) {	//���ݱ��� �丶�䰡 �ʹµ� �ɸ� �ִ� �ϼ� üũ
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

			if (arr[i][j] == 0) {	//������ �丶���� ���� üũ
				zeroCnt++;
			}

			if (arr[i][j] == 1) {	//���� �丶���� ��ǥ ����
				bxy.x = i;
				bxy.y = j;
				vc.push_back(bxy);
			}
		}
	}

	if (zeroCnt == 0) {	//ó�� ������ ������ ��� �丶�䰡 ���� ���¶�� 0 ���
		cout << 0 << '\n';
		return 0;
	}

	solution();

	if (zeroCnt == 0) {	//��� �丶�䰡 ���� ���, �ִ� �ϼ� ���
		cout << result << '\n';
	}
	else {	//�丶�� �Ϻΰ� ���� ���� ���, -1 ���
		cout << -1 << '\n';
	}

	return 0;
}