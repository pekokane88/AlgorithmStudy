//앞에서부터 두 수의 최대공약수를 구하고, 이를 위해 최소공배수를 구한다.
//이 과정을 반복해나가면 N개의 최소공배수를 구할 수 있다.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getGCD(int n1, int n2){
    while(n2 != 0){
        int temp = n1;
        n1 = n2;
        n2 = temp % n2;    
    }
    return n1;    
}

int solution(vector<int> arr) {
    int answer = 1;
    
    sort(arr.begin(), arr.end());
    
    int index = 0;
    while(arr[index] == 0 or arr[index] == 1){
        index += 1;
    }
    
    answer = arr[index++];
    
    for(int i = index; i<arr.size(); i++){
        int gcd = getGCD(answer, arr[i]);
        answer *= (arr[i] / gcd);
    }
    
    return answer;
}
