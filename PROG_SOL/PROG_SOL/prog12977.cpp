#include <vector>
#include <iostream>
#include <set>
using namespace std;

int primeNumArr[10001];

int solution(vector<int> nums) {
    int answer = 0;
    
    primeNumArr[0] = primeNumArr[1] = 1;
    for(int i = 2; i <= 10000; i++){
        if(primeNumArr[i] == 0){
            int tmp = 2;
            while(i * tmp <= 10000){
                primeNumArr[i * tmp] = 1;
                tmp++;
            }
        }
    }
    
	for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            for(int k = j + 1; k < nums.size(); k++){
                int n = nums[i] + nums[j] + nums[k];
                
                if(primeNumArr[n] == 0){
                    answer++;
                }
            }
        }
    }
    
    return answer;
}
