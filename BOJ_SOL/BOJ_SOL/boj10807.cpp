// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/10807
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[201] = {};
	int N, tmp, v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr[tmp + 100]++;
	}

	cin >> v;

	cout << arr[v + 100] << '\n';

	return 0;
}