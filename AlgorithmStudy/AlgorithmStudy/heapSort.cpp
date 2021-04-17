#include <iostream>

using namespace std;

int number = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main() {
	//먼저 전체 트리 구조를 최대 힙 구조로 바꾼다
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;	//부모노드
			if (heap[root] < heap[c]) {	//부모노드 값보다 현재노드 값이 더 큰경우 교체
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			c = root;
		} while (c != 0);
	}

	//크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--) {
		//가장 큰 값을 마지막으로 보내 오름차순 구성
		int tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;

		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;	//부모의 자식

			//자식중에 더 큰 값을 찾기
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c += 1;
			}

			//부모보다 자식이 더 크다면 교환
			if (heap[root] < heap[c] && c < i) {
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			root = c;
		} while (c < i);
;	}

	for (int i = 0; i < number; i++) {
		cout << heap[i] << ' ';
	}
}