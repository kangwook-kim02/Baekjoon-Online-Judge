/*
완전탐색 > 전략망을 둘로 나누기
Level 2
느낀점: undirected edge임에 유의를 해야한다는 것 
코드 자체는 단순히 각 전선을 하나씩 잘라서 DFS를 돌려 각 전력망의 개수의 차이를 구하여
최소 값만 찾으면 된다
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>> &wires, vector<bool>& visit, int &cnt, int current) {
    cnt++;
    visit[current] = true;
    for (int i = 0; i < wires.size(); i++) {
        if (wires[i][0] == current && !visit[wires[i][1]]) dfs(wires,visit,cnt,wires[i][1]);
        if (wires[i][1] == current && !visit[wires[i][0]]) dfs(wires,visit,cnt,wires[i][0]);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 9999;
    
    for (int i = 0; i < wires.size(); i++) {
        vector<bool> visit(n, false);
        vector<vector<int>> temp = wires;
        temp.erase(temp.begin() + i);
        int count1 = 0;
        int count2 = 0;
        bool check = false;
        for (int j = 1; j < n; j++) {
            if (!visit[j] && !check) {
                check = true;
                dfs(temp,visit,count1,j);
                continue;
             }
            if (!visit[j] && check) {
                dfs(temp,visit,count2,j);
            }
        }
        if (count1 > count2) {
            answer = min(answer, count1-count2);
        }
        else {
            answer = min(answer, count2-count1);
        }
    }

    
    return answer;
}
