#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int hArr[9];	//������ 9�� Ű�� ���� �迭
	int totHeight = 0;	//������ Ű ����

	for (int i = 0; i < 9; i++) {
		cin >> hArr[i];
		totHeight += hArr[i];
	}

	sort(hArr, hArr + 9);	//�������� ����� ���� ����

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			//�θ��� Ű�� ���� ���� ������ 100�� ���
			if ((totHeight - hArr[i] - hArr[j]) == 100) {
				for (int k = 0; k < 9; k++) {
					//�θ��� ������ �ٸ� ������ Ű ���
					if (k == i || k == j) {
						continue;
					}
					cout << hArr[k] << '\n';
				}
				i = j = 9;	//���� ������ ��µǴ� ���� �����ϱ� ����
				break;
			}
		}
	}

	return 0;
}