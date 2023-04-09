#include <iostream>
#include <queue>
using namespace std;

struct cmp{
  //기존 pq 의 오름차순 정렬
  bool operator()(int n1, int n2){
    // 클 수록 우선 순위를 높게 주겠다는 의미.
    if(n1 > n2){
      return true;
    }
    else{
      return false;
    }
  }
}

priority_queue<int, vector<int>, cmp> pq;

int main(){
 
  pq.push(3);
  pq.push(2);
  pq.push(5);

  // pq 예상 출력 결과 -> 5, 3, 2
  while(!pq.empty()){
    cout << pq.top() << endl;
    pq.pop();
  }
  
 return 0; 
}
