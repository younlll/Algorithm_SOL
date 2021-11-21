#include <iostream>
#include <vector>

using namespace std;

string answer[3];
vector<int> vc[26];

// 전위 순회
void solution_pre(int idx) {
	if (idx == -1) {	// 연결된 자식 노드가 없는 경우(루트가 -1로 들어온 경우)
		return;
	}

	answer[0] += (char(idx + 65));	// 루트 노드를 추가
	solution_pre(vc[idx][0]);	// 왼쪽 자식노드
	solution_pre(vc[idx][1]);	// 오른쪽 자식노드
}

// 중위 순회
void solution_ind(int idx) {
	if (idx == -1) {	// 더 이상 탐색할 노드가 없는 경우
		return;
	}

	solution_ind(vc[idx][0]);	// 왼쪽 자식노드 탐색
	
	//왼쪽 자식노드의 탐색이 끝난 경우
	answer[1] += (char(idx + 65));
	solution_ind(vc[idx][1]);	// 오른쪽 자식노드 탐색
}

// 후위 순회
void solution_post(int idx) {
	if (idx == -1) {	// 더 이상 탐색할 노드가 없는 경우
		return;
	}

	solution_post(vc[idx][0]);	// 왼쪽 자식 노드 탐색
	solution_post(vc[idx][1]);	// 오른쪽 자식 노드 탐색
	answer[2] += (char(idx + 65));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;	// 노드의 개수

	char ch1, ch2, ch3;
	for (int i = 0; i < N; i++) {
		cin >> ch1 >> ch2 >> ch3;

		if (ch2 != '.') {
			vc[ch1 - 65].push_back(ch2 - 65);
		}
		else {
			vc[ch1 - 65].push_back(-1);
		}
		if (ch3 != '.') {
			vc[ch1 - 65].push_back(ch3 - 65);
		}
		else {
			vc[ch1 - 65].push_back(-1);
		}
	}

	solution_pre(0);
	solution_ind(0);
	solution_post(0);

	for (int i = 0; i < 3; i++) {
		cout << answer[i] << '\n';
	}
}