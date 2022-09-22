/*
  map은 3차원 배열. map[row][col][z] ->  z축은 하나의 지도를 의미함. ex) z=2는 2번 지도를 의미.
  arr에 있는 수를 이용해 우선 각 map 배열을 완성.
  그 후, 1,2 지도를 비교하여 3번 지도를 만들고 그 상태를 확인하여 answer 배열을 완성시켜주면 된다. 
*/
#include <string>
#include <vector>

using namespace std;

int map[17][17][4] = {0};

void makeMap(int input, int index, int row, int z){
    int start = index-1;
    int num = input;
    while(start >= 0){
        if(num > 0){
            int tempNum = num % 2;
            num = num / 2;
            map[row][start][z] = tempNum;
        }
        else{
            map[row][start][z] = 0;
        }
        start -= 1;
    }
    return;
}

void compareMap(int N){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(map[i][j][1] == 1 || map[i][j][2] == 1) map[i][j][3] = 1;
            else map[i][j][3] = 0;
        }
    }
    return;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i<n; i++){
        makeMap(arr1[i], n, i, 1);
        makeMap(arr2[i], n, i, 2);
    }
    
    compareMap(n);
    
    for(int i = 0; i<n; i++){
        string temp = "";
        for(int j = 0; j<n; j++){
            if(map[i][j][3] == 1) temp += "#";
            else temp += " ";
        }
        answer.push_back(temp);
    }
    
    return answer;
}
