// Authored by : youn
// Co-authored by : -
// https://www.acmicpc.net/problem/11328
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[27] = {};
	int N;
	cin >> N;
	
	string str1, str2, result = "Possible";
	for (int i = 0; i < N; i++) {
		cin >> str1 >> str2;
		result = "Possible";
		if (str1.length() != str2.length()) {
			result = "Impossible";
		}
		else {
			sort(str1.begin(), str1.end());
			sort(str2.begin(), str2.end());
			for (int i = 0; i < str1.length(); i++) {
				if (str1[i] != str2[i]) {
					result = "Impossible";
					break;
				}
			}
		}

		cout << result << '\n';
	}

	return 0;
}