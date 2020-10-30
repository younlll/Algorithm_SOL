#include <iostream>
#include <vector>
using namespace std;

int arr[55][55];
int cpArr[55][55];
vector<pair<int, int>> vc;
vector<pair<int, int>> vcCh;

void choice(int cnt, int k, int start, int m) {
	if (cnt == k) {
		cout << '\n';
		for (int i = 0; i < vcCh.size(); i++) {
			cout << vcCh[i].first << ',' << vcCh[i].second << '\n';
		}
		return;
	}

	for (int i = start; i < m; i++) {
		vcCh.push_back(make_pair(vc[i].first, vc[i].second));
		choice(cnt + 1, k, start + 1, m);
		vcCh.erase(vcCh.begin()+(vcCh.size()-1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				vc.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		choice(0, i, 0, m);
	}
}