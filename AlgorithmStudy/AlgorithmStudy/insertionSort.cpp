//삽입정렬 알고리즘
//
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for (int i = 0; i < 9; i++) {
		int j = i;	//정렬할 원소 선택

		//j를 1씩 줄여가며 선택된 원소의 앞 원소들과 비교
		while (arr[j] > arr[j + 1]) {
			int tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
			j--;
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}