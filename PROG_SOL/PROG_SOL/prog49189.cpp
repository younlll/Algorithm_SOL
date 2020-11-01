#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> oneDir(n + 1, 0);
    vector<bool> visited(n + 1, false);
    vector<int> vc[20001];

    for (int i = 0; i < edge.size(); i++) {
        //����� ��� ���� ����
        vc[edge[i][0]].push_back(edge[i][1]);
        vc[edge[i][1]].push_back(edge[i][0]);
    }

    queue<int> Queue;
    Queue.push(1);  //1�� ��忡�� ���
    oneDir[1] = 0;
    visited[1] = true;
    int maxCnt = 0;
    while (!Queue.empty()) {
        int cur = Queue.front();    //���� ����ȣ
        Queue.pop();
        int curDir = oneDir[cur];   //���� ��忡�� 1���� ���� �Ÿ�

        if (curDir > maxCnt) {    //�����忡�� 1���� ���� �Ÿ��� �ִ뺸�� ū ���
            maxCnt = curDir;    //�ִ밪 ����
            answer = 1;         //coning 1�� �ʱ�ȭ
        }
        else if (curDir == maxCnt) { //�����忡�� 1���� ���� �Ÿ��� �ִ�� ���� ���
            answer++;   //counting
        }

        for (int i = 0; i < vc[cur].size(); i++) {
            //������� �� �湮���� ���� ���� ó��
            if (!visited[vc[cur][i]]) {
                Queue.push(vc[cur][i]);
                oneDir[vc[cur][i]] = curDir + 1;  //���� ��忡�� +1�� �Ÿ��� 1���� �����ϴµ� �ʿ��� �ִܰŸ�
                visited[vc[cur][i]] = true;
            }
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6;
    vector<vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2}};
    int answer = solution(n, edge); // 3
    cout << answer << '\n';

    return 0;
}