/*
스택/큐 > 같은 숫자는 싫어
Level 1
느낀점: 코딩 테스트 볼 때, 만약 정답인지 아닌지를 알려주지 않는다면
테스트 케이스를 만들어서 예외를 확인해봐야한다.
*/

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> stk;
    for (int i = 0; i < arr.size(); i++) {
        if (stk.empty()) {
            stk.push(arr[i]);
            continue;
        }
        
        if (stk.top() == arr[i] && i != arr.size()-1) {
            continue;
        }
        else {
            int temp = stk.top();
            stk.pop();
            answer.push_back(temp);
            stk.push(arr[i]);
            
            if (i == arr.size()-1 && temp != arr[i]) answer.push_back(arr[i]);
        }
    }
   

    return answer;
}
