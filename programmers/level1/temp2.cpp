#include <iostream>
#include <string>
#include <vector>

using namespace std;

//today 오늘 날짜
//terms 약관종류 및 기간
//pri 계약 날짜 + 종류 

int dateLength;
int termsLength;
vector<int> cmpDate;
char cmpPrivacy;
int termBucket[100] = {0};
int todayYear = 0;
int todayMonth = 0;
int todayDay = 0;

vector<int> parsingDate(string date){
    vector<int>result;
    string temp = "";

    for(int i = 0; i<dateLength; i++){
        if(date[i] == '.'){
            result.push_back(stoi(temp));
            temp = "";
        }
        else if(i == dateLength - 1){
            temp += date[i];
            result.push_back(stoi(temp));
        }
        else{
            temp += date[i];
        }
    }
    return result;
}

void findTerm(vector<string> v1){
    char tempP;
    string temp = "";
    int term = 0;
    for(int i = 0; i<termsLength; i++){
        int termLen = v1[i].size();
        tempP = v1[i][0];
        for(int j = 2; j<termLen; j++){
            temp += v1[i][j];
        }
        term = stoi(temp);
        termBucket[tempP] = term;
        temp = "";
    }
    return;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    dateLength = today.size(); // 날짜 고정 길이
    int priSize = privacies.size();
    int privacyLength = privacies[0].size();
    termsLength = terms.size();

    vector<int> now;
    now = parsingDate(today);
    todayYear = now[0];
    todayMonth = now[1];
    todayDay = now[2];

    findTerm(terms);

    for(int i = 0; i<priSize; i++){
        //비교해야할 약관들의 날짜, 약관 구함.
        cmpDate = parsingDate(privacies[i]);
        int cmpYear = cmpDate[0];
        int cmpMonth = cmpDate[1];
        int cmpDay = cmpDate[2];
        cmpPrivacy = privacies[i][privacyLength - 1];

        int term = termBucket[cmpPrivacy];
        int termY = term / 12; // 년 으로 구할 수 있고,
        int termM = term % 12; //  12로 나눈 나머지를 구할 수 있음.

        cmpYear += termY;
        cmpMonth += termM;

        if(cmpMonth > 12){
            cmpYear += 1;
            cmpMonth -= 12;
        }

        if(cmpDay == 1){
            cmpDay = 28;
            cmpMonth -= 1;
        }
        else cmpDay -= 1;

        if(todayYear < cmpYear) continue;
        else if(todayYear > cmpYear) answer.push_back(i + 1);
        else{
            if(todayMonth > cmpMonth) answer.push_back(i + 1);
            else if(todayMonth == cmpMonth){
                if(todayDay > cmpDay) answer.push_back(i + 1);
            }
        }

    }

    return answer;
}
