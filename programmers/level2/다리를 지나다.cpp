#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> bridge;

    //time -> 시간
    //cur -> 현재 다리의 weight 같은데....
    int time = 0, cur = 0;

    for(int i = 0; i < truck_weights.size(); i++){
        time++;
        if(time == bridge.front().second + bridge_length){
            cur -= bridge.front().first;
            bridge.pop();
        }
        while(cur + truck_weights[i] > weight){
            time = bridge.front().second + bridge_length;
            cur -= bridge.front().first;
            bridge.pop();
        }
        cur += truck_weights[i];
        bridge.emplace(truck_weights[i], time);
    }

    time = bridge.back().second + bridge_length;

    return time;
}
