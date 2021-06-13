#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> arc;
vector<int> mTap;
int answer = 0;

int main() {
	cin >> N >> M;

	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		arc.push_back(tmp);
	}

	vector<int>::iterator iter;
	for (int i = 0; i < M; i++) {
		iter = find(mTap.begin(), mTap.end(), arc[i]);

		//��Ƽ�ǿ� ���� ������ �ִ� ���
		if (mTap.size() < N) {
			// ���� ��Ƽ�ǿ� �������� �ʴ� ���
			if (iter == mTap.end()) {
				mTap.push_back(arc[i]);
			}
			continue;
		}
		
		//��Ƽ�ǿ� ���� ������ ���� ���
		if (mTap.size() >= N) {
			// ���� ��Ƽ�ǿ� �������� �ʴ� ���
			if (iter == mTap.end()) {
				int idx = 0, num = 0;
				// �ڿ� ������ ���� ���ڱ���̰ų� ���� ���߿� ���̴� ���ڱ�⸦ �̴´�
				for (int j = 0; j < N; j++) {
					int cnt = 0;
					for (int k = i + 1; k < M; k++) {
						if (arc[k] == mTap[j]) {
							break;
						}
						cnt++;
					}
					if (cnt > idx) {
						num = j;
						idx = cnt;
					}
				}
				answer++;
				mTap[num] = arc[i];
			}
		}
	}
	cout << answer << '\n';
}