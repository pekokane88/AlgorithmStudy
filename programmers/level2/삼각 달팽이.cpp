#include <string>
#include <vector>
using namespace std;

vector<vector<int>> temp;

vector<int> solution(int n) {
    vector<int> answer;
    
    temp = vector<vector<int>>(n, vector<int>(n, 0));
    //이걸 한쪽으로 밀어보자. 그러면 2차원 배열 계단형태가 된다.
    //따라서 뱡향벡터는 아래로 -> 가장 옆으로, -> 대각선 위로
    
    int totalCnt = 0;
    for(int i = 1; i<=n; i++){
        totalCnt += i;
    }
    
    int now = 1;
    int x = 0;
    int y = 0;
    temp[y][x] = now;
    while (now != totalCnt) {

        //down
        y += 1;
        while (temp[y][x] == 0) {
            now += 1;
            temp[y][x] = now;
            y += 1;
            if (y >= n or temp[y][x] != 0) {
                y -= 1;
                break;
            }
        }

        //right
        x += 1;
        while (temp[y][x] == 0) {
            now += 1;
            temp[y][x] = now;
            x += 1;
            if (x >= n or temp[y][x] != 0) {
                x -= 1;
                break;
            }
        }

        //side up
        x -= 1; y -= 1;
        while (temp[y][x] == 0) {
            now += 1;
            temp[y][x] = now;
            if (temp[y - 1][x - 1] == 0) {
                x -= 1; y -= 1;
            }
        }
    }
    
    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[i].size(); j++) {
            if(temp[i][j] != 0){
                answer.push_back(temp[i][j]);
            }
        }
    }
    
    return answer;
}
