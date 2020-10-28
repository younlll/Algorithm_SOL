#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int arr[1002] = { 0, };
	int maxH = 0;
	int maxL = 0;
	int startIdx = 1002, endIdx = -1;
	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;
		arr[L] = H;
		if (maxH < H) {	//최대 높이의 기둥 찾기
			maxH = H;
			maxL = L;
		}

		if (startIdx > L) {	//기둥의 시작위치
			startIdx = L;
		}
		if (endIdx < L) {	//기둥의 마지막 위치
			endIdx = L;
		}
	}

	int answer = maxH;
	for (int i = maxL - 1; i >= startIdx; i--) {	//시작~가장 큰 기둥까지
		int m = *max_element(arr, arr + i);	//현재 위치 ~ 가장 큰 기둥 이전 위치 중 가장 높은 기둥 크기 구하기
		answer = answer + max(arr[i], m);	//현재 기둥 높이와 m중 더 큰 값을 누적
	}
	for (int i = maxL + 1; i <= endIdx; i++) {//가장 큰 기둥 ~ 마지막까지
		int m = *max_element(arr + i, arr + endIdx + 1);
		answer = answer + max(arr[i], m);
	}

	cout << answer << '\n';

	return 0;
}