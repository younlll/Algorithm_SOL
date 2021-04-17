#include <iostream>

using namespace std;

int sorted[8];	//���� �迭�� �ݵ�� ���������� ����

void merge(int a[], int m, int mid, int n) {
	int i = m;
	int j = mid + 1;
	int k = m;

	//���� ������� �迭�� ����
	while (i <= mid && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}

	//���� ������ ����
	if (i > mid) {	//i�� ���� �������
		for (int t = j; t <= n; t++) {
			sorted[k++] = a[t];
		}
	}
	else {	//j�� ���� �������
		for (int t = i; t <= mid; t++) {
			sorted[k++] = a[t];
		}
	}

	//���ĵ� �迭�� ����
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	//ũ�Ⱑ 1���� ū ���
	if (m < n) {
		int  mid = (m + n) / 2;
		mergeSort(a, m, mid);
		mergeSort(a, mid + 1, n);
		merge(a, m, mid, n);
	}
}

int main() {
	int arr[8] = { 7, 6, 5, 8, 3, 5, 9, 1 };
	mergeSort(arr, 0, 7);
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << ' ';
	}
}