#include <string>
#include <vector>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    //n 이 총 개수
    //a 가 가져다 줘야 하는 병의 개수
    //b 가 a개를 가져다 주면 돌려주는 병의 개수
    
    int now = n;
    
    while(now >= a){
        int getBottle = ((now/a) * b);
        int leftBottle = now % a;
        answer += getBottle;
        now = getBottle + leftBottle;
    }
    
    return answer;
}
