/*
스택/큐 > 기능 개발
Level 2
느낀점: 스택 문제의 경우 마지막 원소를 어떻게 처리하는지를
즉 예외 상황을 생각해볼 것
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day(progresses.size(), 0);
    for (int i = 0; i < progresses.size(); i++) {
        int remain = 100 - progresses[i];
        if (remain <= 0) continue;
        
        int mul = remain / speeds[i];
        remain = remain - speeds[i] * mul;
        if (remain <= 0) {
            day[i] = mul;
        }
        else {
            day[i] = mul+1;
        }
    }
    
    stack<int> stk;
    stk.push(day[0]);
    int cnt = 1;
    for (int i = 1; i < day.size(); i++) {
        if (stk.top() >= day[i]) {
            cnt++;
            if (i == day.size()-1) {
                answer.push_back(cnt);
            }
        }
        else {
            stk.pop();
            answer.push_back(cnt);
            stk.push(day[i]);
            cnt = 1;
            
            if (i == day.size()-1) {
                answer.push_back(cnt);
            }
        }
    }
    
    return answer;
}
