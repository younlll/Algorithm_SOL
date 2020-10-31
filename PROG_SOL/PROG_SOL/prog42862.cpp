#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();    //The first case is that no one gets spare clothes

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            //The case losted student is same reserve student
            if (lost[i] == reserve[j]) {
                answer++;
                reserve[j] = -1;
                lost[i] = -1;
                break;
            }
        }
    }

    //Repeat the number of lost students
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == -1) {
            continue;
        }
        //Repeat the number of reserve students
        for (int j = 0; j < reserve.size(); j++) {
            //Check from the value of -1 or +1 or number
            if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) {
                //If this case is ture, +1 in answer value
                answer++;
                reserve[j] = -1;
                break;
            }
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;  // 5  5  3  5  5
    vector<int> lost = { 2, 4 };    // {2, 4}  {2, 4}  {3}  {2, 3, 4}  {2, 3|
    vector<int> reserve = { 1, 3, 5 };  // {1, 3, 5}  {3}  {1}  {1, 3}  {3, 4}

    int answer = solution(n, lost, reserve);
    cout << answer << '\n';

    return 0;
}