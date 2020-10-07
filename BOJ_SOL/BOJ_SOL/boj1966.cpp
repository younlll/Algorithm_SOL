#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	string input; //입력 들어오는 문자
	while (T--) {
		stack<char> frontCh;	//커서 앞 문자
		stack<char> backCh;		//커서 뒷 문자

		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '<') {	//커서 한칸 앞으로 이동
				if (!frontCh.empty()) {	//커서 앞에 문자가 있는 경우
					//커서 앞에 있던 문자를 커서 뒤로 보내기
					backCh.push(frontCh.top());
					frontCh.pop();
				}
			}
			else if (input[i] == '>') {	//커서 한칸 뒤로 보내기
				if (!backCh.empty()) {	//커서 뒤에 문자가 있는 경우
					//커서 뒤 문자를 커서 앞으로 보내기
					frontCh.push(backCh.top());
					backCh.pop();
				}
			}
			else if (input[i] == '-') {	//백스페이스
				if (!frontCh.empty()) {	//커서 앞 문자가 있는 경우
					frontCh.pop();	//커서 앞 문자 삭제
				}
			}
			else {
				frontCh.push(input[i]);	//문자입력
			}
		}

		while (!frontCh.empty()) {	//올바른 출력을 위해 커서 앞 문자들을 커서 뒤로 보냄
			backCh.push(frontCh.top());
			frontCh.pop();
		}

		//출력
		while (!backCh.empty()) {
			cout << backCh.top();
			backCh.pop();
		}
		cout << '\n';
	}

	return 0;
}