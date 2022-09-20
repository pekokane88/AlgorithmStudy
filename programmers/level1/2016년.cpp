/*
2016 1월 1일은 금요일. 8 15 22 29 , 36 금요일임. 2월로넘어감. 2월 5일 -> 따라서 7로 % 연산하였을 때 1이 나오면 금요일이 된다는 것을 알 수 있다.

월별 날짜 구성.
1,3,5,7,8,10,12  -> 31
2,4,6,9,11, -> 30
*/
#include <string>
#include <vector>

using namespace std;

vector<int> month = {0,31,29,31,30,31,30,31,31,30,31,30,31,};
vector<string> day = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

string solution(int a, int b) {
    string answer = "";
    
    int sum = 0;
    
    for(int i = 1; i<a; i++){
        sum += month[i];
    }
    
    sum += b;
    
    answer = day[sum % 7];
    
    return answer;
}
