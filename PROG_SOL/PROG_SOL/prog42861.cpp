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
    //���x�� �θ� ����(x)�� ���, x ��ȯ
    if (parent[x] == x) {
        return x;
    }

    //�θ� �ٸ� ����� ���, ����Ű�� �θ����� �ٽ� �θ��带 ã�´�(���)
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    //�� ����� �θ��带 ã�´�
    int parentA = getParent(a);
    int parentB = getParent(b);

    //�θ��� ���� �� �������� ��� ����� �θ� �ȴ�
    if (parentA < parentB) {
        parent[parentB] = parentA;
    }
    else {
        parent[parentA] = parentB;
    }
}

bool findParent(int a, int b) {
    //�ش� ����� �θ� ã���ش�
    int parentA = getParent(a);
    int parentB = getParent(b);

    //�θ� ������ true, �ٸ��� false�� ��ȯ�Ѵ�
    if (parentA == parentB) {
        return true;
    }
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    //���� ����� ��尡 �����Ƿ� ������ ������ �θ�� �����Ѵ�
    for (int i = 0; i < costs.size(); i++) {
        parent[costs[i][0]] = costs[i][0];
        parent[costs[i][1]] = costs[i][1];
    }

    //������ �Ÿ��� �������� �������� �����Ѵ�
    sort(costs.begin(), costs.end(), cmp);

    for (int i = 0; i < costs.size(); i++) {
        //�θ� �������(��ȯ �߻�) continue
        if (findParent(costs[i][0], costs[i][1]) == true) {
            continue;
        }
        
        //�θ� �ٸ����, ��峢�� ������ ���� �θ� �����ش�
        unionParent(costs[i][0], costs[i][1]);

        //������ �̵� ����� �ջ����ش�
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