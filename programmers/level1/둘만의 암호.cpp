#include <string>
#include <vector>
using namespace std;

vector<int> skipFlag(26, 0);

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i = 0; i<skip.size(); i++){
        skipFlag[skip[i] - 97] = 1;
    }
    
    for(int i = 0; i<s.size(); i++){
        char ch = s[i];
        for(int j = 0; j<index; j++){
            if(ch == 'z') ch = 'a';
            else ch += 1;
            
            if(skipFlag[ch - 97]){
                while(skipFlag[ch - 97]){
                    if(ch == 'z') ch = 'a';
                    else ch += 1;
                }
            }
        }
        answer += ch;
    }
    return answer;
}
