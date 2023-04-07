#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> map(10001, vector<int>(10001, -1));
unordered_map<char, int> um{
    {'E', 0},
    {'W', 1},
    {'S', 2},
    {'N', 3},
};
int nowY = -1; int nowX = -1;
int dirY[4] = {0, 0, 1, -1};
int dirX[4] = {1, -1, 0, 0};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2, 0);
    
    for(int i = 0; i<park.size(); i++){
        for(int j = 0; j<park[i].size(); j++){
            if(park[i][j] == 'O') map[i][j] = 1;
            else if(park[i][j] == 'S'){
                nowY = i;
                nowX = j;
                map[i][j] = 1;
            }
        }
    }
    
    string temp = "";
    for(int i = 0; i<routes.size(); i++){
        char d = routes[i][0];
        char tmp = routes[i][2];
        temp += tmp;
        int n = stoi(temp);
        temp = "";
        
        int incY = dirY[um[d]] * n;
        int incX = dirX[um[d]] * n;
        
        int nextY = nowY + incY;
        int nextX = nowX + incX;
        
        //check map
        if(nextY < 0 || nextX < 0 || map[nextY][nextX] == -1) continue;
        
        //check X
        bool checkRockFlag = false;
        if(incY == 0){
            int smallX = min(nowX, nextX);
            int bigX = max(nowX, nextX);
            for(int i = smallX; i <= bigX; i++){
                if(map[nextY][i] == -1){
                    checkRockFlag = true;
                    break;
                }
            }
        }
        else if(incX == 0){
            int sY = min(nowY, nextY);
            int bY = max(nowY, nextY);
            for(int i = sY; i<=bY; i++){
                if(map[i][nextX] == -1){
                    checkRockFlag = true;
                    break;
                }
            }
        }
        
        if(checkRockFlag) continue;
        
        nowY = nextY;
        nowX = nextX;
    }
    
    answer[0] = nowY;
    answer[1] = nowX;
    
    return answer;
}
