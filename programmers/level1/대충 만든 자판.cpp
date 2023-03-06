//map 에 등록하면서 기존 값이 있으면 최소 값을 등록. 해당 키가 map 에 등록이 되어 있지 않다면 바로 -1 을 반환해야 한다.
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char, int> um;

void init(vector<string> v1){
    for(int i = 0; i<v1.size(); i++){
        for(int j = 0; j<v1[i].size(); j++){
            if(um.count(v1[i][j]) == 0){
                um[v1[i][j]] = j + 1;
            }
            else{
                um[v1[i][j]] = min(um[v1[i][j]], j + 1);
            }
        }
    }
    return;
}

int checkTarget(string str){
    int result = 0;
    for(int i = 0; i<str.size(); i++){
        if(um.count(str[i]) == 0) return -1;
        result += um[str[i]];
    }
    return result;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    init(keymap);
    
    for(int i = 0; i<targets.size(); i++){
        int cnt = checkTarget(targets[i]);
        answer.push_back(cnt);
    }
    
    return answer;
}
