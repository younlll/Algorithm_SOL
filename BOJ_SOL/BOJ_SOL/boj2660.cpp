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

	int arr[51][51];
	fill(&arr[0][0], &arr[N][N], INF);	//��� ���� �ִ밪���� �ʱ�ȭ

	for (int i = 1; i <= N; i++) {
		arr[i][i] = 0;	//�ڱ��ڽ��� ���谡 �����Ƿ� 0 ����
	}

	int a = 0, b = 0;
	while (1) {
		cin >> a >> b;

		if (a == -1 && b == -1) {	//�� ���� -1�̸� �Է� ����
			break;
		}

		//�Է¹��� a�� b���̴� 1(ģ������) �̴�
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	int minNum = INF;
	vector<int> vc;
	for (int i = 1; i <= N; i++) {
		int maxNum = 0;
		for (int j = 1; j <= N; j++) {
			maxNum = max(maxNum, arr[i][j]);	//i�� j�� ������ �ִ� ã��
		}

		if (minNum > maxNum) {	//�ּҰ����� �ִ밪�� �������
			minNum = maxNum;	//�ּҰ� ��ü
			vc.clear();			//ȸ�屳ü
			vc.push_back(i);
		}
		else if (minNum == maxNum) {	//�ּҰ��� �ִ밪�� ������ ȸ������ ����ȣ�� ���Ϳ� �߰�
			vc.push_back(i);
		}
	}

	cout << minNum << ' ' << vc.size() << '\n';
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << ' ';
	}
}