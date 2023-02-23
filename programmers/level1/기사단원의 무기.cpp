// 해당 수의 모든 배수를 체크한다. 그러면 자연스럽게 i의 약수의 개수가 구해지게 된다.
// 이때 1은 모든 수의 약수이기 때문에 초기에 vector 을 1로 초기화해주었다.

#include <string>
#include <vector>
using namespace std;

vector<int> bucket(100001, 1);

void checkDivisor(int num){
    for(int i = 2; i<=num; i++){
        int tempNum = i;
        while(tempNum <= num){
            if(tempNum % i == 0){
                bucket[tempNum] += 1;
            }
            tempNum += i;
        }
    }
    return;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    checkDivisor(number);
    
    for(int i = 1; i<=number; i++){
        if(bucket[i] > limit){
            answer += power;
        }
        else{
            answer += bucket[i];
        }
    }    
    
    return answer;
}
