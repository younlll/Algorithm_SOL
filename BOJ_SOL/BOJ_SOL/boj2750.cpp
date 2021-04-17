#include <iostream>

#define INF 987987987
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int arr[1001];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//i�� ������ ���� ��ġ�� ����
	for (int i = 0; i < N; i++) {
		int min = INF;
		int idx = 0;
		for (int j = i; j < N; j++) {	//������ ��ġ���� ������ ���� ���������� Ž���ϸ� �ּڰ��� ���Ѵ�
			if (min > arr[j]) {
				min = arr[j];
				idx = j;
			}
		}
		//���� �ּڰ��� i(������ ���� ��ġ)�� swap�Ѵ�
		int tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}

	//�������
	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
}