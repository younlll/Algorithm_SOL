#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end()); //Sorting vector
    int head = 0;
    int tail = people.size() - 1;
    while (head <= tail) {  //Serching for half of the vector
        if (head == tail) { //If the head and tail have the same index, only one person will use the boat to move.
            answer++;
            break;
        }
        if (people[head] + people[tail] <= limit) { //If the sum is less than the boat's limit
            answer++;
            head++;
            tail--;
        }
        else {  //If the sum is more than the boat's limit
            answer++;
            tail--;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //{ 70, 50, 80, 50 }
    //{80, 80, 50}
    vector<int> people = { 70, 50, 80, 50 };
    int limit = 100;

    int answer = solution(people, limit);
    cout << answer << '\n';
}