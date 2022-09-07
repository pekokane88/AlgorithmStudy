/*
  나누기 연산자와 나머지 연산자를 이용하여 1의 자리 수를 계속 추출해 나가며 answer에 더해주고 반환한다.
*/

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int copyN = n;
    
    answer += (copyN % 10);
    copyN /= 10;
    
    while(copyN != 0){
        answer += (copyN % 10);
        copyN /= 10;
    }

    return answer;
}
