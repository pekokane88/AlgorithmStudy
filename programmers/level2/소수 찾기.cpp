/*
  소수 찾기 + dfs + 중복 제거
  1. 우선 문자열을 이용해 단어를 만들기 위해 dfs를 이용한다.
  2. 그 후 만든 문자열을 숫자로 변환 후, 소수인지 확인한다.
  3. 중복으로 숫자가 나오는 것을 방지하기 위해 hash_map 을 이용한다.
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, int> um;
vector<int> check(9999999, 0);

string str;
int len;
char map[8] = {0};
int used[7] = {0};

bool checkPrimeNumber(int num){
    for(int i = 2; i*i<=num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

void dfs(int level){
    if(level >= 1){
        string temp = map;
        int target = stoi(temp);
        if(target != 0 && target != 1){
            if(checkPrimeNumber(target)){
                if(um.count(target) == 0){
                  um[target] = 1;
                }
                else{
                  um[target] += 1; 
                }
            }
        }
    }
    if(level >= len){
        return;
    }
    
    for(int i = 0; i<len; i++){
        if(used[i] != 0) continue;
        map[level] = str[i];
        used[i] = 1;
        
        dfs(level + 1);
        map[level] = 0;
        used[i] = 0;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    str = numbers;
    len = str.size();
    
    dfs(0);
    
    answer = um.size();
    
    return answer;
}
