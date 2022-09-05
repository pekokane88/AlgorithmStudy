#include <string>
#include <vector>

using namespace std;

vector<int> bucket;

int findFirstIndex(int col, vector<vector<int>> board){
    int boardSize = board.size();
    for(int i = 0; i<boardSize; i++){
        if(board[i][col] != 0) return i;
    }
    return -1;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int movesLength = moves.size();
    int boardSize = board.size();
    
    for(int i = 0; i<movesLength; i++){
        int firstRow = findFirstIndex(moves[i]-1, board);
        if(firstRow != -1){
            bucket.push_back(board[firstRow][moves[i]-1]);
            board[firstRow][moves[i]-1] = 0;
        }
        if(bucket.size() >= 2){
            if(bucket[bucket.size()-1] == bucket[bucket.size() -2]){
                bucket.pop_back();
                bucket.pop_back();
                answer += 2;
            }
        }
    }
    
    return answer;
}
