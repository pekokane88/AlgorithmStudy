#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
char direction[4] = {'u', 'r', 'd', 'l'};

struct Node{
    int R, C, K;
    string history = "";
};

//x, y -> 스타트 지점
//r, c -> 도착 지점
// k -> 무조건다써야함.
string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";

    vector<string> route;

    queue<Node> qu;
    qu.push({x,y,k});

    while(!qu.empty()){
        Node now = qu.front(); qu.pop();
        int nowRow = now.R; 
        int nowCol = now.C;
        int nowK = now.K;
        if(nowRow == r && nowCol == c && nowK == 0) route.push_back(now.history);

        for(int i = 0; i<4; i++){
            int nextRow = nowRow + dr[i];
            int nextCol = nowCol + dc[i];
            int nextK = nowK - 1;
            if(nextRow < 1 || nextCol < 1 || nextRow >= n+1 || nextCol >= m+1 ) continue;
            if(nextK < 0) continue;
            qu.push({nextRow, nextCol, nextK, now.history + direction[i]});
        }
    }

    sort(route.begin(), route.end());

    if(route.size() == 0) answer = "impossible";
    else answer = route[0];

    return answer;
}
