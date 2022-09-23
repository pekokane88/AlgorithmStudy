/*
  각 스테이지의 실패율을 구하여야 한다.
  arr은 각 단계에서 클리어하지 못한 사람이 몇명인지 저장하는 배열, fail 은 각 단계에서 실패율을 저장할 배열.
  Node 구조체를 하나 만들어서 실패율과 스테이지 넘버를 묶어준다.
  그리고 Compare함수를 하나 만들어서 sort에 같이 넣어준다. compare 함수는 실패율은 내림차순, 스테이지는 오름차순으로 정렬되게 해준다.
  이 때, sort가 아닌 stable_sort를 사용한다면 2번째 비교문인 stageNumber 조건은 compare 함수에 넣어주지 않아도 된다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//각 스테이지의 번호를 실패율이 높은 순서로 정렬.

struct Node{
    double failRate;
    int stageNumber;
};

int arr[502] = {0};
double fail[502] = {0};

int compare(Node n1, Node n2){
    if(n1.failRate > n2.failRate) return 1; // 실패율은 내림차순
    else if(n1.failRate < n2.failRate) return 0;
    
    return (n1.stageNumber < n2.stageNumber); //인덱스는 오름차순
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<Node> bucket;
    int stageLength = stages.size();
    
    for(int i = 0; i<stageLength; i++){
        arr[stages[i]] += 1;
    }
    
    int tempNumber = stageLength;
    for(int i = 1; i<=N; i++){
        fail[i] = static_cast<double>(arr[i]) / tempNumber;
        tempNumber -= arr[i];
        bucket.push_back({fail[i], i});
    }
    
    sort(bucket.begin(), bucket.end(), compare);
    //stable_sort(bucket.begin(), bucket.end(), compare);
    
    for(int i = 0; i<N; i++){
        answer.push_back(bucket[i].stageNumber);
    }
    
    return answer;
}
