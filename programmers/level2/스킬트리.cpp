/*
  스킬트리 또한 문자열 parsing 문제. 선행 스킬을 배우지 않으면 다음 스킬을 배우지 못한다.
  used 배열과 DAT를 이용하여 문제를 해결.
  1. 배열에 각 스킬의 선행조건을 입력
  2. 문자열을 탐색하며 선행조건을 배웠는지 검색하기 위해 used 배열을 체크하여 pass,  그렇지 않은 것이 존재한다면 더 볼 필요가 없기 때문에 바로 종료
  3. 끝까지 탐색하였을때 조건에 문제가 없다면 true flag 를 반환하며 answer 값을 1 올려준다.
*/
#include <string>
#include <vector>
using namespace std;

vector<char> v1(100, 0);
vector<int> used(100, 0);

int checkSkill(string str){
    int len = str.size();
    used = vector<int>(100, 0);
    
    for(int i = 0; i<len; i++){
        if(v1[str[i]] == 0) continue;
        else{
            if(v1[str[i]] == str[i]){
                used[str[i]] = 1;
            }
            else{
                if(used[v1[str[i]]] == 1){
                    used[str[i]] = 1;
                }
                else{
                    return 0;
                }
            }
        }
    }
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int len =  skill_trees.size();
    
    for(int i = 0; i<skill.size(); i++){
        if(i == 0){
             v1[skill[i]] = skill[i];
        }
        else{
           v1[skill[i]] = skill[i - 1]; 
        }
    }
    
    for(int i = 0; i<len; i++){
        string temp = skill_trees[i];
        if(checkSkill(temp)){
            answer += 1;
        }
    }
    
    return answer;
}
