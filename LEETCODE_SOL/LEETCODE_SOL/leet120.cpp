#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int answer = 0;
        
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= triangle[i].size() - 1; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        
        answer = triangle[0][0];

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //{ {2},{3, 4},{6, 5, 7},{4, 1, 8, 3} }
    //{ {-1},{2, 3},{1, -1, -3} }
    vector<vector<int>> triangle = { {-1},{2, 3},{1, -1, -3} };
    Solution solution;
    int answer = solution.minimumTotal(triangle);

    cout << answer << '\n';

    return 0;
}