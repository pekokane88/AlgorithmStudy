/*
  문자열을 parsing 해가며 튜플을 구성하고 있는 원소들을 추출해 나간다.
*/
#include <string>
#include <vector>

using namespace std;

int len = 0;
vector<int> Bucket(100001, 987654321);
vector<int> result(501, 0);

void func(string str, int cnt) {
    int len = str.size();
    string temp = "";
    for (int i = 0; i < len; i++) {
        if (str[i] != ',') {
            temp += str[i];

        }
        else if (str[i] == ',') {
            int tmpNum = stoi(temp);
            if (Bucket[tmpNum] >= cnt) {
                Bucket[tmpNum] = cnt;
            }
            temp = "";
        }

        if (i == len - 1) {
            int tmpNum = stoi(temp);
            if (Bucket[tmpNum] >= cnt) {
                Bucket[tmpNum] = cnt;
            }
        }
    }
    return;
}

vector<int> solution(string s) {
    vector<int> answer;

    len = s.size();

    string temp = "";
    int commaCnt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '{') continue;
        else if (s[i] == '}') {
            if (temp == "") continue;
            else {
                func(temp, commaCnt + 1);
                temp = "";
                commaCnt = 0;
            }
        }
        else if (s[i] == ',') {
            if (temp == "") continue;
            else {
                commaCnt += 1;
                temp += s[i];
            }
        }
        else temp += s[i];
    }
    
    for (int i = 0; i < 100001; i++) {
        if (Bucket[i] != 987654321) {
            result[Bucket[i] - 1] = i;
        }
    }
    
    for(int i = 0; i<501; i++){
        if(result[i] == 0) break;
        answer.push_back(result[i]);
    }
    
    return answer;
}
