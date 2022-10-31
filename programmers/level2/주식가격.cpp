/*
  문제의 이해가 어려웠다.
  여기서 중요한 점은 n초 뒤에 주식의 가격이 떨어진다면 그 주식은 n초 동안 가격이 유지된다는 조건을 설정해주는 부분이다.
  그리고 prices의 길이가 10만이라 2중 for문으로 해결할 수 없다고 생각하였다. 따라서 직접 시간을 계산해보았다. 2중 for문의 최악의 연산 횟수는 1~n-1까지의 연산이다.
  따라서 1~n-1까지의 합은 (n*n-1)/2 이기 때문에 이는 약 50억번의 연산이면 최악 50초가 걸린다는 의미가 된다.
  시간 복잡도면에서 보면 해결할 수 없기 때문에, 정확한 풀이는 아니라고 생각된다. 나중에 더 좋은 풀이를 생각해봐야겠다.
*/
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int len = prices.size();
    
    for(int i = 0; i<len; i++){
        int temp = 0;
        for(int j = i + 1; j<len; j++){
            temp += 1;
            if(prices[i] > prices[j]) break;
        }
        answer.push_back(temp);
    }
    
    return answer;
}
