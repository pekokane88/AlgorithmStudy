#include <string>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int now;
    int level;
};
queue<node> qu;

int solution(int x, int y, int n) {
    int answer = -1;
    
    if(x == y){
        return 0;
    }
    node n1 = {y, 0};
    qu.push(n1);
    
    while(!qu.empty()){
        node cur = qu.front(); qu.pop();
    
        if(cur.now < x) continue;
        if(cur.now == x){
            return cur.level;
        }
        if(cur.now % 2 == 0){
            qu.push({cur.now / 2, cur.level + 1});            
        }
        if(cur.now % 3 == 0){
            qu.push({cur.now / 3, cur.level + 1});
        }
        qu.push({cur.now - n, cur.level + 1});
    }
    
    return answer;
}
