/*
스택/큐 > 프로세스
Level 2
느낀점: 내림차순 정렬 할 때, sort 함수 3번째 파라미터 전달하는 법을 까먹었었다.
만약 실전이었다면 greater<int>() 이런걸 쓰는 것보단, compare 함수를 만는게 더 속도가 빠를 것 같다
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
    }
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    int idx = 0;
    int high = priorities[0];
    while (!q.empty()) {
        high = priorities[idx];
        int process = q.front().second;
        int pos = q.front().first;
        q.pop();
        if (process == high) {
            idx++;
            if (pos == location) {
                answer = idx;
                break;
            }
        } else {
            q.push({pos,process});
        }
    }

    
    
    return answer;
}
