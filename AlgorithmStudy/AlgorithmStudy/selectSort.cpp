//�������� �˰���
#include <iostream>

#define INF 987987987

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };	// ������ �迭
	int min = 0, idx = 0;
	for (int i = 0; i < 10; i++) {
		min = INF;	// ���� �ּڰ� ����

		//������ ��ġ���� ������ ��ġ���� Ž���ϸ� �ּڰ��� ��ġ�� ����
		for (int j = i; j < 10; j++) {	
			if (min > arr[j]) {
				min = arr[j];	//������� Ž���� ��ġ�� �ּڰ� ����
				idx = j;		//������� Ž���� ��ġ�� �ּڰ��� ��ġ�� �ε��� ����
			 }
		}

		//������ ��ġ�� �ּڰ��� ��ġ�ϵ��� SWAPPING
		int tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}