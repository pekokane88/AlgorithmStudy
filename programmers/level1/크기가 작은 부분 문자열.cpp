//t 의 길이는 최대 10000, p의 길이는 최대 18
// 18자리의 숫자는 int 의 최대 값인 약 21억을 훨씬 넘는다.
// 무의식적으로 stoi 를 사용하여 에러가 발생하였다. stoi 에서 stoll(long long) 타입으로 변환하여 해결하였다. (변수의 자료형 유의!!)
// stoi -> string to int
// stod -> string to double
// stoll -> string to long long
// to_string -> num to string
#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    long long cmp = stoll(p);
    
    for(int i = 0; i<t.size() - p.size() + 1; i++){
        string temp = "";
        for(int j = 0; j<p.size(); j++){
            temp += t[i + j];
        }
        if(stoll(temp) <= cmp) answer += 1;        
    }
    return answer;
}
