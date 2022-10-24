/*
  문제 자체는 어렵지 않았으나, 단계를 나눠서 하려다 보니 구현이 길어졌다.
  문제를 읽어가며 하나씩 구현해가면 충분히 할 수 있을 듯 하다.
  1. records 배열을 탐색하며 각 문자열을 parsing
  2. IN일때
     - 처음 들어온 값이면 unordered_map 에 init 해준다.
     - 처음 들어온 값이 아니라면 다시 들어왔다 체크해주고, 입차 시간 체크
  3. Out 일때는 출차시간에서 입차시간을 빼 그 시간만큼의 차이를 계산해준다.
  4. 이렇게 전부 탐색 후, 아직 출차를 하지 않은 차를 체크하여 총 시간을 계산한다.
  5. 총 시간을 계산 후, 이를 요금 단위로 환산한다. (올림을 하기 위해서 double로 강제 형 변환을 해주었다.)
  6. 그 후, 차 번호가 적은 것 부터 answer에 넣어주기 위하여 pq(차 번호 오름차순 정렬)를 이용하여 answer에 차례대로 넣어주었다.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>
using namespace std;

//시간은 그냥 더해서 빼면됨.
int base_time, base_fees, per_minute, per_fees;
unordered_map<string, pair<int,int>> um1; // in, out check and fee check
unordered_map<string, pair<string,string>> um2; // time check
vector<string> Records;
string record[3];
priority_queue<pair<string,int>, vector<pair<string,int>>, greater<pair<string,int>>> pq;

void parseRecord(string str){
    int len = str.size();
    int idx = 0;
    
    string temp = "";
    for(int i = 0; i<len; i++){
        if(str[i] == ' '){
            record[idx] = temp;
            temp = "";
            idx += 1;
        }
        else if(i == len - 1){
            temp += str[i];
            record[idx] = temp;
        }
        else{
            temp += str[i];
        }
    }
    return;
}

void calcFee(string str){
    int inHour = stoi(um2[str].first.substr(0, 2));
    int outHour = stoi(um2[str].second.substr(0, 2));
    int inMinute = stoi(um2[str].first.substr(3, 2));
    int outMinute = stoi(um2[str].second.substr(3,2));
    
    int diffHour = (outHour - inHour) * 60;
    int diffMinute = 0;
    if(outMinute < inMinute){
        diffMinute = (outMinute + 60) - inMinute;
        diffHour -= 60;
    }
    else{
        diffMinute = outMinute - inMinute;
    }
    um1[str].first += (diffHour + diffMinute);
    return;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    Records = records;
    base_time = fees[0];
    base_fees = fees[1];
    per_minute = fees[2];
    per_fees = fees[3];
    
    int len = Records.size();
    
    for(int i = 0; i<len; i++){
        parseRecord(Records[i]); //record에 파싱 값 삽입.
        if(record[2] == "IN"){
            if(um1.count(record[1]) != 0){
                um1[record[1]].second = 1;
                um2[record[1]].first = record[0];
            }
            else{
                um1[record[1]] = {0, 1};
                um2[record[1]].first = record[0];
            }
        }
        else if(record[2] == "OUT"){
            um1[record[1]].second = 0; //출차 체크
            um2[record[1]].second = record[0];
            calcFee(record[1]);
        }
    }
    
    for(auto it=um1.begin(); it != um1.end(); ++it){
        if(it->second.second == 1){
            it->second.second = 0;
            um2[it->first].second = "23:59";
            calcFee(it->first);
        }
        
        if(it->second.first <= base_time){
            it->second.first = base_fees;
        }
        else{
            it->second.first = base_fees + ceil((double)(it->second.first-base_time)/per_minute) * per_fees;
        }
    }
    
    for(auto it=um1.begin(); it != um1.end(); ++it){
        pq.push({it->first, it->second.first});
    }
    
    while(!pq.empty()){
        pair<string, int> temp = pq.top(); pq.pop();
        answer.push_back(temp.second);
    }
    
    return answer;
}
