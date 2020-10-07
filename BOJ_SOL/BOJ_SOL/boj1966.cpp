#include <iostream>
#include <queue>
using namespace std;

bool cmp(int n1, int n2) {
	return n1 > n2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	int n, m;
	while (T--) {
		int result = 0;
		cin >> n >> m;
		
		queue<int> idxQ;		//문서의 처음 위치를 저장
		queue<int> printQ;		//문서 우선순위를 저장
		priority_queue<int> pq;		//문서 중요도 내림차순 정렬
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			printQ.push(tmp);
			pq.push(tmp);
			idxQ.push(i);
		}

		//큐에 데이터가 있는 동안 반복
		while (!printQ.empty()) {

			if (pq.top() == printQ.front()) {	//현재 우선순위와 프린트 우선순위가 같은 경우

				int idx = idxQ.front();	//문서 초기 위치

				//출력
				idxQ.pop();
				printQ.pop();
				pq.pop();
				result++;	//몇번째 출력인지 체크

				if (idx == m) {	//출력한 문서 위치와 궁금한 문서 위차가 같은 경우 종료
					break;
				}
			}
			else {	//현재 우선순위와 프린트 우선순위가 다른 경우

				//프린트 큐 가장 마직막으로 옮김
				idxQ.push(idxQ.front());
				printQ.push(printQ.front());
				idxQ.pop();
				printQ.pop();
			}
		}
		
		cout << result << '\n';
	}

	return 0;
}