//map 에 각 토핑의 종류를 저장.
//두 size 를 비교하면 topping 의 종류가 같은지 비교 가능하다.
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int> me;
unordered_map<int,int> bro;

int solution(vector<int> topping) {
    int answer = 0;
    
    for(int i = 0; i < topping.size(); i++){
        if(bro.count(topping[i]) == 0){
            bro[topping[i]] = 1;
        }
        else{
            bro[topping[i]] += 1;
        }
    }
    
    for(int i = 0; i<topping.size(); i++){
        if(me.count(topping[i]) == 0){
            me[topping[i]] = 1;
        }
        else{
            me[topping[i]] += 1;
        }
        
        bro[topping[i]] -=1;
        if(bro[topping[i]] == 0){
            bro.erase(topping[i]);
        }
        
        if(me.size() == bro.size()) answer += 1; 
    }
    
    return answer;
}
