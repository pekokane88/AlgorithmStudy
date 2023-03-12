// map 을 돌며 최소 및 최대 X , Y 좌표를 구해준다.
//드래그는 map 을 감싸줘야하기 때문에 max 값에서 +1 씩 해준다.
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int minX = 987654321;
    int minY = 987654321;
    int maxX = -987654321;
    int maxY = -987654321;
    
    
    for(int i = 0; i<wallpaper.size(); i++){
        for(int j = 0; j<wallpaper[i].size(); j++){
            if(wallpaper[i][j] == '#'){
                if(minX > j) minX = j;
                if(minY > i) minY = i;
                
                if(maxX < j) maxX = j;
                if(maxY < i) maxY = i;
            }
        }
    }
    
    answer.push_back(minY);
    answer.push_back(minX);
    answer.push_back(maxY + 1);
    answer.push_back(maxX + 1);
    
    return answer;
}
