#include <string>
#include <vector>

using namespace std;

unsigned long long solution(int balls, int share) {
    unsigned long long answer = 0;
    
    if(balls == share){
        return 1;
    }
    
    int diff = balls - share;
    int count = 1;
    unsigned long long ans = 1;
    if(diff >= share){
        for(int i = balls; i>diff; i--){
            ans *= i;
            ans /= count;
            count += 1;
        }
    }
    else{
        for(int i = balls; i>share; i--){
            ans *= i;
            ans /= count;
            count += 1;
        }
    }
    
    answer = ans;
    
    return answer;
}
