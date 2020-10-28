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
		if (maxH < H) {	//�ִ� ������ ��� ã��
			maxH = H;
			maxL = L;
		}

		if (startIdx > L) {	//����� ������ġ
			startIdx = L;
		}
		if (endIdx < L) {	//����� ������ ��ġ
			endIdx = L;
		}
	}

	int answer = maxH;
	for (int i = maxL - 1; i >= startIdx; i--) {	//����~���� ū ��ձ���
		int m = *max_element(arr, arr + i);	//���� ��ġ ~ ���� ū ��� ���� ��ġ �� ���� ���� ��� ũ�� ���ϱ�
		answer = answer + max(arr[i], m);	//���� ��� ���̿� m�� �� ū ���� ����
	}
	for (int i = maxL + 1; i <= endIdx; i++) {//���� ū ��� ~ ����������
		int m = *max_element(arr + i, arr + endIdx + 1);
		answer = answer + max(arr[i], m);
	}

	cout << answer << '\n';

	return 0;
}