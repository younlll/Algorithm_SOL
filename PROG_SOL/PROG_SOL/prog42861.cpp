#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> parent(101);

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int getParent(int x) {
    //노드x의 부모가 본인(x)인 경우, x 반환
    if (parent[x] == x) {
        return x;
    }

    //부모가 다른 노드인 경우, 가리키는 부모값으로 다시 부모노드를 찾는다(재귀)
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    //각 노드의 부모노드를 찾는다
    int parentA = getParent(a);
    int parentB = getParent(b);

    //부모노드 값이 더 작은쪽이 상대 노드의 부모가 된다
    if (parentA < parentB) {
        parent[parentB] = parentA;
    }
    else {
        parent[parentA] = parentB;
    }
}

bool findParent(int a, int b) {
    //해당 노드의 부모를 찾아준다
    int parentA = getParent(a);
    int parentB = getParent(b);

    //부모가 같으면 true, 다르면 false르 반환한다
    if (parentA == parentB) {
        return true;
    }
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    //아직 연결된 노드가 없으므로 본인을 본인의 부모로 설정한다
    for (int i = 0; i < costs.size(); i++) {
        parent[costs[i][0]] = costs[i][0];
        parent[costs[i][1]] = costs[i][1];
    }

    //섬간의 거리를 기준으로 오름차순 정렬한다
    sort(costs.begin(), costs.end(), cmp);

    for (int i = 0; i < costs.size(); i++) {
        //부모가 같은경우(순환 발생) continue
        if (findParent(costs[i][0], costs[i][1]) == true) {
            continue;
        }
        
        //부모가 다른경우, 노드끼리 연결을 통해 부모를 합쳐준다
        unionParent(costs[i][0], costs[i][1]);

        //섬간의 이동 비용을 합산해준다
        answer += costs[i][2];
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 5;
    vector<vector<int>> costs = { {0, 1, 1},{3, 4, 1},{1, 2, 2},{2, 3, 4} };
    int answer = solution(n, costs);
    cout << answer << '\n';

}