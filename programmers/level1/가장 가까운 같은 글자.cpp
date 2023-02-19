//쉬운 문제인데 초기에 아무 생각없이 vector 의 원소를 0으로 초기화하여 삽질 하였다. 가장 처음 값이 0 번째 index 에 나올 수도 있다.
#include <string>
#include <vector>

using namespace std;
vector<int> bucket(200, -1);


vector<int> solution(string s) {
    vector<int> answer;
    
    answer = vector<int>(s.size(), -1);
    
    for(int i = 0; i<s.size(); i++){
        if(bucket[s[i]] == -1){
            bucket[s[i]] = i;
        }
        else if(bucket[s[i]] != -1){
            answer[i] = i - bucket[s[i]];
            bucket[s[i]] = i;
        }
    }
    
    return answer;
}
