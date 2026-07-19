/*
스택/큐 > 올바른 괄호
Level 2
느낀점: 문해기, 백준에서 풀었던 문제와 유사하여 어렵지 않게 풀음
*/

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') stk.push(s[i]);
        
        if (s[i] == ')') {
            if (stk.empty()) {
                answer = false;
                break;
            }
            stk.pop();
        }
    }
    if (!stk.empty()) answer = false;
    return answer;
}
