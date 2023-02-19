//들어올 때마다 순위를 sorting 해주는 것은 비효율적이다. size 가 유동적일 때는 sort 보다 priority queue를 이용하는 것이 효율적이다.
#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    for(int i = 0; i<score.size(); i++){
        if(pq.size() == k){
            pq.push(score[i]);
            pq.pop();
            answer.push_back(pq.top());
        }
        else{
            pq.push(score[i]);
            answer.push_back(pq.top());
        }
    }
    
    return answer;
}
