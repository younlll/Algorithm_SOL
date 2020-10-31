#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int len = number.length() - k;  //String length excluding k
    
    int maxIdx = -1;
    int start = maxIdx;
    while (len) {
        int max = 0;
        for (int i = number.length() - len; i > start; i--) {
            if (max <= number[i] - '0') {
                max = number[i] - '0';
                maxIdx = i;
            }
        }

        start = maxIdx;
        answer += (max + '0');
        len--;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string number = "1924"; //  1924  1231234  4177252841
    int k = 2; //  2  3  4

    string answer = solution(number, k);
    cout << answer << '\n';

    return 0;
}