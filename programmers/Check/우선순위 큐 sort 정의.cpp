#include <iostream>
#include <queue>
using namespace std;

//pq 오름차순 정렬을 위한 비교함수
struct cmp{
  bool operator()(int n1, int n2){
    // 작을수록 우선 순위를 높게 주겠다는 의미.
    if(n1 < n2){
      return false;
    }
    else{
      return true;
    }
  }
};

//sort 의 내림차순 정렬을 위한 비교 함수
bool compare(int n1, int n2){
   if(n1 > n2){
     return true;
   }
  else{
    return false;
  }
};

priority_queue<int, vector<int>, cmp> pq;
vector<int> v1;

int main(){
 
  pq.push(3);
  pq.push(2);
  pq.push(5);

  // pq 예상 출력 결과 -> 5, 3, 2
  while(!pq.empty()){
    cout << pq.top() << endl;
    pq.pop();
  }
  
  v1.push_back(3);
  v1.push_back(4);
  v1.push_back(5);
  
  sort(v1.begin(), v1.end(), compare);
  
  //예상 출력 결과 5 4 3
  for(int i = 0; i<v1.size(); i++){
    cout << v1[i] << " ";
  }
  
 return 0; 
}
