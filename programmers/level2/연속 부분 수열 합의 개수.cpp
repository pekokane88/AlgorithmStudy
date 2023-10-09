//map 을 이용하여 중복된 수 검사.
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um;

int solution(vector<int> elements) {
    int answer = 0;
    int listSize = elements.size();
    
    for(int i = 0; i<listSize; i++){
        int tempSum = 0;
        for(int j = 0; j<listSize; j++){
            tempSum += elements[(i + j) % listSize];
            um[tempSum] += 1;
        }
    }

    answer = um.size();
    return answer;
}
