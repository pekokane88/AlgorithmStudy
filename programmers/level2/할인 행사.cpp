#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

queue<string> qu;
unordered_map<string, int> wantMap;
vector<int> numMap;

bool compareNumber(vector<int> origin){
    bool result = true;
    for(int i = 0; i<numMap.size(); i++){
        if(numMap[i] < origin[i]) return false;
    }
    return result;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    numMap = vector<int>(want.size(), 0);
    
    for(int i = 0; i<want.size(); i++){
        wantMap[want[i]] = i;
    }
    
    for(int i = 0; i<discount.size(); i++){
        if(wantMap.count(discount[i]) != 0){
            numMap[wantMap[discount[i]]] += 1;
        }
        qu.push(discount[i]);
        
        if(qu.size() == 10){
            if(compareNumber(number)) answer += 1;
            
            string temp = qu.front(); qu.pop();
            if(wantMap.count(temp) != 0){
                numMap[wantMap[temp]] -= 1;
            }
        }
    }
    
    return answer;
}
