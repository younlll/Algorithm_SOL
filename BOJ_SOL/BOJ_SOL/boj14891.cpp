#include <iostream>
#include <deque>
using namespace std;

struct tQueue {
	deque<int> dq;
};

tQueue arr[4];

void solution(int idx, int dir, int gijun) {
	int cur_idx = idx;
	int lNum = arr[cur_idx].dq[6];
	int rNum = arr[cur_idx].dq[2];

	if (dir == -1) {
		//이동
		int tmp = arr[cur_idx].dq.front();
		arr[cur_idx].dq.pop_front();
		arr[cur_idx].dq.push_back(tmp);

		//왼쪽 톱니 검사
		if (cur_idx > 0) {
			if (lNum != arr[cur_idx - 1].dq[2] && cur_idx - 1 != gijun) {
				solution(cur_idx - 1, dir * (-1), cur_idx);
			}
		}
		//오른쪽 톱니 검사
		if (cur_idx < 3) {
			if (rNum != arr[cur_idx + 1].dq[6] && cur_idx + 1 != gijun) {
				solution(cur_idx + 1, dir * (-1), cur_idx);
			}
		}
	}
	else if (dir == 1) {
		//이동
		int tmp = arr[cur_idx].dq.back();
		arr[cur_idx].dq.pop_back();
		arr[cur_idx].dq.push_front(tmp);

		//왼쪽 톱니 검사
		if (cur_idx > 0) {
			if (lNum != arr[cur_idx - 1].dq[2] && cur_idx - 1 != gijun) {
				solution(cur_idx - 1, dir * (-1), cur_idx);
			}
		}
		//오른쪽 톱니 검사
		if (cur_idx < 3) {
			if (rNum != arr[cur_idx + 1].dq[6] && cur_idx + 1 != gijun){
				solution( cur_idx + 1, dir * (-1), cur_idx);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++) {
		string stmp;
		cin >> stmp;
		for (int j = 0; j < 8; j++) {
			int tmp = stmp[j] - '0';
			arr[i].dq.push_back(tmp);
		}
	}

	int K;
	cin >> K;
	//2 <-> 6 2 <-> 6 2 <-> 6
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;

		solution(x - 1, y, x - 1);
	}

	int result = 0;
	int score = 1;
	for (int i = 0; i < 4; i++) {
		if (arr[i].dq.front() == 1) {
			result += score;
		}
		score *= 2;
	}

	cout << result << '\n';
}