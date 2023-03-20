//greedy 이용해 앞에서부터 채워 나간다.
//이 때 주의점은 브러쉬의 최대 길이는 100000이기 때문에 배열의 길을 여유롭게 잡아준다.
#include <string>
#include <vector>
using namespace std;

vector<int> wall;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    wall = vector<int>(200001, 1);
    
    for(int i = 0; i<section.size(); i++){
        wall[section[i]] = 0;
    }
    
    for(int i = 1; i<=n; i++){
        if(wall[i] == 0){
            for(int j = i; j< i + m; j++){
                wall[j] = 1;
            }
            answer += 1;
        }
    }
    
    return answer;
}
