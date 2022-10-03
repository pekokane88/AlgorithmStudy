/*
  1. people이라는 bucket 배열을 하나생성하여 전부 체육복을 1개씩 가지고 있다고 초기화.
  2. lose 와 reserve를 이용하여 people 배열의 체육복 갱신
  3. for 문을 돌면서 체육복이 없으면 왼쪽부터 여벌 체육복이 있는지 검사. 있다면 빌려주고 갱신
  4. 마지막에 people 배열을 탐색하여 체육복이 1개 이상있는 사람의 수를 answer 에 더해준다.
*/
#include <string>
#include <vector>
using namespace std;

int lostLength, resLength;
vector<int> people(31, 1);

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    lostLength = lost.size();
    resLength = reserve.size();
    
    for(int i = 0; i<lostLength; i++){
        people[lost[i]] -= 1;
    }
    for(int i = 0; i<resLength; i++){
        people[reserve[i]] += 1;
    }
    
    for(int i = 1; i<=n; i++){
        if(people[i] == 0){
            if(i - 1 >= 1 && people[i - 1] == 2){
                people[i - 1] -= 1;
                people[i] = 1;
            } 
            else if(i + 1 <= n && people[i + 1] == 2){
                people[i + 1] -= 1;
                people[i] = 1;
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        if(people[i] != 0) answer += 1;
    }
    
    return answer;
}
