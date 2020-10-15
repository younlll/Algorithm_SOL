#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct rMapAttr {
	int attr[4] = { 0, };
};
struct cMapAttr {
	int attr[4] = { 0, };
};

int N;
vector<rMapAttr> rVc;
vector<cMapAttr> cVc;

void blockStack(int t, int x, int y) {
	rMapAttr rMa;
	cMapAttr cMa;
	
	if (t == 1) {
		bool flag = false;
		for (int i = 0; i < rVc.size(); i++) {
			if (rVc[i].attr[y] == 0) {
				rVc[i].attr[y] = t;
				flag = true;
				break;
			}
		}
		if (!flag) {
			rMa.attr[y] = t;
			rVc.push_back(rMa);
		}
		
		flag = false;
		for (int i = 0; i < cVc.size(); i++) {
			if (cVc[i].attr[3 - y] == 0) {
				cVc[i].attr[3 - y] = t;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cMa.attr[3 - y] = t;
			cVc.push_back(cMa);
		}
	}
	else if (t == 2) {
		bool flag = false;
		for (int i = 0; i < rVc.size(); i++) {
			if (rVc[i].attr[y] == 0 && rVc[i].attr[y + 1] == 0) {
				rVc[i].attr[y] = t;
				rVc[i].attr[y + 1] = t;
				flag = true;
				break;
			}
		}
		if (!flag) {
			rMa.attr[y] = t;
			rMa.attr[y + 1] = t;
			rVc.push_back(rMa);
		}

		flag = false;
		for (int i = 1; i < cVc.size(); i++) {
			if (cVc[i].attr[3 - x] == 0 && cVc[i - 1].attr[3 - x] == 0) {
				cVc[i].attr[3 - x] = t;
				cVc[i - 1].attr[3 - x] = t;
				flag = true;
				break;
			}
		}
		if (!flag) {
			for (int i = 0; i < 2; i++) {
				cMa.attr[3 - x] = t;
				cVc.push_back(cMa);
			}
		}
	}
	else if (t == 3) {
		bool flag = false;
		for (int i = 1; i < rVc.size(); i++) {
			if (rVc[i].attr[y] == 0 && rVc[i - 1].attr[y] == 0) {
				rVc[i].attr[y] = t;
				rVc[i - 1].attr[y] = t;
				flag = true;
				break;
			}
		}
		if (!flag) {
			for (int i = 0; i < 2; i++) {
				rMa.attr[y] = t;
				rVc.push_back(rMa);
			}
		}

		flag = false;
		for (int i = 0; i < cVc.size(); i++) {
			if (cVc[i].attr[3 - x] == 0 && cVc[i].attr[2 - x] == 0) {
				cVc[i].attr[3 - x] = t;
				cVc[i].attr[2 - x] = t;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cMa.attr[3 - x] = t;
			cMa.attr[2 - x] = t;
			cVc.push_back(cMa);
		}
	}
}

bool downBlock() {
	bool rsd = false;
	for (int j = 0; j < 4; j++) {
		int tmp[3] = { 10, 10, 10 };
		for (int i = 0; i < rVc.size(); i++) {
			if (rVc[i].attr[j] == 1 && tmp[0] < 6) {
				rVc[i].attr[j] = 0;
				rVc[tmp[0]].attr[j] = 1;
				
				rsd = true;
				break;
			}
			else if (rVc[i].attr[j] == 2 && tmp[1] < 6) {
				rVc[i].attr[j] = rVc[i].attr[j + 1] = 0;
				rVc[tmp[1]].attr[j] = rVc[tmp[1]].attr[j + 1] = 1;
				
				rsd = true;
				break;
			}
			else if (rVc[i].attr[j] == 3 && tmp[2] < 6) {
				rVc[i].attr[j] = rVc[i + 1].attr[j] = 0;
				rVc[tmp[2]].attr[j] = rVc[tmp[2] + 1].attr[j] = 1;

				rsd = true;
				break;
			}

			if (rVc[i].attr[j] == 0) {
				tmp[0] = tmp[0] > i ? i : tmp[0];
				if (j < 3 && rVc[i].attr[j + 1] == 0) {
					tmp[1] = tmp[1] > i ? i : tmp[1];
				}
				if (rVc.size() >= 2) {
					if (i < 5 && rVc[i + 1].attr[j] == 0) {
						tmp[2] = tmp[2] > i ? i : tmp[2];
					}
				}
			}
		}
	}

	for (int j = 0; j < 4; j++) {
		int tmp[3] = { 10, 10, 10 };
		for (int i = 0; i < cVc.size(); i++) {
			if (cVc[i].attr[j] == 1 && tmp[0] < 6) {
				cVc[i].attr[j] = 0;
				cVc[tmp[0]].attr[j] = 1;

				rsd = true;
				break;
			}
			else if (cVc[i].attr[j] == 2 && tmp[1] < 6) {
				cVc[i].attr[j] = cVc[i + 1].attr[j] = 0;
				cVc[tmp[2]].attr[j] = cVc[tmp[2] + 1].attr[j] = 1;

				rsd = true;
				break;
			}
			else if (cVc[i].attr[j] == 3 && tmp[2] < 6) {
				cVc[i].attr[j] = cVc[i].attr[j + 1] = 0;
				cVc[tmp[1]].attr[j] = cVc[tmp[1]].attr[j + 1] = 1;

				rsd = true;
				break;
			}

			if (cVc[i].attr[j] == 0) {
				tmp[0] = tmp[0] > i ? i : tmp[0];
				if (j < 3 && cVc[i].attr[j + 1] == 0) {
					tmp[2] = tmp[1] > i ? i : tmp[1];
				}
				if (cVc.size() >= 2) {
					if (i < 5 && cVc[i + 1].attr[j] == 0) {
						tmp[1] = tmp[2] > i ? i : tmp[2];
					}
				}
			}
		}
	}

	return rsd;
}

int blockClear() {
	int clearLine = 0;
	while (1) {
		bool flag = false;
		for (int i = 0; i < rVc.size(); i++) {
			int tmpChk = 0;
			for (int j = 0; j < 4; j++) {
				if (rVc[i].attr[j] == 1) {
					tmpChk++;
				}
			}

			if (tmpChk == 4) {
				rVc.erase(rVc.begin() + i);
				for (int j = i; j < rVc.size(); j++) {
					for (int k = 0; k < 4; k++) {
						if (rVc[j].attr[k] == 1) {

						}
						else if (rVc[j].attr[k] == 2) {

						}
						else if (rVc[j].attr[k] == 3) {

						}
					}
				}
				clearLine++;
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}

	while (1) {
		bool flag = false;
		for (int i = 0; i < cVc.size(); i++) {
			int tmpChk = 0;
			for (int j = 0; j < 4; j++) {
				if (cVc[i].attr[j] == 1) {
					tmpChk++;
				}
			}
			
			if (tmpChk == 4) {
				cVc.erase(cVc.begin() + i);
				clearLine++;
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}

	return clearLine;
}

void blockBoom() {
	while (rVc.size() > 6) {
		rVc.erase(rVc.begin());
	}
	while (cVc.size() > 6) {
		cVc.erase(cVc.begin());
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int score = 0;
	for (int i = 0; i < N; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		blockStack(t, x, y);
		score += blockClear();
		blockBoom();

		while (1) {
			bool db = downBlock();
			if (db) {
				score += blockClear();

				if (score == 0) {
					break;
				}
			}
			else {
				break;
			}
		}
	}

	for (int i = rVc.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			cout << rVc[i].attr[j] << ' ';
		}
		cout << '\n';
	}

	cout << '\n';
	for (int i = cVc.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			cout << cVc[i].attr[j] << ' ';
		}
		cout << '\n';
	}
}