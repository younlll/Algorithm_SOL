#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str, bomb;
	cin >> str >> bomb;

	vector<char> vc;
	for (char ch : str) {
		vc.push_back(ch);	//문자 넣기

		//넣은 문자가 폭탄의 마지막 문자와 같은 경우
		if (ch == bomb[bomb.size() - 1]) {

			//현재 쌓인 문자열 길이가 폭탄보다 작다면 폭탄이 존재하지 않는 경우이다
			if (vc.size() - bomb.size() < 0) {
				continue;
			}

			bool flag = true;
			int endIdx = vc.size() - 1;
			for (int i = 0; i < bomb.size(); i++) {

				//쌓여있는 문자와 폭탄 문자가 일치하지 않는 경우
				if (vc[endIdx - i] != bomb[bomb.size() - 1 - i]) {
					flag = false;
					break;
				}
			}

			//폭탄이 존재하는 경우 해당 부분 삭제
			if (flag) {
				vc.erase(vc.begin() + endIdx +1 - bomb.size(), vc.end());
			}
		}
	}

	if (vc.size() > 0) {
		for (int i = 0; i < vc.size(); i++) {
			cout << vc[i];
		}
		cout << '\n';
	}
	else {
		cout << "FRULA\n";
	}

	return 0;
}