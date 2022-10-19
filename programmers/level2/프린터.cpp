/*
  최댓값을 이용해야 하기 때문에 queue와 priority_queue를 같이 사용한다.
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int,int>> qu;
priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int len = priorities.size();
    
    for(int i = 0; i<len; i++){
        qu.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(true){
        pair<int,int> temp = qu.front();
        int max = pq.top();
        if(max == temp.first){
            answer += 1;
            qu.pop();
            pq.pop();
            if(temp.second == location){
                break;
            }
        }
        else{
            qu.pop(); qu.push(temp);
        }
    }
    return answer;
}
