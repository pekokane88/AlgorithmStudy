// unordered_map -> 해당 card 뭉치에 해당 단어가 있는지 바로 확인하기 위한 용도
// card1,2 -> 카드를 순서대로 빼기 위한 vector
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um1;
unordered_map<string, int> um2;

vector<string> card1;
vector<string> card2;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    for(int i = cards1.size() - 1; i >= 0; i--){
        um1[cards1[i]] = 1;
        card1.push_back(cards1[i]);
    }
    
    for(int i = cards2.size() - 1; i >= 0; i--){
        um2[cards2[i]] = 1;
        card2.push_back(cards2[i]);
    }
    
    for(int i = 0; i<goal.size(); i++){
        if(um1[goal[i]]){
            if(card1[card1.size() -1] == goal[i]){
                card1.pop_back();
            }
            else{
                return "No";
            }
        }
        else if(um2[goal[i]]){
            if(card2[card2.size() - 1] == goal[i]){
                card2.pop_back();
            }
            else{
                return "No";
            }
        }
    }
    
    return answer;
}
