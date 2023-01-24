// dfs 를 이용, depth 가 3일때 SU< 이 -이면 count를 1증가시켜준다.
// 조합을 이용하여 문제를 해결.(중복X, 순서X)
#include <string>
#include <vector>

using namespace std;

vector<int> v1;
vector<int> used;
int count = 0;
int sum = 0;

void dfs(int level, int index){
    if(level >= 3){
        if(sum == 0){
            count += 1;
        }
        return;
    }
    
    for(int i = index; i<v1.size(); i++){
        if(used[i] == 1) continue;
        sum += v1[i];
        used[i] = 1;
        
        dfs(level + 1, i + 1);
        
        sum -= v1[i];
        used[i] = 0; 
    }
}

int solution(vector<int> number) {
    int answer = 0;
    v1 = number;
    used = vector<int>(number.size(), 0);
    dfs(0, 0);
    
    answer = count;
    
    return answer;
}
