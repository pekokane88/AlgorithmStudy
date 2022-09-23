/*
  한정된 예산으로 가장 많은 부서에 돈을 주는 것이 목표 -> Greedy 알고리즘 이용
  벡터를 정렬 후 예산이 가장 적게 드는 부서를 먼저 준다. 그러면 가장 많은 부서에 예산을 나눠줄 수 있다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    int dSize = d.size();
    sort(d.begin(), d.end());
    
    for(int i = 0; i<dSize; i++){
        if(d[i] <= budget){
            answer += 1;
            budget -= d[i];
        }
    }
    
    return answer;
}
