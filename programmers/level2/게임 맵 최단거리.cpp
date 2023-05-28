//시작지점인 0,0 이 아닌 목표 지점인 R,C 로 부터 BFS 를 출발하면 더 쉽게 접근할 수 있다.
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> MAP;
vector<vector<int>> PATH;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, -1, 1};
int r = -1;
int c = -1;
queue<pair<int,int>> qu;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    r = maps.size();
    c = maps[0].size();
    MAP = maps;
    PATH = vector<vector<int>>(r, vector<int>(c, 0));
    
    //시작을 0,0 이 아닌 r,c 에서부터.
    qu.push({r-1, c-1});
    PATH[r-1][c-1] += 1;
    
    while(!qu.empty()){
        pair<int,int> now = qu.front(); qu.pop();
        int Y = now.first; int X = now.second;
        
        for(int i = 0; i<4; i++){
            int nY = Y + dirY[i];
            int nX = X + dirX[i];
            
            if(nY < 0 or nX < 0 or nY >= r or nX >= c) continue;
            if(MAP[nY][nX] == 0) continue;
            if(PATH[nY][nX] == 0){
                qu.push({nY, nX}); PATH[nY][nX] = PATH[Y][X] + 1;
            }else{
                if(PATH[nY][nX] > PATH[Y][X] + 1){
                    qu.push({nY, nX}); PATH[nY][nX] = PATH[Y][X] + 1;
                }else{
                    continue;
                }
            }
        }
    }
    
    if(PATH[0][0] == 0) return -1;
    answer = PATH[0][0];
        
    return answer;
}
