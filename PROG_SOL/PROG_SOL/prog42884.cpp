#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int, int>> vc;

    sort(routes.begin(), routes.end()); //차량 시작위치를 기준으로 오름차순 정렬
    vc.push_back(make_pair(routes[0][0], routes[0][1]));    //처음 차량의 단속위치
    for (int i = 1; i < routes.size(); i++) {
        int a = routes[i][0];
        int b = routes[i][1];
        bool flag = false;
        for (int j = 0; j < vc.size(); j++) {
            flag = false;
            //차량 시적이 단속카메라 범위 안에 있는 경우
            if (vc[j].first <= a && a <= vc[j].second) {
                vc[j].first = a;
                flag = true;
            }
            //차량 마지막 위치가 단속카메라 범위 아에 있ㄴ.ㄴ 경우
            if (vc[j].first <= b && b <= vc[j].second) {
                vc[j].second = b;
                flag = true;
            }

            if (flag) {
                break;
            }
        }
        if (!flag) {    //단속카메라 범위 안에 차량이 한번도 안나온 이유
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