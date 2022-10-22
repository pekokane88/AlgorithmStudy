/*
  단어 조합을 만들고, 이를 이용해 공집합, 교집합, 합집합을 만들어 비교하는 문제.
  구현 자체는 그렇게 어렵지 않으나, 한 가지 주의해야 하는 점은
  unordered_map의 사이즈가 아닌 키의 값을 이용해야한다는 점이다. (교집합과 합집합의 의미를 다시 한번 생각해보면 쉽게 이해 가능)
*/
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

string s1, s2;
unordered_map<string, int> um1;
unordered_map<string, int> um2;

string transferStr(string str){
    int len = str.size();
    
    string temp = "";
    
    for(int i = 0; i<len; i++){
        if(str[i] >='a' && str[i] <= 'z'){
            temp += (str[i] - 32);
        }
        else temp += str[i];
    }
    
    return temp;
}

bool checkWord(string str){
    int len = str.size();
    for(int i = 0; i<len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z') continue;
        else return false;
    }
    return true;
}

void makeWord(){
    int len = s1.size();
    for(int i = 0; i<len - 1; i++){
        string temp = "";
        bool flag = false;
        for(int j = i; j <= i + 1; j++){
            temp += s1[j]; 
        }
        if(checkWord(temp)){
            if(um1.count(temp) == 0) um1[temp] = 1;
            else um1[temp] += 1;
        }
    }
    
    len = s2.size();
    for(int i = 0; i<len - 1; i++){
        string temp = "";
        bool flag = false;
        for(int j = i; j <= i + 1; j++){
            temp += s2[j]; 
        }
        if(checkWord(temp)){
            if(um2.count(temp) == 0) um2[temp] = 1;
            else um2[temp] += 1;
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    s1 = transferStr(str1); s2 = transferStr(str2);
    
    if(s1 == s2) return 65536;
    makeWord();
    if(um1.size() == 0 && um2.size() == 0) return 65536;
  
    int sameWord = 0;
    int sumWord = 0;
    for (auto it = um1.begin(); it != um1.end(); ++it){
        if(um2.count(it->first) != 0){
            if(um1[it->first] == um2[it->first]){
                sameWord += it->second;
                sumWord += it->second;
                um2[it->first] = 0;
            }
            else{
                sameWord += min(um1[it->first], um2[it->first]);
                sumWord += max(um1[it->first], um2[it->first]);
                um2[it->first] = 0;
            }
        }
        else{
            sumWord += it->second;
        }
    }
    
    for (auto i = um2.begin(); i != um2.end(); ++i){
        if(i->second != 0){
            sumWord += i->second;
        }
    }
    answer = (sameWord * 65536)/sumWord;
    return answer;
}
