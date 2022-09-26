/*
  Greedy 알고리즘 이용.
  두 수를 곱해 누적값을 최소를 만들기 위해서는 무조건 작은 수 * 큰 수 의 짝을 만들어 나가야 한다.
  따라서 두 배열을 오름차순 정렬 후 A는 0번째 index 부터 B는 n번째 index 부터 연산해나간다.
*/
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int len = A.size();
    
    for(int i = 0; i<len; i++){
        answer += (A[i] * B[len -1 -i]);
    }
    
    return answer;
}
