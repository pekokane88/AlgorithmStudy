//DP 를 이용한 문제 -> 가장 최대의 합을 구할 수 있는 방법을 찾아야함.
//DP 를 이용하여 Max 합으로만 배열을 채워 나감.
//Max 함수는 '땅따먹기 게임에는 한 행씩 내려올 때, 같은 열을 연속해서 밟을 수 없는 특수 규칙' 을 위해서 연속해서 밟는 열을 체크하기 위하여 임의로 만듬.
#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> v1, int ban){
    int maxNum = -9999999;
    for(int i = 0; i<4; i++){
        if(ban == -1){
             if(maxNum < v1[i]){
                maxNum = v1[i];
            }
        }
        else{
             if(maxNum < v1[i] and i != ban){
                maxNum = v1[i];
            }
        }
    }
    return maxNum;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> dp = vector<vector<int>>(land.size(), vector<int>(4, 0));
    
    for(int i = 1; i<land.size(); i++){
        for(int j = 0; j<4; j++){
            int temp = land[i][j] + max(land[i - 1], j);
            land[i][j] = temp;
        }
    }
    
    answer = max(land[land.size() - 1], -1);
    
    // for(int i = 0; i<land.size(); i++){
    //     for(int j = 0; j<4; j++){
    //         cout << land[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return answer;
}
