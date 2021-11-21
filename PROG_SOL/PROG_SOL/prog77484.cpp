#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    vector<int>::iterator iter;
    int zeroCnt = 0;
    int matchCnt = 0;
    
    // unknown number counting
    for(int i = 0; i < lottos.size(); i++){
        if(lottos[i] == 0){
            zeroCnt++;
        }
    }
    
    cout << "zeroCnt: " << zeroCnt << '\n';
    
    // number match count
    for(int i = 0; i < win_nums.size(); i++){
        iter = find(lottos.begin(), lottos.end(), win_nums[i]);
        
        cout << "num: " << win_nums[i] << ' ';
        
        if(iter != lottos.end()){
            matchCnt++;
            cout << matchCnt << '\n';
        }
    }
    
    int matchMin = matchCnt;
    int matchMax = matchCnt + zeroCnt;
    for(int i = 0; i <= 6; i++){
        if(matchMin == i){
            if(i == 0 || i == 1){
                answer.push_back(6);
            }else{
                answer.push_back(7 - i);
            }
        }
        if(matchMax == i){
            if(i == 0 || i == 1){
                answer.push_back(6);
            }else{
                answer.push_back(7 - i);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
