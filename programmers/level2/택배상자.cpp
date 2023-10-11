//Main 벨트에 있는 상자는 1~n 까지의 순서대로 있음. 해당 상자는 1부터 차례대로 밖에 빼지 못함.
//보조 벨트에 있는 상자는 Main 벨트에 있던 상자를 옮겨 둔 것. 입구 외에 다른 면이 막혀 있어 한 쪽으로 밖에 빼지 못해 Stack 과 같은 First In Last Out 의 구조를 가지고 있음.
//택배 기사가 주문한 대로 택배 상자를 싣기 위해 Main / 보조 벨트 위의 박스를 순서대로 옮길 때 최대 몇개까지 order 대로 옮길 수 있는지 확인하는 문제.
//Stack 과 비슷한 Vector 의 pop_back() 을 이용하여 구현.
#include <string>
#include <vector>
using namespace std;

vector<int> subBox;
vector<int> mainBox;
vector<int> truck;
int solution(vector<int> order) {
    int answer = 0;
    
    for(int i = order.size(); i >= 1; i--){
        mainBox.push_back(i);
    }

    while(true){
        if(mainBox[mainBox.size() - 1] == order[0]){
            truck.push_back(mainBox[mainBox.size() - 1]);
            mainBox.pop_back();
            break;
        }
        subBox.push_back(mainBox[mainBox.size() - 1]);
        mainBox.pop_back();
    }
    
    for(int i = 1; i < order.size(); i++){
        if(mainBox.size() != 0 and mainBox[mainBox.size() - 1] < order[i]){
            while(true){
                if(mainBox.size() == 0) break;
                if(mainBox[mainBox.size() - 1] == order[i]){
                    truck.push_back(mainBox[mainBox.size() - 1]);
                    mainBox.pop_back();
                    break;
                }
                subBox.push_back(mainBox[mainBox.size() - 1]);
                mainBox.pop_back();
            }
        }
        else{
            if(mainBox.size() != 0 and mainBox[mainBox.size() - 1] == order[i]){
                truck.push_back(mainBox[mainBox.size() - 1]);
                mainBox.pop_back();
                continue;
            }
            if(subBox.size() != 0 and subBox[subBox.size() - 1] == order[i]){
                truck.push_back(subBox[subBox.size() - 1]);
                subBox.pop_back();
                continue;
            }
            break;
        }
    }
    
    answer = truck.size();
    
    return answer;
}
