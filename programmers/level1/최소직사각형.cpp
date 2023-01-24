// X,Y 중 더 긴 변을 한 쪽으로 몰아준다고 생각한다.
// 그 후 X, Y 길이들 중에 가장 최댓값을 골라서 반환한다.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> X;
vector<int> Y;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
  
    for(int i = 0; i<sizes.size(); i++){
        int lager = max(sizes[i][0], sizes[i][1]);
        int smaller = min(sizes[i][0], sizes[i][1]);
        
        X.push_back(lager);
        Y.push_back(smaller);
    }
    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    answer = X[X.size() - 1] * Y[Y.size() - 1];
    
    return answer;
}
