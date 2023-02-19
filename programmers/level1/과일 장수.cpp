//sort 를 하여 큰 것부터 취해간다. 일종의 Greedy Algorithm
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    
    int count = 0;
    
    for(int i = score.size() - 1; i >= 0; i--){
        count += 1;
        if(count == m){
            answer += (score[i] * m);
            count = 0;
        }
    }
    
    return answer;
}
