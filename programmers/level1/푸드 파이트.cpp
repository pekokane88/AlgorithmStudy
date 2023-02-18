// 2로 나눈 몫이 2보다 크지 않으면 대회에 사용하지 못함.
#include <string>
#include <vector>

using namespace std;
string left = "";
string right = "";

string solution(vector<int> food) {
    string answer = "";
    
    int len = food.size();
    for(int i = 1; i<len; i++){
        if(food[i] / 2 < 1) continue;
        int count = food[i] / 2;
        for(int j = 0; j<count; j++){
            left += to_string(i);
            right = to_string(i) + right;
        }
    }
    
    answer = left + "0" + right;
    
    return answer;
}
