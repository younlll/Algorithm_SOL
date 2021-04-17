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

	//i는 정렬할 현재 위치를 말함
	for (int i = 0; i < N; i++) {
		int min = INF;
		int idx = 0;
		for (int j = i; j < N; j++) {	//정렬할 위치부터 정렬할 집합 마지막까지 탐색하며 최솟값을 구한다
			if (min > arr[j]) {
				min = arr[j];
				idx = j;
			}
		}
		//구한 최솟값과 i(정렬할 현재 위치)를 swap한다
		int tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}

	//정답출력
	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
}