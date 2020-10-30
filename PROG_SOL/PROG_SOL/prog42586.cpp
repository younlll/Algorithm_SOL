#include <vector>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> rest;
    int len = progresses.size();
    int max = 0;
    for (int i = 0; i < len; i++) {
        int restWork = 100 - progresses[i]; //���� �۾���
        
        //���� �۾��� ó�� �Ⱓ
        int restDay = ceil((double)restWork / speeds[i]);
        rest.push_back(restDay);
    }

    queue<int> Queue;
    Queue.push(rest[0]);
    for (int i = 1; i < len; i++) {
        //������ �Ǵ� �۾����� ���� ����� �۾��� ���� ���� ��� ������ �۾� �߰�
        if (Queue.front() >= rest[i]) {
            Queue.push(rest[i]);
        }
        else {
            //������ �Ǵ� �۾����� ���� ����� �۾��� ���߿� ������ ���
            answer.push_back(Queue.size()); //������ �۾� ����
            while (!Queue.empty()) {
                Queue.pop();    //������ �۾��� pop
            }
            Queue.push(rest[i]);    //���� �۾�
        }
    }

    if (!Queue.empty()) {
        answer.push_back(Queue.size());
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //99, 1, 99, 1
    //93, 30, 55
    //95, 90, 99, 99, 80, 99
    vector<int> progresses = { 99, 1, 99, 1 };

    //1, 1, 1, 1
    //1, 30, 5
    //1, 1, 1, 1, 1, 1
    vector<int> speeds = { 1, 1, 1, 1 };

    vector<int> answer = solution(progresses, speeds);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;

}