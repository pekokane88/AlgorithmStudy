//정말 쉬운 문제인데 평균에서 소수점이 나오는 부분을 생각하지 못하여 삽질을 하였다.
// 나눗셈할때 double 타입이 하나는 있어야 결과값을 double type으로 받을 수 있다.
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(a > b) return true;
        else if(a < b) return false;
        
        return false;
    }
};

vector<double> avg;
unordered_map<double, int> um;
priority_queue<double> pq;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;

    for(int i = 0; i<score.size(); i++){
        double num = ((double)(score[i][0] + score[i][1]) / 2);
        avg.push_back(num);
        pq.push(num);
        um[num] = -1;
    }
    
    int grade = 1;
    double beforeGrade = pq.top(); pq.pop();
    um[beforeGrade] = grade;
    
    while(!pq.empty()){
        double nowGrade = pq.top();pq.pop();
        if(nowGrade == beforeGrade){
            grade += 1;
        }
        else{
            grade += 1;
            um[nowGrade] = grade;
            beforeGrade = nowGrade;
        }
    }
    
    for(int i = 0; i<avg.size(); i++){
        answer.push_back(um[avg[i]]);
    }
    
    return answer;
}
