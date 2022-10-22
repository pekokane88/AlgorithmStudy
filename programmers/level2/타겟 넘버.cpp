/*
  완탐의 기초. DFS 를 이용하여 풀었다. numbers 의 최고 길이는 20개 이기 때문에 2^20 을 해도 100만번 연산이다.
  따라서 완탐을 하여도 시간초과가 날 확률이 거의 없다.
  -1, +1 을 전부 해 나가며 배열을 전부 탐색하였을 때 합이 target과 같다면 cnt += 1을 해주고 return 해서 다시 탐색한다.
*/
#include <string>
#include <vector>
//방향벡터 -1 or + 1해서 하나씩 가면됨.
using namespace std;
vector<int> v1;
int len = 0;
int goal = 0;
int cnt = 0;
int sum = 0;
int arr[2] = {-1,1};

void dfs(int level){
    if(level >= len){
        if(sum == goal){
            cnt += 1;
        }
        return;
    }
    
    for(int i = 0; i<2; i++){
        sum += (arr[i] * v1[level]);
        
        dfs(level + 1);
        
        sum -= (arr[i] * v1[level]);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    v1 = numbers;
    len = numbers.size();
    goal = target;
    dfs(0);
    answer = cnt;
    
    return answer;
}
