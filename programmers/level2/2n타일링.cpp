#include <string>
#include <vector>
#include <cmath>
using namespace std;

//규칙이 있는지 살펴볼 수 있도록 하자. -> 이런 단순히 무식한 반복 코드들은 무언가 다른 방법이 있을 것!

int solution(int n) {
    int answer = 0;
    long long mod = pow(10,9) + 7;
    vector<int> dp = vector<int>(n + 1, 0);
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i<=n; i++){
        dp[i] = (dp[i-2] + dp[i-1]) % mod;
    }
    
    answer = dp[n];
    
    return answer;
}
