#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987987897

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int arr[101][101];
	fill(&arr[0][0], &arr[N][N], INF);	//��ü �迭�� INF�� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp != 0) {	// i->j�� ����� ��츸 ������ �Է�
				arr[i][j] = tmp;
			}
		}
	}

	//i->j / i->k->j �� ��츦 �񱳿� j�� ������ �ִܰŸ� ���ϱ�
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] < INF) {	//INF���� ������ i->j�� ���� ��찡 �����Ƿ� 1���
				cout << "1 ";
			}
			else {	//INF���� ũ�ٸ� i->j�� ���� ��찡 �����Ƿ� 0���
				cout << "0 ";
			}
		}
		cout << '\n';
	}

}