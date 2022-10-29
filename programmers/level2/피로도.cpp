/*
  1. 기초적인 dfs 문제. map의 크기도 최대 8개 밖에 되지 않기 때문에 완전탐색으로 해결할 수 있다.
  2. 던전은 한 번밖에 들어가지 못하기에 used 배열을 이용하여 방문 여부를 체크한다.
  3. 혹시 K가 던전들의 최소 피로도를 만족하지 못할 때를 대비하여 방어코드를 설정한다.
*/
#include <string>
#include <vector>
using namespace std;

int MAX = -987654321;
int LEN = 0; int K = 0;
vector<vector<int>> v1;
vector<int>used;

void dfs(int count){
    if(count > MAX){
        MAX = count;
    }
    
    for(int i = 0; i<LEN; i++){
        if(K < v1[i][0]) continue;
        if(used[i] == 1) continue;
        K -= v1[i][1];
        used[i] = 1;
        
        dfs(count + 1);
        
        K += v1[i][1];
        used[i] = 0;
    }
     
    return;
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    //init
    K = k;
    LEN = dungeons.size();
    v1 = dungeons;
    used = vector<int>(LEN + 1, 0);
    
    //Get Max cnt
    dfs(0);
    
    if(MAX == -987654321){
        answer = 0;
    }
    else{
        answer = MAX;
    }
    
    return answer;
}
