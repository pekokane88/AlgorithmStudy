/*
  구현 자체는 별 것 없으나, 아이디어를 생각하는 과정이 어려웠다.
  어떠한 전화번호가 다른 전화번호의 접두사가 된다면 false 를 반환하고, 그렇지 않다면 true를 반환한다.
  1. phone_book을 오름차순으로 정렬한다.
  2. 1중 for문을 돌면서 i가 i + 1의 접두사에 해당하는지 확인한다.
  3. 2번이 성립하는 이유는 정렬이 되어있기 때문이다. 여기서 숫자의 크기로 정렬된다고 생각하면 안되고 문자열 정렬이기 때문에 사전순으로 정렬이 된다. ("1"~"9" 순서)
     따라서 연속된 i와 i+1 에서 포함이 되지 않는다면 그 뒤는 더 볼 것이 없기 때문에 아래와 같은 코드가 성립될 수 있다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i<phone_book.size() - 1; i++){
            if(phone_book[i + 1].find(phone_book[i]) == 0){
                return false;
            }
    }
    
    return answer;
}
