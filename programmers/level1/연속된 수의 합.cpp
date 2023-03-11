// 맞는 방법인지는 잘 모르겠다...
#include <string>
#include <vector>
#include <queue>
using namespace std;

int bucket[1000000] = {0};
queue<int> qu;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    if(num == 1){
        answer.push_back(total);
        return answer;
    }
    
    int half = 0;
    
    if(total >= num){
        if(total % 2 == 0) half = total / 2;
        else half = (total / 2) + 1;    
    }
    else{
        if(num % 2 == 0) half = num / 2;
        else half = (num / 2) + 1;    
    }
    
    int sum = half;
    int count = 1;
    qu.push(half);
    
    while(true){
        sum += --half;
        count += 1;
        qu.push(half);
        if(count == num){
            if(sum == total){
                break;
            }
            else if(sum != total){
                count -= 1;
                sum -= qu.front(); qu.pop();
            }
        }
    }
    
    answer = vector<int>(qu.size(), 0);
    
    for(int i = qu.size() - 1; i >= 0; i--){
        answer[i] = qu.front(); qu.pop();
    }

    return answer;
}
