/*
프로그래머스 고득점 킷
해시
완주하지 못한 선수
Level 1
*/


#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> um;
    
    for (int i = 0; i < completion.size(); i++) {
        um[completion[i]]++;
    }
    
    for (int i = 0; i < participant.size(); i++) {
        um[participant[i]]--;
        if (um[participant[i]] < 0) {
            answer = participant[i];
            break;
        }
    }
    
    
    return answer;
}
