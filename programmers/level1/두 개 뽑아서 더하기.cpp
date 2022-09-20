/*
  numbers의 최대 길이는 100, 따라서 2중 for문을 해도 최대 만 번 탐색하기 때문에 시간 초과 날 확률이 적다.
  bucket 배열을 이용하여 0 ~ 200 까지 두 수를 더한 값을 인덱스로 사용하여 그 곳의 값을 증가시켜준다.
  마지막으로 bucket[i] 가 0이 아닌 인덱스를 answer 에 추가시켜주면 자연스럽게 오름차순으로 값이 채워진다.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> bucket(201, 0);

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    int len = numbers.size();
    
    for(int i = 0; i<len; i++){
        int sum = 0;
        for(int j = i; j<len; j++){
            if(i == j) continue;
            bucket[numbers[i] + numbers[j]]++;
        }
    }
    
    for(int i = 0; i<201; i++){
        if(bucket[i] != 0) answer.push_back(i);
    }
    
    return answer;
}
