#include <iostream>

using namespace std;

int sorted[8];	//정렬 배열은 반드시 전역번수로 선언

void merge(int a[], int m, int mid, int n) {
	int i = m;
	int j = mid + 1;
	int k = m;

	//작은 순서대로 배열에 삽입
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

	//남은 데이터 삽입
	if (i > mid) {	//i가 먼저 끝난경우
		for (int t = j; t <= n; t++) {
			sorted[k++] = a[t];
		}
	}
	else {	//j가 먼저 끝난경우
		for (int t = i; t <= mid; t++) {
			sorted[k++] = a[t];
		}
	}

	//정렬된 배열을 삽입
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	//크기가 1보다 큰 경우
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