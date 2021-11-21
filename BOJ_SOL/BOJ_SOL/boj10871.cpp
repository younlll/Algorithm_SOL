#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, X;
	cin >> N >> X;

	while (N--) {
		int tmp;
		cin >> tmp;
		if (tmp < X) {
			cout << tmp << ' ';
		}
	}

	return 0;
}