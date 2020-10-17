#include <iostream>
#include <deque>
using namespace std;

int N, M;
int x, y, K;
int arr[20][20];

deque<int> col_q;
deque<int> row_q;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void init() {
	for (int i = 0; i < 4; i++) {
		col_q.push_back(0);
	}
	for (int i = 0; i < 2; i++) {
		row_q.push_back(0);
	}
}

void solution(int next_x, int next_y, int move) {
	
	if (move == 4) {	//�����̵��̰ų� ������ ���
		//�ֻ��� �̵����
		col_q.push_front(col_q.back());
		col_q.pop_back();
	}
	else if (move == 3) {
		//�ֻ��� �̵����
		col_q.push_back(col_q.front());
		col_q.pop_front();
	}
	else if (move == 2) {	//������ ���
		for (int i = 1; i <= 2; i++) {
			col_q.push_back(col_q.front());
			col_q.pop_front();
			col_q.push_back(row_q.back());
			row_q.pop_back();
			if (i == 1) {
				row_q.push_front(col_q.front());
				col_q.pop_front();
			}
			else if (i == 2) {
				row_q.push_back(col_q.front());
				col_q.pop_front();
			}
			
		}
	}
	else if (move == 1) {	//������ ���
		for (int i = 1; i <= 2; i++) {
			col_q.push_back(col_q.front());
			col_q.pop_front();
			col_q.push_back(row_q.front());
			row_q.pop_front();
			if (i == 1) {
				row_q.push_back(col_q.front());
				col_q.pop_front();
			}
			else if (i == 2) {
				row_q.push_front(col_q.front());
				col_q.pop_front();
			}
		}
	}

	if (arr[next_x][next_y] == 0) {	//���� ���� 0�ΰ��
		arr[next_x][next_y] = col_q[3];	//�ֻ��� ���� �ʿ� �ű�
	}
	else {	//���� ���� 0�� �ƴѰ��
		col_q[3] = arr[next_x][next_y];	//�ֻ��� �ٴڿ� ���� ���� �ű�
		arr[next_x][next_y] = 0;	//�� 0���� ����
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	init();

	int move;
	for (int i = 0; i < K; i++) {
		cin >> move;
		
		int next_x = x + dx[move - 1];
		int next_y = y + dy[move - 1];

		//�ٱ����� ������ ����� ��� ����
		if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) {
			continue;
		}

		solution(next_x, next_y, move);
		x = next_x;
		y = next_y;
		cout << col_q[1] << '\n';
	}
}