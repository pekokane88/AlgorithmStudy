#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int flag = 1;
    //지울 때 뒤에 숫자보다 더 작은 숫자는 지운다.
    while(flag){
        for(int i=1;i<number.length();i++){
            if(number[i-1] < number[i] && k >= 1){
                number.erase(i-1, 1);
                k--;
                if(k == 0)
                    flag = 0;

                break;
            }

            if(i == number.length()-1)
                flag = 0;
        }
    }

    while(k--){
        number.erase(number.length()-1, 1);
    }

    answer = number;
    return answer;
}
