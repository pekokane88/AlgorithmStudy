/*
  1. 먼저 최대 나올 수 있는 3000까지의 수에서 모든 소수를 구한다.
  2. 3개의 수를 골라 얻을 수 있는 모든 조합의 가지 수를 구한다.
  3. 이 때 그 수가 소수라면 Cnt 를 1증가 시킨다.(arr에는 소수만 1로 되어있기 때문에 이것으로 판별 가능)
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> arr(3001, 1);
vector<int> used;
vector<int> numList;
int len = 0;
int sum = 0;
int cnt = 0;

void findPrimeNumber(void) {
    for (int i = 2; i * i <= 3000; i++) {
        if (arr[i] == 1) {
            int temp = i;
            while (temp <= 3000 - i) {
                temp += i;
                arr[temp] = 0;
            }
        }
    }
    return;
}

void dfs(int level, int index){
    
    if(level >= 3){
        if(arr[sum] == 1){
            cnt++;
        }
        return;
    }
    
    for(int i = index; i<len; i++){
        if(used[i] != 0) continue;
        sum += numList[i];
        used[i] = 1;
        
        dfs(level + 1, i + 1);
        
        sum -= numList[i];
        used[i] = 0;
    }

    return;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    sort(nums.begin(), nums.end());
    numList = nums;
    len = nums.size();
    used = vector<int>(len+1, 0);
    findPrimeNumber();
    dfs(0, 0);
    
    answer = cnt;

    return answer;
}
