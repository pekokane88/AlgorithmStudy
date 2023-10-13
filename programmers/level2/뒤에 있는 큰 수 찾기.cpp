#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    //정답 임시 저장용
    vector<int> temp;
    //stack 용
    vector<int> list;
    
    //초기 세팅
    temp.push_back(-1);
    list.push_back(numbers[numbers.size() - 1]);
    
    //뒤에서부터 시작(큰 수를 저장하기 편함)
    for(int i = numbers.size() -2; i >= 0; i--){
        int num = -1;
        
        //현재 numbers[i]보다 큰 수를 찾을 때까지 stack 에서 제거해나가며 찾음.
        while(list.size() != 0){
           if(list[list.size() - 1] > numbers[i]){
                num = list[list.size() - 1];
                break;
            }
            else{
                list.pop_back();
            }
        }
        
        //그 후 정답과 탐색한 숫자를 각각 넣어준다.
        temp.push_back(num);
        list.push_back(numbers[i]);
    }
    
    for(int i = 0; i<temp.size(); i++){
        answer.push_back(temp[temp.size() - 1 - i]);
    }
    
    return answer;
}
