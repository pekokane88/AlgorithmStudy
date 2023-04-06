//순위와 이름을 매칭해둔 map 과 vecoter 를 이용하여 현재 순위를 계속 갱신해 나간다.
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    for(int i = 0; i<players.size(); i++){
        um[players[i]] = i;
    }
    
    for(int i = 0; i<callings.size(); i++){
        int nowRank = um[callings[i]];
        string beforePlayer = players[nowRank - 1];
        players[nowRank] = beforePlayer;
        players[nowRank - 1] = callings[i];
        um[callings[i]] = nowRank - 1;
        um[beforePlayer] = nowRank;
    }
    
    answer = players;
    
    return answer;
}
