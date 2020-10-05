#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool chkNum[10];
vector<char> chVc;
string MIN = "9879879879";
string MAX = "0";

void solution(int cnt, int k, string result) {
	if (cnt > k) {
		if (MIN > result) {
			MIN = result;
		}
		if (MAX < result) {
			MAX = result;
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		//���� ��� ���� üũ
		if (!chkNum[i]) {
			if (cnt == 0) {	//ù��° �ڸ��� ���, �ε�ȣ �� ���� �־���
				result += (i + '0');
				chkNum[i] = true;	//���
				solution(cnt + 1, k, result);
				chkNum[i] = false;	//��� ����
				result.erase(result.size() - 1);	//������ �ڸ��� �ٸ� ���� ��ü�ϱ� ���� ����
			}
			else {
				int len = result.size();
				int tmp = result[len - 1] - '0';
				if (chVc[cnt-1] == '>') {
					if (tmp > i) {
						result += (i + '0');
						chkNum[i] = true;
						solution(cnt+1, k, result);
						chkNum[i] = false;
						result.erase(result.size() - 1);
					}
				}
				else if (chVc[cnt-1] == '<') {
					if (tmp < i) {
						result += (i + '0');
						chkNum[i] = true;
						solution(cnt + 1, k, result);
						chkNum[i] = false;
						result.erase(result.size() - 1);
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	char tmp;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		chVc.push_back(tmp);
	}
	solution(0, k, "");
	
	cout << MAX << '\n';
	cout << MIN << '\n';

	return 0;
}