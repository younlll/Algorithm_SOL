#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, H;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> H;
	vector<int> bottom(N / 2), top(N / 2);	//������ �������� ������ �����Ƿ� ����N�� /2��ŭ�� ����
	for (int i = 0; i < N / 2; i++) {
		cin >> bottom[i] >> top[i];	//������ ������ ���� �Է�
	}

	//������ ������ ���� �������� ����
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int minVal = 987897897;
	int answer = 1;
	for (int i = 1; i <= H; i++) {

		//����i���� ��ġ�� ������ ����
		int cnt = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		
		//����i���� ��ġ�� �������� ����
		cnt += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		if (minVal == cnt) {	//�ּڰ��� ����i�� ������ ������ �������� ������ ���ٸ� ī��Ʈ +1
			answer++;
		}
		else if (minVal > cnt) {	//�ּڰ��� ����i�� ������ ������ �������� ������ �ٸ����
			minVal = cnt;	//�ּҰ� ����
			answer = 1;		//ī��Ʈ 1�� �ʱ�ȭ
		}
	}

	cout << minVal << ' ' << answer << '\n';

	return 0;
}