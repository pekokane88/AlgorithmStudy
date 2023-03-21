//나올 수 있는 기울기 가짓 수를 전부 확인 후, 평행 또는 일치 여부를 확인하였다.
//전부 하드코딩하였는데 가짓 수 조합을 어디에 저장해두고 사용하면 더 깔끔한 코드가 되지 않을까 싶다.
#include <string>
#include <vector>
using namespace std;

double gradient1 = 0;
double gradient2 = 0;
double y1 = 0;
double y2 = 0;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    //case1
    gradient1 = (double)(dots[1][1] - dots[0][1]) / (double)(dots[1][0] - dots[0][0]);
    gradient2 = (double)(dots[3][1] - dots[2][1]) / (double)(dots[3][0] - dots[2][0]);
    if(gradient1 == gradient2){
        y1 = (double)gradient1 * dots[0][0] + (double)dots[0][1];
        y2 = (double)gradient1 * dots[2][0] + (double)dots[2][1];
        if(y1 == y2 or y1 != y2) return 1;
    }
    
    //case2
    gradient1 = (double)(dots[2][1] - dots[0][1]) / (double)(dots[2][0] - dots[0][0]);
    gradient2 = (double)(dots[3][1] - dots[1][1]) / (double)(dots[3][0] - dots[1][0]);
    if(gradient1 == gradient2){
        y1 = (double)gradient1 * dots[0][0] + (double)dots[0][1];
        y2 = (double)gradient1 * dots[1][0] + (double)dots[1][1];
        if(y1 == y2 or y1 != y2) return 1;
    }
    
    //case3
    gradient1 = (double)(dots[3][1] - dots[0][1]) / (double)(dots[3][0] - dots[0][0]);
    gradient2 = (double)(dots[2][1] - dots[1][1]) / (double)(dots[2][0] - dots[1][0]);
    if(gradient1 == gradient2){
        y1 = (double)gradient1 * dots[0][0] + (double)dots[0][1];
        y2 = (double)gradient1 * dots[1][0] + (double)dots[1][1];
        if(y1 == y2 or y1 != y2) return 1;
    }
    
    return answer;
}
