#include <iostream>
using namespace std;

int num = 10;
int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

//start: 정렬수행 집합의 1번째 원소
//end: 정렬수행 집합의 마지막 원소
void quickSort(int* arr, int start, int end) {
	if (start >= end) {	//원소가 1개인 경우
		return;
	}

	//pivot 값 잡아주기
	int key = start; //pivot은 첫번째 원소

	int i = start + 1;	//왼쪽부터 하나씩 큰값을 찾아 나아갈때의 index
	int j = end;	//오른쪽부터 하나씩 작은값을 찾아 나아갈때의 index
	int tmp;

	while (i <= j) {	//양쪽에서 출발해서 엇갈릴 때까지만 반복
		while (arr[i] <= arr[key]) {	//pivot보다 큰값을 찾을때까지 왼쪽에서 오른쪽으로 한칸씩 이동
			i++;
		}
		while (arr[j] >= arr[key] && j > start) {	//pivot보다 작은 값을 찾을때까지 오른쪽에서 왼쪽으로 한칸씩 이동
			j--;
		}

		if (i > j) {	//엇갈린 상태의 경우 pivot과 작은값 교체
			tmp = arr[j];
			arr[j] = arr[key];
			arr[key] = tmp;
		}
		else {	//엇갈리지 않고 작은값과 큰값을 찾은경우, 두 수의 자리 교체
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}

	//엇갈린 이후
	//pivot을 기준으로 왼쪽과 오른쪽 집합 퀵정렬 수행
	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	quickSort(arr, 0, num - 1);	//index 0부터 9까지

	for (int i = 0; i < num; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}