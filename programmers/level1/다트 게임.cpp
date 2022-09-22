/*
  score 배열 -> 다트 점수를 저장하기 위한 배열
  cnt -> 다트 횟수를 체크 (무조건 점수가 세번 들어오기에 가능)
  문자열 파싱을 하면서 1. 점수일 경우 2. 보너스일 경우 3. 옵션일 경우를 나눠 처리해준다.
  그리고 마지막에 score 배열에 있는 점수를 모두 더해준다.
*/
#include <string>

using namespace std;

int score[3] = {0};

int solution(string dartResult) {
    int answer = 0;
    
    int cnt = 0; // 
    int dartLength = dartResult.size();
    
    for(int i = 0; i<dartLength; i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(dartResult[i] == '1' && dartResult[i+1] == '0'){
                i = i+1;
                score[cnt] = 10;
            }
            else{
                string tempStr = "";
                tempStr += dartResult[i];
                score[cnt] = stoi(tempStr);
            }
            cnt++;
        }
        else if(dartResult[i] >= 'A' && dartResult[i] <= 'Z'){
            if(dartResult[i] == 'D') score[cnt - 1] *= score[cnt - 1];
            if(dartResult[i] == 'T') score[cnt - 1] *= (score[cnt - 1] * score[cnt - 1]);
        }
        else{
            if(dartResult[i] == '*'){
               if(cnt >= 2){
                   score[cnt - 1] *= 2;
                   score[cnt - 2] *= 2;
               } 
                else{
                    score[cnt - 1] *= 2;    
                }
            } 
            else if(dartResult[i] == '#'){
               score[cnt - 1] *= -1; 
            }
            
        }
    }
    
    answer = score[0] + score[1] + score[2];
    
    return answer;
}
