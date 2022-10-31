/*
  재귀의 기초. 탐색하면서 cnt 를 이용해 만들어진 단어에 번호를 붙여준다.
  해당 word 가 나오면 그 때의 number 를 기록해 둔 후, 이를 반환한다.
*/
#include <string>
#include <vector>
using namespace std;

char ch[6] = {"AEIOU"};
char used[6] = {0};
int cnt = 0;
string target = "";
int result = 0;

void dfs(int level){
    if(level >= 1){
        cnt += 1;
        if(used == target){
            result = cnt;
            return;
        }
    }
    if(level >= 5){
        return;
    }
    
    for(int i = 0; i<5; i++){
        used[level] = ch[i];
        
        dfs(level + 1);
        
        used[level] = 0;
    }   
    return;
}


int solution(string word) {
    int answer = 0;
    target = word;
    
    dfs(0);
    
    answer = result;
    
    return answer;
}
