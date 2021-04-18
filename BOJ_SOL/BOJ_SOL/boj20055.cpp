#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	deque<pair<int, bool>> dq1;
	deque<pair<int, bool>> dq2;

	cin >> N >> K;

	int cnt = 0;
	int answer = 0;

	for (int i = 0; i < 2 * N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			cnt++;
		}
		if (i < N) {
			dq1.push_back({ tmp, false });
		}
		else {
			dq2.push_front({ tmp, false });
		}
	}

	while (cnt < K) {	//������ 0�� ������ K�̸��� ��쵿�� �ݺ�
		//�����̾Ʈ ��ĭ�� �̵�
		pair<int, bool> downInfo = dq1.back();	//������ ĭ ���� ����
		pair<int, bool> upInfo = dq2.front();	//�ö� ĭ ���� ����
		downInfo.second = false;	//�κ� �����ֱ�
		if (downInfo.second) {

		}
		dq1.pop_back();	//���ٿ��� ������ ĭ pop
		dq2.pop_front(); //�Ʒ��ٿ��� �ö� ĭ pop
		dq1.push_front(upInfo);
		dq2.push_back(downInfo);

		//��Ʈ�� �κ� �̵���Ű��
		for (int i = N - 1; i >= 0; i--) {
			if (i + 1 >= N) {	//�κ��� ��ĭ �̵��� ���� �������� ���� ���
				dq1[i].second = false;
			}else if (dq1[i].second && dq1[i + 1].first >= 1) {	//���� ��ġ�� �κ��� �����鼭 �̵��� ĭ�� �������� 1�̻��� ���
				if (!dq1[i + 1].second) {	//�̵��� ĭ�� ��ĭ�� ���
					dq1[i].second = false;
					dq1[i + 1].second = true;	//�κ� ���� ǥ��
					dq1[i + 1].first -= 1;	//������ 1 ����
					if (dq1[i + 1].first == 0) {	//������ �������� 0���� �˻�
						cnt++;
					}
				}
			}
		}

		//�ö󰡴� ��ġ�� �κ��� ������ �������� 1�̻��� ���
		//�κ� �ø���
		if (dq1[0].first >= 1 && !dq1[0].second) {
			dq1[0].first -= 1;	//������ 1����
			dq1[0].second = true;
			if (dq1[0].first == 0) {	//������ �������� 0���� �˻�
				cnt++;
			}
		}

		answer++;
	}

	cout << answer << '\n';

	return 0;
}