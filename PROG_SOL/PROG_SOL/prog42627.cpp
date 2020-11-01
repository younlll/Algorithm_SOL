#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int workCnt = jobs.size();
    vector<pair<int, int>> readyQ;
    sort(jobs.begin(), jobs.end()); //job�� ���� �ð� �������� ��, �۾� �ҿ�ð� �������� ����

    int startTime = 0;
    int endTime = 0;
    while (readyQ.size() > 0 || jobs.size() > 0) {
        //
        if (readyQ.size() == 0) {
            readyQ.push_back(make_pair(jobs[0][0], jobs[0][1]));    //���� �۾� ����
            jobs.erase(jobs.begin());  //����� �۾� ���� 
        }
        //������ �۾��� ����,����ð� ���
        if (endTime >= readyQ[0].first) {
            startTime = endTime;
        }
        else {
            startTime = readyQ[0].first;
        }
        endTime = startTime + readyQ[0].second;

        //�۾� ���� ��, ������ job ����
        while (jobs.size() > 0 && jobs[0][0] <= endTime) {
            if (endTime >= jobs[0][0]) {    //�۾� ������ ���簡 ������ job üũ
                readyQ.push_back(make_pair(jobs[0][0], jobs[0][1]));
                jobs.erase(jobs.begin());
            }
        }

        answer = answer + (endTime - readyQ[0].first);
        readyQ.erase(readyQ.begin());   //����� �۾� ����
        sort(readyQ.begin(), readyQ.end(), comp);   //���� ������ �۾��� ���� ª�� �۾������� ����
    }

    return answer / workCnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //{{0, 3}, {1, 9}, {2, 6}}  //9
    //{{0, 4}, {0, 3}, {0, 2}, {0, 1}}  //5
    //{{0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3}}  //13
    //{{1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3}}  //13
    //{{0,3}} // 3
    //{{5,3}} // 3
    //{{0,3},{0,3}} // 9/2=4
    //{{0,3},{4,4}} // 7/2=3
    //{{0,3},{1,4},{2,5}} // 19/3=6
    //{{0,3},{1,1},{3,5}} // 12/3=4
    //{{0, 5}, {1, 2}, {5, 5}}  //6
    //{{0, 3}, {1, 9}, {500, 6}}    //6
    //{{0, 3}, {1, 9}, {500, 1}}    //5
    vector<vector<int>> jobs = { {0, 3}, {1, 9}, {2, 6} };
    int answer = solution(jobs);
    cout << answer << '\n';
}