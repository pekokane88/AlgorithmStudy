/*
  통과는 하였으나, 효울적이지 못한 것 같다. 추후 수정
  1. hash_map 을 이용하여 각 아이디에 번호를 부여.
  2. 배열을 이용해 누가 누구를 신고하였는지 기록, 이때 1번 이상 신고한 기록은 무시
  3. k이상 신고당한 유저만을 담은 배열을 이용하여 신고한 사람 추가.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int idSize;
int reportSize;
unordered_map<string, int> um;
int arr[1001][1001] = {0};
vector<string> overK;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    idSize = id_list.size();
    reportSize = report.size();
    
    for(int i = 0; i<idSize; i++){
        um[id_list[i]] = i + 1;
    }
    
    for(int i = 0; i<reportSize; i++){
        int len = report[i].size();
        string person[2] = {"", ""};
        int index = 0;
        for(int j = 0; j<len; j++){
            if(report[i][j] == ' '){
                index = 1;
                continue;
            }
            person[index] += report[i][j];
        }
        if(arr[um[person[0]]][um[person[1]]] == 0){
            arr[um[person[0]]][um[person[1]]] = 1;
        }
    }
    
    for(int x = 1; x<=idSize; x++){
        int cnt = 0;
        for(int y = 1; y<=idSize; y++){
            if(arr[y][x] == 1) cnt += 1;
        }
        if(cnt >= k) overK.push_back(id_list[x-1]);
    }
    
   answer = vector<int>(idSize, 0);
    
    if(overK.size() == 0){
        return answer;
    }
    else{
        int overKSize = overK.size();
        for(int i = 0; i<overKSize; i++){
            string temp = overK[i];
            for(int j = 1; j<=idSize; j++){
                if(j == um[temp]) continue;
                if(arr[j][um[temp]] == 1) answer[j-1]+=1;
            }      
        }
    }
        
    return answer;
}
