/*
  처음에 그냥 피보나치 수열 공식대로 구해서 배열에 전부 넣은 후 n번째 index 값을 % 해주면 된다고 생각하였으나, 기하급수적으로 커지는 값에 의해 overflow 발생 -> 실패
  따라서 피보나치 수열을 적용하고 n번째 index 에서 %연산을 하는 것이 아닌, %한 값을 n번째 index에 넣어주고 피보나치 수열을 적용하기로 하였다.
/*
#include <string>
#include <vector>

using namespace std;

long long arr[100001] = {0};

int solution(int n) {
    int answer = 0;
    
    int cnt = 2;
    arr[1] = 1;
    
    
    while(true){
        arr[cnt] = (arr[cnt - 1] + arr[cnt - 2]) % 1234567;
        cnt += 1;
        if(cnt == 100001) break;
    }
    
    answer = arr[n];
    
    return answer;
}
