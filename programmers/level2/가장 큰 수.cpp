//정수를 문자열로 변경하여 최대한 큰 수를 만든다.
//이 때 수를 어떻게 배치하여야 가장 큰 수가 나오는지 비교 함수를 하나 생성해서 정렬을 해준다. -> 두 문자열을 합쳤을 때 더 큰 문자열을 만들 수 있도록
//모든 원소가 0 일 때 출력은 "0"으로 나와야 한다는 사실에 주의하자.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v1;

bool checkAllZero(string str){
    for(int i = 0; i<str.size(); i++){
        if(str[i] != '0') return false;
    }
    return true;
}

bool compare(string str1, string str2){
    string cmp1 = str1 + str2;
    string cmp2 = str2 + str1;
    
    if(cmp1 < cmp2) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    int len = numbers.size();
    for (int i = 0; i < len; i++) {
        v1.push_back(to_string(numbers[i]));
    }
    
    sort(v1.begin(), v1.end(), compare);
    //stable_sort(v1.begin(), v1.end(), compare);
    
    for(int i = v1.size() - 1; i >= 0; i--){
        answer += v1[i];
    }
    
    if(checkAllZero(answer)) answer = "0";
    
    return answer;
}
