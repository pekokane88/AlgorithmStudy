/*
  절댓값과 부호값을 넣으면 부호를 반영한 수를 반환해주는 함수를 하나 생성하여 answer에 바로 더해준다.
*/
#include <string>
#include <vector>

using namespace std;

int changeNumber(int num, bool b){
    if(b) return num;
    else return num * -1;    
}

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int absSize = absolutes.size();
    
    for(int i = 0; i<absSize; i++){
        answer += changeNumber(absolutes[i], signs[i]);
    }
    
    return answer;
}
