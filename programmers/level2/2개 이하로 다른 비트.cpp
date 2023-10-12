#include <string>
#include <vector>
#include <cmath>
using namespace std;

//2개 이하로 다른 비트 구하기
//짝수의 경우 1을 더해주면 마지막 비트 수 1자리가 차이 난다.
//홀수의 경우 최초 0이 나온 비트 자리수 에서 그 옆 자리와 값을 바꿔주면 2개 이상 차이나며 가장 최소의 숫자가 나오게 된다.

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    //0이 가장 처음어디서 나오느냐가 중요.
    for(int i = 0; i<numbers.size(); i++){
        long long num = numbers[i];
        long long temp = num;
        long long cnt = 0;
        
        while(temp > 0){
            if(temp % 2 == 0){
                break;
            }
            temp /= 2;
            cnt += 1;
        }
        
        if(cnt == 0){
            num += 1;
        }else{
            num = num + pow(2, cnt - 1);
        }
        answer.push_back(num);
    }

    return answer;
}
