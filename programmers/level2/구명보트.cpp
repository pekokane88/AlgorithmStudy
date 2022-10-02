/*
   중요! : 배에는 최대 2명까지만 탈 수 있다. 이를 잘 이용하여야 한다.
   1. 먼저 people 배열을 정렬한다.
   2. 가장 왼쪽인 people[start]은 최솟값이고 가장 오른쪽인 poeple[end] 은 최대값이다. 따라서 이 둘울 더했는데 limit 보다 넘는다면 end 인덱스의 사람은 
      무조건 혼자 배를 타야하기 때문에 인덱스를 end - 1 해주고, 배를 하나 증가시켜준다(배를 미리 태워보냄).
   3. 만약 people[start] + people[end] 가 limit보다 작거나 같다면 둘 다 배에 태워 보내면 된다. 그리고 start + 1, end -1 해준다.
   4. 이 과정을 계속 반복하면된다.
   5. 만약 모든 사람이 전부 탑승했다면 start와 end 값이 역전되게 되고 answer를 출력해주면 된다. 하지만 start == end라면 
      start 인덱스의 사람이 배를 타지 못한 것이기 때문에 마지막으로  answer + 1을 해준다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    int len = people.size();
    int start = 0;
    int end = len - 1;
    sort(people.begin(), people.end());
    
    while(start < end){
        int left = people[start];
        int right = people[end];
        if(left + right > limit){
            answer += 1;
            end -= 1;
        }
        else if(left + right <= limit){
            answer += 1;
            start += 1;
            end -=1;
        }
    }
    
    if(start == end) answer += 1;

    return answer;
}
