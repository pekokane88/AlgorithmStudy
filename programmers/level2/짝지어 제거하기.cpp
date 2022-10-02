/*
  문자열의 길이는 최대 100만이기에 for문을 이용해서 검사한다면 시간초과가 나올 것이다.
  따라서 입력을 받으면서 검사해준다.
  만약 새로 입력받는 것이 전의 입력받는 것과 같다면 전에 입력받은 것을 vectoer 에서 빼준다. 그리고 검사해야할 인덱스를 바꿔가면서 계속 확인해준다.
  마지막에 vecoter의 길이가 0이라면 전부 제거한 것이고, 아니라면 0을 출력한다.
*/
#include <iostream>
#include <vector>
#include<string>
using namespace std;

vector<char> v1;

int solution(string s)
{
    int answer = -1;

    int beforeLength = s.size();
    int cmpIndex = 0;
    
    if(beforeLength == 0) return 1;
    
    v1.push_back(s[0]);
    for(int i = 1; i<beforeLength; i++){
        if(v1[cmpIndex] == s[i]) {
            v1.pop_back();
            cmpIndex -= 1;
        }
        else{
            v1.push_back(s[i]);
            cmpIndex += 1;
        }
    }
    
    if(v1.size() == 0) return 1;
    else return 0;
    
    return answer;
}
