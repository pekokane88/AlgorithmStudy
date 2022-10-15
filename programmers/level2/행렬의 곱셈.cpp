/*
  단순히 행렬의 곱셈 연산을 코드로 옮겨놓은 형태
  출력물의 Row,Col 은 arr1 의 Row X arr2 의 Col 형태로 나오게 된다.
*/
#include <string>
#include <vector>

using namespace std;

int R1, C1, R2, C2;
vector<vector<int>> MAP;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    R1 = arr1.size();
    C1 = arr1[0].size();
    R2 = arr2.size();
    C2 = arr2[0].size();
    MAP = vector<vector<int>>(R1, vector<int>(C2,0));
    
    for(int Y = 0; Y<R1; Y++){
        for(int X = 0; X<C2; X++){
            int sum = 0;
            for(int Y2 = 0; Y2<R2; Y2++){
                sum += (arr1[Y][Y2] * arr2[Y2][X]);
            }
            MAP[Y][X] = sum;
        }
    }
     
    answer = MAP;
    return answer;
}
