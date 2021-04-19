#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

deque<int> dq[4];
int N;

void solution(int a, int b) {
	int rtArr[4] = { 0, };
	
	rtArr[a - 1] = b;
	//움직일 톱니 기준으로 좌측 검사
	for (int i = a - 1; i > 0; i--) {
		if (dq[i][6] != dq[i - 1][2]) {	//왼쪽 톱니의 회전여부 확인
			rtArr[i - 1] = rtArr[i] * -1;
		}
		else {
			break;
		}
	}

	rtArr[a - 1] = b;
	//움직일 톱니 기준으로 우측 검사
	for (int i = a - 1; i < 3; i++) {
		if (dq[i][2] != dq[i + 1][6]) {	//오른쪽 톱니의 회전여부 확인
			rtArr[i + 1] = rtArr[i] * -1;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (rtArr[i] == 1) {
			dq[i].push_front(dq[i][7]);
			dq[i].pop_back();
		}
		else if (rtArr[i] == -1) {
			dq[i].push_back(dq[i][0]);
			dq[i].pop_front();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			dq[i].push_back(str[j] - '0');
		}
	}
		
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		solution(a, b);
	}

	int answer = 0;
	int gijun = 2;
	for (int i = 0; i < 4; i++) {
		if (dq[i][0] == 0) {
			answer += 0;
		}
		else if (dq[i][0] == 1) {
			answer += pow(gijun, i);
		}
	}

	cout << answer << '\n';

	return 0;
}