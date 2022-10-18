/*
  Queue의 구조에 대해 알고 있다면 그렇게 어렵지 않은 문제.
  앞의 기능의 개발 진행이 100퍼센트가 되어야만 뒤의 기능을 배포할 수 있다.
  따라서 Queue를 이용해 가장 앞의 기능이 100퍼센트인지 검사해가면서 배포 개수를 answer에 추가해주면 된다.
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int>> qu;
vector<int> result;

void DoProgress(void) {
    for (int i = 0; i < qu.size(); i++) {
        pair<int, int> temp = qu.front(); qu.pop();
        qu.push({ temp.first + temp.second, temp.second });
    }
    return;
}

void DoPatch(void) {
    int cnt = 0;
    while(!qu.empty()) {
        pair<int, int> temp = qu.front();
        if (temp.first >= 100) {
            cnt += 1;
            qu.pop();
        }
        else {
            result.push_back(cnt);
            return;
        }
    }
    result.push_back(cnt);
    return;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    
    for (int i = 0; i < progresses.size(); i++) {
        qu.push({ progresses[i], speeds[i] });
    }

    while (!qu.empty()) {
        DoProgress();
        pair<int, int> temp = qu.front();
            if (temp.first >= 100) {
                DoPatch();
            }
    }
    
    answer = result;
    
    return answer;
}
