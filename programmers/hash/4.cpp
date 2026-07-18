/*
해시 > 의상
Level 2
시행착오: 
처음에 DFS로 접근하니 시간 초과가 발생하였다. 당연히 O(2^30)이기 때문에 다른 방식을 생각했어야 했지만
그러지 않고, DFS에서 시간을 줄이려는 시도를 하였다. 이후 해결을 하지는 못했고
AI의 도움을 받아, 조합을 이용해서 풀어야 한다는 힌트를 얻고 다시 풀기 진행
알고리즘: 맵, 조합(수학)
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string,int> um;

    for (int i = 0; i < clothes.size(); i++) {
        um[clothes[i][1]]++;
    }
    answer = 1;
    for (auto iter : um) {
        answer = answer*(iter.second + 1);
    }
    answer--;
    return answer;
    
}
