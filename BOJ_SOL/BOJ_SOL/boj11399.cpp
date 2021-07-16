#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;	// ��� ��

	vector<int> vc;	// ����ð��� ���� ��

	// 0���� N(�����) ��ŭ �ݺ��Ͽ� ����ð� �Է�
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vc.push_back(tmp);
	}

	sort(vc.begin(), vc.end());

	int answer = 0;
	int tmpSum = 0;
	for (int i = 0; i < N; i++) {
		tmpSum += vc[i];
		answer += tmpSum;
	}

	cout << answer << '\n';

	return 0;
}