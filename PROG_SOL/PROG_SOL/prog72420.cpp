#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i = 0; i < new_id.length(); i++){
       if('A' <= new_id[i] && new_id[i] <= 'Z'){
           new_id[i] = new_id[i] - 'A' + 'a';
        }
    }

    // step2
    for(int i = 0; i < new_id.length(); i++){
        if('a' <= new_id[i] && new_id[i] <= 'z'){
            continue;
        }
        if('0' <= new_id[i] && new_id[i] <= '9'){
            continue;
        }
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            continue;
        }

        new_id.erase(i, 1);
        i--;
    }

    // step3
    for(int i = 0; i < new_id.length() - 1; i++){
        if(new_id[i] == '.' && new_id[i+1] == '.'){
            new_id.erase(i+1, 1);
            i--;
        }
    }

    // step4
    if(new_id[0] == '.'){
        new_id.erase(0, 1);
    }
    if(new_id[new_id.length() - 1] == '.'){
        new_id.erase(new_id.length() - 1, 1);
    }

    // step5
    if(new_id.length() == 0){
        new_id += 'a';
    }

    // step6
    if(new_id.length() >= 16){
        new_id.erase(15);
        if(new_id[14] == '.'){
           new_id.erase(14);
        }
    }

    // step7
    if(new_id.length() <= 2){
        char lastCh = new_id[new_id.length() - 1];

        while(new_id.length() < 3){
           new_id += lastCh;
        }
    }
    
    answer = new_id;
    
    return answer;
}
