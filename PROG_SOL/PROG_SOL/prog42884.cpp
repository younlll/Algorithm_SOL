#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int, int>> vc;

    sort(routes.begin(), routes.end()); //���� ������ġ�� �������� �������� ����
    vc.push_back(make_pair(routes[0][0], routes[0][1]));    //ó�� ������ �ܼ���ġ
    for (int i = 1; i < routes.size(); i++) {
        int a = routes[i][0];
        int b = routes[i][1];
        bool flag = false;
        for (int j = 0; j < vc.size(); j++) {
            flag = false;
            //���� ������ �ܼ�ī�޶� ���� �ȿ� �ִ� ���
            if (vc[j].first <= a && a <= vc[j].second) {
                vc[j].first = a;
                flag = true;
            }
            //���� ������ ��ġ�� �ܼ�ī�޶� ���� �ƿ� �֤�.�� ���
            if (vc[j].first <= b && b <= vc[j].second) {
                vc[j].second = b;
                flag = true;
            }

            if (flag) {
                break;
            }
        }
        if (!flag) {    //�ܼ�ī�޶� ���� �ȿ� ������ �ѹ��� �ȳ��� ����
            vc.push_back(make_pair(a, b));
        }
    }

    answer = vc.size();

    return answer;
}

int main() {
    ios::sync_with_stdio;
    cin.tie(nullptr);

    //{ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }    // 2
    //{{-2, -1}, {1, 2}, {-3, 0}}   // 2
    //{{0, 1}, {0, 1}, {1, 2}}  // 1
    //{{0, 0}}} // 1
    //{{0, 1}, {2, 3}, {4, 5}, {6, 7}}  // 4
    //{{-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}}    //2
    //{{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}}  //2
    //{{-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}}  //2
    vector<vector<int>> routes = { {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} };
    int answer = solution(routes);

    cout << answer << '\n';

    return 0;
}