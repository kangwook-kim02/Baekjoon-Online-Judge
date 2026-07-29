/*
완전탐색 > 피로도
Level 2
느낀점: 완전탐색 카테고리여서 문제를 보기 전부터 완전탐색으로 풀어야겠다는 생각을 갖고 있었지만,
실제 완전탐색의 힌트는 던전의 개수가 최대 8개라는 점이다.
따라서 DFS로 모든 경우의 수를 조사해가면서 풀었다.
모든 경우의 수는 피로도 상관 없다면
최대 8! O(8!)이 될 것이다.
*/

#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& dungeons, int current, vector<bool>& visit, int cnt, int& answer) {
    
    answer = max(answer,cnt);
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visit[i] && current >= dungeons[i][0]) {
            visit[i] = true;
            dfs(dungeons, current-dungeons[i][1], visit, cnt+1, answer);
            visit[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visit(dungeons.size(), false);
    dfs(dungeons, k, visit, 0, answer);
    return answer;
}
