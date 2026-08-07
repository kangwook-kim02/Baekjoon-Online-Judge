/*
탐욕법 > 구멍보트
Level 2
느낀점: 처음에 접근했을 때 50000^2 은 시간 초과가 걸릴 것 같다는 생각이 들었다. (=25억)
하지만, n^2/2 계산에 따르면 6억 5천만이 나오기 때문에 뭔가 시간 안에 돌아갈 수 있지 않을까 싶었다
구현 결과 결국 시간 초과
다음 방식으로 Binary Search를 사용했으나 얘도 마찬가지로 시간 초과가 발생하였다.
그 다음으로 생각한 방식이 Stack
가장 최적으로 보트에 최대한 2명씩 채우는 방법이 무엇일까 하다가 예를 들어
90 80 70 60 30 10 (최대 100kg)
이 있다 했을 때,
70 30
60 10
이든
60 30 이든
70 10 이든 
똑같은 결과이다. 하지만, 조금 더 생각을 해보았을 때, 예를들어 30의 값이 40이었다고 해보자 그러면 40과 60은 같은 보트에 탑승이 되지만 40과 70은 되지 않는다.
그렇기에 일관적으로 최대한 많이 탑승 시키기 위해서는 무게가 가운데인 친구들부터 먼저 태우면 일관적이게 된다.
예)
5번째 6번째 탑승
4번째 7번째 탑승
3번째 8번째 탑승
*/

#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    stack<int> stk;
    for (int i = people.size()-1; i >= 0; i--) {        
        if (stk.empty()) {
            stk.push(people[i]);
            continue;
        }
        
        if (stk.top() + people[i] <= limit) {
            answer++;
            stk.pop();
        }
        else {
            stk.push(people[i]);
        }
    }
    
    while(!stk.empty()) {
        stk.pop();
        answer++;
    }
    
    return answer;
}
