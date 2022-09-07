/*
  count만큼 반복문을 돌면서 총 비용을 구한다.
  그 후 총 비용이 소지 돈보다 크다면 그 차를 반환해주고, 그것이 아니라면 0을 반환한다.
*/
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long allCost = 0;
    
    for(int i = 1; i<= count; i++){
        allCost += (price * i);
    }
    
    long long diff = allCost - money;
    
    if(diff > 0) answer = diff;
    else answer = 0;

    return answer;
}
