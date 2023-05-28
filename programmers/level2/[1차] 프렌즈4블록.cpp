//블록의 제거 및 정렬 과정을 함수로 순차적으로 구현하면 어렵지 않게 해결이 가능하다.
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dirY[4] = {0, 0, 1, 1};
int dirX[4] = {0, 1, 0, 1};
int r = -1;
int c = -1;
queue<pair<int,int>> qu;
vector<vector<char>> MAP;
vector<vector<int>> CHECK;

//검사용 함수
void printMap(){
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

//4개가 있는가?
bool func1(int Y, int X){
    for(int i = 0; i<4; i++){
        int nY = Y + dirY[i];
        int nX = X + dirX[i];
        if(MAP[nY][nX] != MAP[Y][X]) return false;
    }
    return true;
}

//있다면 queue 에 일단 추가 후 일괄 제거 할 예정.
void func2(int Y, int X){
    for(int i = 0; i<4; i++){
        int nY = Y + dirY[i];
        int nX = X + dirX[i];
        if(CHECK[nY][nX] == 0){
            qu.push({nY, nX});
            CHECK[nY][nX] = 1;        
        }
    }
    return;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    r = m;
    c = n;
    MAP = vector<vector<char>>(r, vector<char>(c, 0));
    CHECK = vector<vector<int>>(r, vector<int>(c, 0));
    
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            MAP[i][j] = board[i][j];
        }
    }    
    
    while(true){
        //4개 블록 MAP 검사. 'X' 는 공백이라는 의미이기 때문에 검사하지 않는다.
        for(int i = 0; i<r-1; i++){
            for(int j = 0; j<c-1; j++){
                if(MAP[i][j] == 'X') continue;
                if(func1(i, j)){
                    func2(i, j);
                }
            }
        }
        
        //qu 가 비어있다면 더 이상 제거할 수 있는 블록이 없다는 의미.
        if(qu.empty()){
            break;
        }else{
            //qu가 있다면, qu 의 size(개수) 만큼 블록이 터짐.
            //중복 방지 용으로 사용한 CHECK MAP 초기화.
            answer += qu.size();
            CHECK = vector<vector<int>>(r, vector<int>(c, 0));
            //블록을 제거한 맵 최신화.
            while(!qu.empty()){
                pair<int,int> temp = qu.front(); qu.pop();
                MAP[temp.first][temp.second] = 'X';
            }
        }
        
        //MAP 정렬, 비어있는 자리에 블록 채우기.
        for(int x = 0; x < c; x++){
            queue<pair<int, int>> blank;
            for(int y = r - 1; y >= 0; y--){
                if(MAP[y][x] == 'X'){
                    blank.push({y, x});
                }else{
                    if(blank.empty()) continue;
                    else{
                        pair<int, int> savePoint = blank.front(); blank.pop();
                        MAP[savePoint.first][savePoint.second] = MAP[y][x];
                        MAP[y][x] = 'X';
                        blank.push({y, x});
                    }
                }
            }
        }
    }
    
    return answer;
}
