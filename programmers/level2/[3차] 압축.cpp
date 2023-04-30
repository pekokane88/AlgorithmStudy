//단어를 하나씩 검사하며 이미 존재한다면 index 를 저장하고 넘어가고, 그렇지 않다면 단어를 추가하고 이전 저장 index 를 출력한다.
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> zip;
int lastIndex = 27;

void init(){
    int count = 1;
    for(char ch = 'A'; ch <= 'Z'; ch++){
        string tempStr = "";
        tempStr += ch;
        zip[tempStr] = count++;
    }
    return;
}

vector<int> solution(string msg) {
    vector<int> answer;
    init();
    
    int tempIndex = 0;
    string tempStr = "";
    for(int i = 0; i<msg.size(); i++){
        tempStr += msg[i];
        if(zip.count(tempStr) != 0){
            tempIndex = zip[tempStr];
        }
        else if(zip.count(tempStr) == 0){
            zip[tempStr] = lastIndex++;
            answer.push_back(tempIndex);
            tempStr = msg[i];
            tempIndex = zip[tempStr];
        }
    }
    
    answer.push_back(zip[tempStr]);
    
    return answer;
}
