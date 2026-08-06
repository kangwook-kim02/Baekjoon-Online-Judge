/*
탐욕법 > 큰 수 만들기
Level 2
느낀점: 굉장히 시행착오가 많았다. 이런 유형을 전에 풀어본 기억이 있어서 스택으로 푸는건가? 생각을 처음에 했지만
무시하고 이중 반복문으로 진행을 했다. 당연히 O(100만 * 100만) 이기 때문에 시간 초과가 일어났고
어떻게 풀까 생각을 하다가 다시 처음으로 돌아와 스택을 이용하여 풀었다.
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> stk;
    int count = 0;
    for (int i = 0; i < number.size(); i++) {
        if (stk.empty()) {
            stk.push(number[i]);
            continue;
        }
        
        while (!stk.empty() && stk.top() < number[i] && count < k) {
            stk.pop();
            count++;
        }
        stk.push(number[i]);
    }

    while (count < k) {
        stk.pop();
        count++;
    }
    
    string temp = "";
    while (!stk.empty()) {
        temp += stk.top();
        stk.pop();
    }
    
    for (int i = temp.size()-1; i >= 0; i--) {
        answer += temp[i];
    }

    return answer;
}
