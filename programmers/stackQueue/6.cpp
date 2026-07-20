/*
스택/큐 > 주식가격
Level 2
느낀점: 알고리즘이 스택/큐인지 유형을 모르고 진행을 했더라면 푸는데 오래 걸리거나
시간 초과가 걸렸을 가능성이 높을 것 같다
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int,int>> s;
    
    int time = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (s.empty() || s.top().second <= prices[i]) {
            s.push({time, prices[i]});
        } else {
            while (!s.empty() && s.top().second > prices[i]) {
                answer[s.top().first] = time - s.top().first;  
                s.pop();
            }
            s.push({time, prices[i]});
        }
        time++;
    }
    
    while (!s.empty()) {
        answer[s.top().first] = time - s.top().first - 1; 
        s.pop();
    }
    
    return answer;
}
