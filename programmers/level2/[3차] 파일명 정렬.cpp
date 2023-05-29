//sort 대신 stable_sort 를 사용해야 한다.
//stable_sort 와 sort 의 가장 큰 차이점은 stable_sort 는 우선 순위가 같은 원소의 상대적인 위치를 보장해준다고 한다.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> func(string str){
    int index = 0;
    string head = "";
    string num = "";
    vector<string> result;
    for(int i = 0; i<str.size(); i++){
        if(str[i] >= '0' and str[i] <= '9'){
            index = i;
            break;
        }else{
            head += toupper(str[i]);
        }
    }
    
    for(int i = index; i<str.size(); i++){
        if(str[i] >= '0' and str[i] <= '9'){
            num += str[i];
        }else{
            break;
        }
    }
    result.push_back(head);
    result.push_back(num);
    return result;
}

bool compare(string s1, string s2){
    vector<string> str1 = func(s1);
    vector<string> str2 = func(s2);
    string head1 = str1[0]; string head2 = str2[0];
    int num1 = stoi(str1[1]); int num2 = stoi(str2[1]);
    
    if(head1 < head2) return true;
    else if(head1 > head2) return false;
    
    if(num1 < num2) return true;
    else return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    stable_sort(files.begin(), files.end(), compare);

    answer = files;
        
    return answer;
}
