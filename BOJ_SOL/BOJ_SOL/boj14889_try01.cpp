#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[20][20];
bool visited[20];
int answer = 987897897;
int sumArr[20];



void solution(int cnt, int idx) {
	if (cnt >= N / 2) {
		int startTeam = 0;
		int linkTeam = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[j] && !visited[i]) {
					linkTeam += arr[i][j];
				}
				else if (visited[j] && visited[i]) {
					startTeam += arr[i][j];
				}
			}
		}
		int tmp = abs(startTeam - linkTeam);
		if (tmp < answer) {
			answer = tmp;
		}

		return;
	}

	for (int i = idx; i < N; i++) {
		visited[i] = true;
		solution(cnt + 1, i + 1);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	solution(0, 0);

	cout << answer << '\n';

	return 0;
}