//좌표와 함께 방향까지 저장해야 한다.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> path;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, -1, 1};
int nowY = 0;
int nowX = 0;

int solution(string dirs) {
    int answer = 0;
    
    for(int i = 0; i<dirs.size(); i++){
        if(dirs[i] == 'U'){
            int nextY = nowY + dirY[0];
            int nextX = nowX + dirX[0];
            if(nextY < -5 or nextX < -5 or nextY > 5 or nextX > 5) continue;
            vector<string> v1{to_string(nowY), to_string(nowX), "U"};
            vector<string> v2{to_string(nextY), to_string(nextX), "D"};
            bool flag1 = (find(path.begin(), path.end(), v1) == path.end()) ? true : false;
            bool flag2 = (find(path.begin(), path.end(), v2) == path.end()) ? true : false;
            if(flag1 and flag2){
                path.push_back(v1);
                path.push_back(v2);
                answer += 1;
            }
            nowY = nextY; nowX = nextX;
        }else if(dirs[i] == 'D'){
            int nextY = nowY + dirY[1];
            int nextX = nowX + dirX[1];
            if(nextY < -5 or nextX < -5 or nextY > 5 or nextX > 5) continue;
            vector<string> v1{to_string(nowY), to_string(nowX), "D"};
            vector<string> v2{to_string(nextY), to_string(nextX), "U"};
            bool flag1 = (find(path.begin(), path.end(), v1) == path.end()) ? true : false;
            bool flag2 = (find(path.begin(), path.end(), v2) == path.end()) ? true : false;
            if(flag1 and flag2){
                path.push_back(v1);
                path.push_back(v2);
                answer += 1;
            }
            nowY = nextY; nowX = nextX;
        }else if(dirs[i] == 'L'){
            int nextY = nowY + dirY[2];
            int nextX = nowX + dirX[2];
            if(nextY < -5 or nextX < -5 or nextY > 5 or nextX > 5) continue;
            vector<string> v1{to_string(nowY), to_string(nowX), "L"};
            vector<string> v2{to_string(nextY), to_string(nextX), "R"};
            bool flag1 = (find(path.begin(), path.end(), v1) == path.end()) ? true : false;
            bool flag2 = (find(path.begin(), path.end(), v2) == path.end()) ? true : false;
            if(flag1 and flag2){
                path.push_back(v1);
                path.push_back(v2);
                answer += 1;
            }
            nowY = nextY; nowX = nextX;
        }else if(dirs[i] == 'R'){
            int nextY = nowY + dirY[3];
            int nextX = nowX + dirX[3];
            if(nextY < -5 or nextX < -5 or nextY > 5 or nextX > 5) continue;
            vector<string> v1{to_string(nowY), to_string(nowX), "R"};
            vector<string> v2{to_string(nextY), to_string(nextX), "L"};
            bool flag1 = (find(path.begin(), path.end(), v1) == path.end()) ? true : false;
            bool flag2 = (find(path.begin(), path.end(), v2) == path.end()) ? true : false;
            if(flag1 and flag2){
                path.push_back(v1);
                path.push_back(v2);
                answer += 1;
            }
            nowY = nextY; nowX = nextX;
        }
    }
    
    return answer;
}
