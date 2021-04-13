//선택정렬 알고리즘
#include <iostream>

#define INF 987987987

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };	// 정렬할 배열
	int min = 0, idx = 0;
	for (int i = 0; i < 10; i++) {
		min = INF;	// 비교할 최솟값 설정

		//정렬할 위치부터 마지막 위치까지 탐색하며 최솟값의 위치를 구함
		for (int j = i; j < 10; j++) {	
			if (min > arr[j]) {
				min = arr[j];	//현재까지 탐색한 위치중 최솟값 저장
				idx = j;		//현재까지 탐색한 위치중 최솟값이 위치한 인덱스 저장
			 }
		}

		//정렬할 위치에 최솟값이 위치하도록 SWAPPING
		int tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}