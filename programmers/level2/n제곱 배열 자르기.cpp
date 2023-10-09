//규칙을 확인한 후, 순차대로 나누어 구현.
#include <string>
#include <vector>
using namespace std;

//규칙 -> i 번째 행에서 i + 1 이 i + 1개만큼 들어감. 그리고 그 뒤는 +=1

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    //get left and right current row and col.
    int startRow =  left / n;
    int endRow = right / n;
    int startCol = left % n;
    int endCol = right % n;
        
    //Same Row
    if(endRow - startRow == 0){
        int duplicateNum = startRow + 1;
        for(int i = startCol; i<=endCol; i++){
            if(i < duplicateNum){
                answer.push_back(duplicateNum);
            }
            else{
                answer.push_back(duplicateNum + (i - startRow));
            }
        }
    }
    //Row diff is 1
    else if(endRow - startRow == 1){
        int duplicateNum1 = startRow + 1;
        int duplicateNum2 = endRow + 1;
        //start
       for(int i = startCol; i<n; i++){
           if(i < duplicateNum1){
               answer.push_back(duplicateNum1);
           }
           else{
               answer.push_back(duplicateNum1 + (i - startRow));
           }
       }
        //end
        for(int i = 0; i<=endCol; i++){
            if(i<duplicateNum2){
                answer.push_back(duplicateNum2);
            }
            else{
                answer.push_back(++duplicateNum2);
            }
        }
    }
    //Row diff is up than 2
    else{
        int startDuplicateNum = startRow + 1;
        int endDuplicateNum = endRow + 1;
        
        //start
        for(int i = startCol; i<n; i++){
            if(i < startDuplicateNum){
                answer.push_back(startDuplicateNum);
            }
            else{
                answer.push_back(startDuplicateNum + (i - startRow));
            }
        }
        //middle
        for(int i = startRow + 1; i <= endRow - 1; i++){
            int middleDuplicateNum = i + 1;
            for(int j = 0; j<n; j++){
                if(j < middleDuplicateNum){
                    answer.push_back(middleDuplicateNum);
                }
                else{
                    answer.push_back(++middleDuplicateNum);
                }
            }
        }
        //end
        for(int i = 0; i<=endCol; i++){
            if(i < endDuplicateNum){
                answer.push_back(endDuplicateNum);
            }
            else{
                answer.push_back(++endDuplicateNum);
            }
        }
    }
    
    return answer;
}
