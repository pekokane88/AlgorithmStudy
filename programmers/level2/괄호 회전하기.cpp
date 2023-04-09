#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, char> um{
    {'}', '{'},
    {']', '['},
    {')', '('},
};

bool checkFunc(string str){
    if(str[0] == ']' or str[0] == ')' or str[0] == '}') return false;
    
    bool result = true;
    vector<char> v1;
    
    for(int i = 0; i<str.size(); i++){
        if(str[i] == '[' or str[i] == '{' or str[i] == '('){
            v1.push_back(str[i]);
        }
        else{
            char ch = v1[v1.size() - 1]; v1.pop_back();
            if(ch != um[str[i]]){
                return false;
            }
        }
    }
    
    if(v1.size() != 0) return false;
    
    return result;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i<s.size(); i++){
        if(checkFunc(s)){
            answer += 1;
        }
        char temp = s[0];
        s = s.substr(1) + temp;
    }
    
    return answer;
}
