// 배열을 이용하여 최대 인용된 논문의 수보다 최소 인용된 논문의 수가 커지는 시점을 구한다.
// 만약에 최대 인용회수 혹은 논문의 수가 많아진다면, 해당 방법으로는 시간 복잡도 문제가 있을 . 
#include <string>
#include <vector>
using namespace std;

int arr[10001] = {0};

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i = 0; i<citations.size(); i++){
        for(int j = 0; j<=citations[i]; j++){
            arr[j] += 1;
        }
    }
    
    for(int i = 0; i<10001; i++){
        if(arr[i]  < i){
            answer = i - 1;
            break;
        }
    }
    
    return answer;
}
