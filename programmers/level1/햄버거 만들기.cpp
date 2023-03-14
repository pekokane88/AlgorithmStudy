//길이가 100만이기 때문에 시간 복잡도에 유의
//문자열로 변환하여 1231 을 찾고 지워준다. 이 때, 지운 후 그전에 1231이 있을 수도 있기 때문에 index 를 앞으로 옮기고 나서 다시 찾는 것이 중요하다.
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    string str = "";
    for(int i = 0; i<ingredient.size(); i++){
        str += to_string(ingredient[i]);
    }
    
    int start = 0;
    
    while(true){
        int index = str.find("1231", start);
        if(index == -1){
            break;
        }
        else{
            str.erase(index, 4);
            answer += 1;
            if(index > 2){
                start = index - 3;
            }
            else if(index > 1){
                start = index - 2;
            }
            else if (index > 0){
                start = index - 1;
            }
        }
    }
    
    return answer;
}
