#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(pair<long, long> p1, pair<long, long>p2){
        if(p1.second > p2.second){
           return false; 
        }
        else{
            return true;
        }
    }
};

unordered_map<long, long> um;
priority_queue<pair<long,long>, vector<pair<long,long>>, cmp> pq;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for(int i = 0; i<tangerine.size(); i++){
        if(um.count(tangerine[i]) == 0){
            um[tangerine[i]] = 1;
        }
        else{
            um[tangerine[i]] += 1;
        }
    }
    
    for(auto item : um){
        pq.push({item.first, item.second});
    }
    
    int sum = 0;
    int count = 0;
    
    while(!pq.empty()){
        pair<long, long> temp = pq.top(); pq.pop();
        count += 1;
        sum += temp.second;
        if(sum >= k){
            break;
        }
    }
    
    answer = count;
    return answer;
}
