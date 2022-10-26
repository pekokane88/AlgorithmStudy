/*
  1. 가장 작은 것과 그 다음 작은 값이 필요
  2. pq 를 이용하여 간단하게 구할 수 있음(오름차순 정렬 설정 필요, 혹은 - 값으로 이용)
  3. 만약 pq.top이 K 이상이면 종료
  4. 만약 pq.top이 K 이상이 아닌데, pq가 empty라면 -1을 return하고 종료.
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    int len = scoville.size();    
    for(int i = 0; i<len; i++){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()){
        int first = pq.top(); pq.pop();
        if(first >= K) break;
        else{
            if(pq.empty()){
                return -1;
            }
            else{
                int second = pq.top(); pq.pop();
                pq.push(first + (second * 2));
                answer += 1;
            }
        }
    }
    
    return answer;
}
