#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct cmp {
	bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	set<pair<string, int>, cmp> vc;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		vc.insert({ tmp, tmp.length() });
	}

	for (auto& p : vc) {
		cout << p.first << '\n';
	}
}