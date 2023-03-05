//마지막에 cnt 가 0이 아니라는 뜻은 문자열 길이로 인해 더 이상 비교할 대상이 남아있지 않다는 의미. 따라서 +1 을 해준다.
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int originCnt = 0;
    int cmpCnt = 0;
    char origin = 0;
    
    for(int i = 0; i<s.size(); i++){
        if(origin == 0){
            origin = s[i];
            originCnt += 1;
       }
        else{
            if(origin == s[i]) originCnt += 1;
            else cmpCnt += 1;
            
            if(originCnt == cmpCnt){
                answer += 1;
                origin = 0;
                originCnt = 0; cmpCnt = 0;
            }
        }
    }
    
    if(originCnt != 0 or cmpCnt != 0){
        answer += 1;
    }
    
    return answer;
}
