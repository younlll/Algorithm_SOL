#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1[] = {1, 2, 3, 4, 5};
    int p2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int p3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int point[3] = {0,};
    int idx1, idx2, idx3 = 0;
    idx1 = idx2 = idx3 = 0;
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == p1[idx1]){
            point[0]++;
        }
        if(answers[i] == p2[idx2]){
            point[1]++;
        }
        if(answers[i] == p3[idx3]){
            point[2]++;
        }
        
        idx1++;
        idx2++;
        idx3++;
        
        if(idx1 >= 5){
            idx1 = 0;
        }
        if(idx2 >= 8){
            idx2 = 0;
        }
        if(idx3 >= 10){
            idx3 = 0;
        }
    }
    
    int max = 0;
    for(int i = 0; i < 3; i++){
        if(point[i] > max){
            max = point[i];
        }
    }
    
    for(int i = 0; i < 3; i++){
        if(point[i] == max){
            answer.push_back(i+1);
        }
    }
    
    
    return answer;
}
