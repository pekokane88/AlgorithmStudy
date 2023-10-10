* 어떠한 두 수의 최대공약수 및 최소공배수 구하기 ([참조 링크](https://codingpractices.tistory.com/34))
  * 최대 공약수 구하는 방법
    * 유클리드 호제법 -> X, Y 의 최대 공약수 는 **y와 r(X % Y)의 최대 공약수와 같다**.   
       구현 방법 (python 예시)   
          while(y)   
            x,y = y, (x % y)   
  * 최소 공배수 구하는 방법
    * 최소 공배수 = (X * Y) / 최대 공약수   
    
* pq, vector 에서 임의의 정렬 함수 선언해서 사용하기 -> 한 번씩 꼭 나오니 숙지해두자. 
* split 이랑 back tracking 관련해서도 코드 적어두기.
* level 1,2 문제 유형 보기 편하게 정리해두기.
