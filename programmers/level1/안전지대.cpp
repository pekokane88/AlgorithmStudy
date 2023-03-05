//방향배열을 이용하여 풀면 쉽게 구할 수 있다. 이 때 폭탄까지 제거해버리지 않도록 예외를 설정해두자.
#include <string>
#include <vector>

using namespace std;

int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1 };
int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[i].size(); j++){
            if(board[i][j] == 1){
                for(int k = 0; k<8; k++){
                    int nr = i + row[k];
                    int nc = j + col[k];
                    if(nr < 0 or nc < 0 or nr >= board.size() or nc >= board[i].size())continue;
                    if(board[nr][nc] == 1) continue;
                    board[nr][nc] = -1;
                }
            }
        }
    }
    
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[i].size(); j++){
            if(board[i][j] == 0) answer += 1;            
        }
    }
    
    return answer;
}
