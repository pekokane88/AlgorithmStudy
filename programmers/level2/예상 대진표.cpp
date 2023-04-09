using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    int now = n;
    
    while(now != 0){
        answer += 1;
        int half = now/2;
        if((a <= half && b <= half) or (a >= half && b >= half)){
            if(a % 2 == 1){
                a += 1;
            }
            if(b % 2 == 1){
                b += 1;
            }
            
            if(a == b){
                return answer;
            }
            else{
                a /= 2;
                b /= 2;
            }
        }
        else{
            if(a % 2 == 1){
                a += 1;
            }
            if(b % 2 == 1){
                b += 1;
            }
            a /= 2;
            b /= 2;
        }
    }

    return answer;
}
