// 기존 옹알이1에서 history 를 추가하여 이전 발음과 비교.
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um{
    {"aya", 1},
    {"ye", 1},
    {"woo", 1},
    {"ma", 1},
};

bool checkSay(string str){
    bool result = true;
    
    string temp = "";
    string history = "";
    for(int i = 0; i<str.size(); i++){
        temp += str[i];
        
        if(um[temp]){
            if(temp == history){
                return false;
            }
            else{
                history = temp;
                temp = "";
            }
        }
        else{
            if(temp.size() == 3 or i == str.size() - 1){
                return false;
            }
        }
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i = 0; i<babbling.size(); i++){
        if(checkSay(babbling[i])){
            answer += 1;
        }
    }
    
    return answer;
}
