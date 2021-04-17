#include <iostream>
using namespace std;

int num = 10;
int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

//start: ���ļ��� ������ 1��° ����
//end: ���ļ��� ������ ������ ����
void quickSort(int* arr, int start, int end) {
	if (start >= end) {	//���Ұ� 1���� ���
		return;
	}

	//pivot �� ����ֱ�
	int key = start; //pivot�� ù��° ����

	int i = start + 1;	//���ʺ��� �ϳ��� ū���� ã�� ���ư����� index
	int j = end;	//�����ʺ��� �ϳ��� �������� ã�� ���ư����� index
	int tmp;

	while (i <= j) {	//���ʿ��� ����ؼ� ������ �������� �ݺ�
		while (arr[i] <= arr[key]) {	//pivot���� ū���� ã�������� ���ʿ��� ���������� ��ĭ�� �̵�
			i++;
		}
		while (arr[j] >= arr[key] && j > start) {	//pivot���� ���� ���� ã�������� �����ʿ��� �������� ��ĭ�� �̵�
			j--;
		}

		if (i > j) {	//������ ������ ��� pivot�� ������ ��ü
			tmp = arr[j];
			arr[j] = arr[key];
			arr[key] = tmp;
		}
		else {	//�������� �ʰ� �������� ū���� ã�����, �� ���� �ڸ� ��ü
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}

	//������ ����
	//pivot�� �������� ���ʰ� ������ ���� ������ ����
	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	quickSort(arr, 0, num - 1);	//index 0���� 9����

	for (int i = 0; i < num; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}