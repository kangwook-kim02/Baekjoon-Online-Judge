/*
힙(Heap) > 이중우선순위큐
Level 3
느낀점: 이중 우선 순위를 어떻게 구현해야할까 고민을 하다가 이전에 풀어봤던
백준에서 작성한 코드를 참고하였다.
실제 구현 방식은 다음과 같다

1. 최대 힙 최소 힙 2개를 만든다
2. PUSH는 동시에 한다.
3. 최대 힙 혹은 최소힙을 pop을 한다 (visit 함수를 이용하여 제거한 원소를 표시해준다.)
  - POP 하기 전 제거된 원소들을 선별할 필요가 있다. (while)
  - 또한 최종 결과를 산출 하기 전에도 제거된 원소를 선별 해야한다. (while)
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
    priority_queue<pair<int,int>, vector<pair<int,int>>> max_heap;
    vector<bool> visit(1000000, false);
    for (int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2, operations[i].size()-2));
        
        if (op == 'I') {
            min_heap.push({num, i});
            max_heap.push({num, i});
        }
        else if (op == 'D') {
            if (num == 1) { // 최댓값 삭제
                while (max_heap.size() > 0 && visit[max_heap.top().second]) {
                    max_heap.pop();
                }
                
                if (max_heap.size() > 0) {
                    visit[max_heap.top().second] = true;
                    max_heap.pop();
                }
                
            } else { // 최솟값 삭제
                while (min_heap.size() > 0 && visit[min_heap.top().second]) {
                    min_heap.pop();
                }
                
                if (min_heap.size() > 0) {
                    visit[min_heap.top().second] = true;
                    min_heap.pop();
                }
            }
        }
    }
    
    while (max_heap.size() > 0 && visit[max_heap.top().second]) {
        max_heap.pop();
    }
    while (min_heap.size() > 0 && visit[min_heap.top().second]) {
        min_heap.pop();
    }
    
    int maxNum = !max_heap.empty() ? max_heap.top().first : !min_heap.empty() ? min_heap.top().first : 0;
    int minNum = !min_heap.empty() ? min_heap.top().first : !max_heap.empty() ? max_heap.top().first : 0;
    
    answer.push_back(maxNum);
    answer.push_back(minNum);
    return answer;
}
