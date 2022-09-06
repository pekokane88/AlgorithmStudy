/*
 DAT 이용. bucket[i] 가 0이면 그 숫자는 없는 값이기에 더해주면 된다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> bucket(10, 0);

int solution(vector<int> numbers) {
    int answer = 0;
    int numbersSize = numbers.size();
    
    for(int i = 0; i < numbersSize; i++){
        bucket[numbers[i]]++;
    }
    
    for(int i = 0; i<10; i++){
        if(bucket[i] == 0){
            answer += i;
        }
    }
    
    return answer;
}
