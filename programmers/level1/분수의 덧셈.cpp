//우선 두 분수를 더한 후, 분자와 분모의 최대 공약수로 각각 나눠주면 기약분수가 완성된다.
#include <string>
#include <vector>
using namespace std;

int getDec(int num1, int num2){
    int result = 1;
    
    while(num2 != 0){
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    
    result = num1;
    
    return result;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int tempNum1 = numer1 * denom2 + numer2 * denom1;
    int tempNum2 = denom1 * denom2;
    int max = getDec(tempNum1, tempNum2);
    
    answer.push_back(tempNum1 / max);
    answer.push_back(tempNum2 / max);
    
    return answer;
}
