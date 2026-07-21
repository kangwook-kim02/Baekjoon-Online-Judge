/*
힙(Heap) > 더 맵게
Level 2
느낀점: 우선 순위 큐 알고리즘은 많이 풀지 않았지만, 우선 순위 큐라고 힌트를 주니 쉽게 풀었다.
다만, 만약 어떤 알고리즘을 쓰는지 모르고 문제를 풀었더라면 문제 유형이 익숙하지 않아 우선 순위 큐로 풀어야하는 지 몰랐을 것 같음
또한 항상 문제 풀 때 조건에 유의할 것 K 이상 이므로, < K 가 되어야 함.
*/

include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>, greater<int>> pq;
    
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while (pq.top() < K && pq.size() > 1) {
        answer++;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first+(second*2));
    }
    
    if (pq.size() == 1 && pq.top() < K) answer = -1; 
    
    return answer;
}
