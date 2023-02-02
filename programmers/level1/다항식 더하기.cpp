//마지막에 다항식 경우의 수를 어떻게 해줄까 하다가 그냥 생각나는 대로 다 적어버렸다... 조금 더 좋은 방법이 있을듯 하다.
#include <string>
#include <vector>
using namespace std;

string solution(string polynomial) {
    string answer = "";
    
    string str = polynomial;
    
    int xNum = 0;
    int num = 0;
    string tempNum = "";
    
    for(int i = 0; i<str.size(); i++){
        if(str[i] == ' ') continue;
        else{
            if(str[i] >= '0' and str[i] <= '9'){
                tempNum += str[i];
            }
            else if(str[i] == 'x'){
                if(tempNum.size() == 0) xNum += 1;
                else{
                    xNum += stoi(tempNum);
                    tempNum = "";
                }
            }
            else if(str[i] == '+'){
                if(tempNum.size() != 0){
                    num += stoi(tempNum);
                    tempNum = "";
                }
            }
        }
    }
    
    if(tempNum.size() != 0){
        num += stoi(tempNum);
    }
    
    if(num == 0 and xNum == 0) return "0";
    
    if(num == 0 and xNum != 1)return to_string(xNum) + 'x';
    else if (num == 0 and xNum ==1) return "x";
    
    if(xNum == 0) return to_string(num);
    
    if(xNum == 1) return "x + " + to_string(num);
    return to_string(xNum) + "x + " + to_string(num);
    
}
