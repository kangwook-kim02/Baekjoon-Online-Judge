/*
스택/큐 > 다리를 지나는 트럭
Level 2
느낀점: 구현을 시뮬레이션 방식으로 진행을 했어야 했는데, 나는 실제로 O(n) time에 해결하기 위해
시뮬레이션이 아닌 트럭이 다리를 건너는 시간으로 이동하게끔 구현을 했다.
그러다보니 예외 케이스가 존재하였고 이 예외를 찾는데 시간이 오래걸렸다.
pop을 else에서만 하다보니까 예외에 걸린 것이였고
time++을 해줄 때도 맨 앞에 있는 트럭이 다리를 건넜는지 아닌지 체크를 꼭 해줘야했다.
다음부터는 이런 문제는 시뮬레이션으로 구현하는게 더 쉬울 것 같다.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int time = 1;
    int sum_weight = 0;
    queue<pair<int,int>> q; // (on_time, weight)
    
    for (int i = 0; i < truck_weights.size(); i++) {
        if (sum_weight + truck_weights[i] <= weight && q.size() < bridge_length) {
            q.push({time, truck_weights[i]});
            sum_weight += truck_weights[i];
            time++;

            // time++ 이후에도 pop을 할지 체크 해야함
            if (time >= q.front().first + bridge_length)  {
                sum_weight -= q.front().second;
                q.pop();   
            }
            
        } else {
            time = q.front().first + bridge_length;
            sum_weight -= q.front().second;
            q.pop();
            i--;
        }
    }
    
    answer = q.back().first + bridge_length;
    
    return answer;
}
