/*
  2부터 n-1 까지 % 했을 때 1이 나오는 수를 찾자마자 break해서 값을 반환해준다.
  n 최대값이 1000000 이기에 for 문으로 완탐을 하여도 문제가 없다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 2; i<n; i++){
        if(n%i == 1){
            answer = i;
            break;
        }
    }
    
    return answer;
}
