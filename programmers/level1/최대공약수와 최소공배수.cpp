#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;

    int gcd = 0;
    int x = n;
    int y = m;
    
    //유클리드 호법. x,y의 최대공약수는 y와  r(x%y)의 나머지가 0인 값과 같다.
    while(y){
        int temp = x;
        x = y;
        y = temp%y;
    }
    
    //최소 공배수 = (n * m) / 최대 공약수;
    answer.push_back(x);
    answer.push_back(n*m / x);
    
    return answer;
}
