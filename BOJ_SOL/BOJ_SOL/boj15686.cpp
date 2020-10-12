#include <iostream>
#include <vector>
using namespace std;

int arr[55][55];
int cpArr[55][55];
vector<pair<int, int>> vc;

void solution(int x, int y) {

}

void funcA(int cnt, int m, int n, int start) {
	if (cnt >= m) {
		return;
	}

	for (int i = start; i < n; i++) {

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
			vc.push_back(pair<int, int>(i, j));
		}
	}
}