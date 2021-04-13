//버블정렬 알고리즘
//시간복잡도 O(n) = N * (N + 1) / 2 = O(N^2) -> 선택정렬과 동일한 시간복잡도를 갖는다
//하지만 선택정렬보다 버블정렬이 속도가 느리다
//(매번 옆 숫자와 비교하고 조건에 맞는경우 매번 교체하며 연산이 수행되므로 실질적으로 가장 느린 정렬 알고리즘이다)
//정렬알고리즘 중에서 가장 비효율적이다
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (int i = 0; i < 10; i++) {	//정렬할 배열 크기만큼 반복하며
		for (int j = 0; j < 9 - i; j++) {	//정렬 탐색범위는 1회 반복마다 가장 뒤에서부터 한자리씩 줄어든다
			if (arr[j] > arr[j + 1]) {	//현재 탐색하는 숫자보다 뒤에 있는 숫자가 작은 경우 swap
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}