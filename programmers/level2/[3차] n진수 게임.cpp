//16진법을 표현하기 위한 character 맵을 이용한다.
#include <string>
#include <vector>
using namespace std;

char chMap[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                 '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string transNum(int n, int k){
    string result = "";
    while(k != 0){
        int temp = k % n;
        k /= n;
        result = chMap[temp] + result;
    }
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int nowNum = 1;
    string tempStr = "";
    
    while(true){
        if(nowNum == t * m){
            break;
        }
        
        if(nowNum == 1){
            tempStr += "01";
        }
        else{
            tempStr += transNum(n, nowNum);
        }
        nowNum += 1;
    }
    
    int start = p;
    
    for(int i = 0; i<tempStr.size(); i++){
        if(i + 1 == start){
           answer += tempStr[i];
            start += m;
        }
        if(answer.size() == t) break;
    }
    
    return answer;
}
