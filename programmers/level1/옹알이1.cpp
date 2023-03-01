#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um = {
    {"aya", 1},
    {"ye", 1},
    {"woo", 1},
    {"ma", 1},
};

bool checkCanSay(string str){
    bool result = true;
    
    string temp = "";
    for(int i = 0; i<str.size(); i++){
        temp += str[i];
        if(um[temp]){
            temp = "";
        }
        else{
            if(temp.size() == 3) return false;
            if(i == str.size() - 1){
                if(!um[temp]){
                    return false;
                }
            }
        }
    }
    return result;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    int len = babbling.size();
    
    for(int i = 0; i<len; i++){
        if(checkCanSay(babbling[i])){
            answer += 1;
        }
    }
    
    return answer;
}
