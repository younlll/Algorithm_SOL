#include <iostream>
#include <bitset>

using namespace std;

//�޸� ���Ѷ����� ���������� ������ �������°ǰ�...
int num;
bitset<1 << 25> bits;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		cin >> num;

		// ��������
		if (cin.eof() == true) {
			break;
		}

		// test: ��Ʈ����
		// set: ��Ʈ�ѱ�
		// num�� ���� bit���°� false��� true�� �������ְ� ���
		if (!bits.test(num)) {
			bits.set(num);
			cout << num << ' ';
		}
	}

	return 0;
}