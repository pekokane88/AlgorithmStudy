#include <string>
#include <vector>
#include <cmath>
using namespace std;

//N으로부터 K진수를 구하는 함수
string getNumber(int n, int k){
    string result = "";
    while(n != 0){
        int tempNum = n % k;
        result = to_string(tempNum) + result;
        n /= k;
    }
    return result;
}

//해당 수가 소수인지 판별하는 함수
bool checkPrime(long num){
    if(num == 1) return false;
    for(int j = 2; j <= sqrt(num); j++){
        if(num % j == 0){
            return false;
        }        
    }
    return true;
}

//K
int checkNumber(string str){
    int result = 0;
    string tempStr = "";
    
    for(int i = 0; i<str.size(); i++){
        if(str[i] != '0'){
            tempStr += str[i];
        }
        else if(str[i] == '0'){
            if(tempStr.size() == 0) continue;
            
            long myNum = stol(tempStr);
            if(checkPrime(myNum)) result += 1;
            tempStr = "";
        }
    }
    
     if(tempStr != ""){
            if(checkPrime(stol(tempStr))){
                result += 1;
            }
        }
    
    return result;
}

int solution(int n, int k) {
    int answer = -1;
    string strNum = getNumber(n, k);
    answer = checkNumber(strNum);
    
    return answer;
}
