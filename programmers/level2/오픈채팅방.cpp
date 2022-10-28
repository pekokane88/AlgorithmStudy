/*
  주차요금 계산하기 문제와 비슷한 문자열 parsing 문제.
  1. 입력을 분석 Enter, uid 를 묶고 uid 와 nickname 을 묶어서 따로 생각한다.
  2. um에는 Enter 와 change가 들어올 때마다 해쉬 맵을 이용하여 최신 닉네임 데이터를 가지고 있는다.
  3. v1 에는 누가 나가고 들어왔는지에 대한 기록을 가지고 있는다.
  4. 마지막에 v1을 이용해 해당 uid 를 가진 유저의 최신 닉네임을 map에서 가져오고 Enter인지 Leave인지 확인해 반환해준다.
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string,string> um;
vector<pair<string,string>> v1;

int LEN = 0;

vector<string> parseStr(string str){
    int len = str.size();
    string temp = "";
    vector<string>result;
    for(int i = 0; i<len; i++){
        if(str[i] == ' '){
            result.push_back(temp);
            temp = "";
        }
        else if(i == len - 1){
            temp += str[i];
            result.push_back(temp);
            temp = "";
        }
        else{
            temp += str[i];
        }
    }
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    LEN = record.size();
    
    for(int i = 0; i < LEN; i++){
        vector<string> tempV = parseStr(record[i]);
        if(tempV[0] == "Enter" || tempV[0] == "Change"){
            um[tempV[1]] = tempV[2];
        }
        if(tempV[0] == "Enter" || tempV[0] == "Leave"){
            v1.push_back({tempV[0], tempV[1]});
        }
    }
    
    LEN = v1.size();
    for(int i = 0; i<LEN; i++){
        string tempStr = "";
        if(v1[i].first == "Enter"){
            tempStr = um[v1[i].second] + "님이 들어왔습니다.";
            answer.push_back(tempStr);
        }
        else{
            tempStr = um[v1[i].second] + "님이 나갔습니다.";
            answer.push_back(tempStr);
        }
    }
    
    return answer;
}
