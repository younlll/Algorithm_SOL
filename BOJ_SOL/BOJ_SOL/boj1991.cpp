#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	vector<pair<int, int>> vc[26];

	cin >> N;	// 노드의 개수

	char ch1, ch2, ch3;
	for (int i = 0; i < N; i++) {
		cin >> ch1 >> ch2 >> ch3;
		vc[ch1 - 65].push_back({ ch2 - 65, ch3 - 65 });
	}
}