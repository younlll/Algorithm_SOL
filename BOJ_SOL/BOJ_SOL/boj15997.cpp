#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string, int> m;
	vector<double> vc;
	string str;
	getline(cin, str);
	
	stringstream ss(str);
	string strTemp;

	int idx = 0;
	while (getline(ss, strTemp, ' ')) {
		m.insert({ strTemp,  idx++});
		vc.push_back(0.0);
	}

	for (int i = 0; i < 6; i++) {
		getline(cin, str);
		stringstream ss2(str);
		strTemp = "";
		vector<string> vcStr;
		while (getline(ss2, strTemp, ' ')) {
			vcStr.push_back(strTemp);
		}

		vc[m[vcStr[0]]] = vc[m[vcStr[0]]] + stod(vcStr[2]) + stod(vcStr[3]);
		vc[m[vcStr[1]]] = vc[m[vcStr[1]]] + stod(vcStr[3]) + stod(vcStr[4]);
	}

	for (int i = 0; i < 4; i++) {
		vc[i] /= 3;
		vc[i] = floor(vc[i] * 10) / 10;
	}
	for (int i = 0; i < 4; i++) {
		cout << vc[i] << '\n';
	}
	return 0;
}