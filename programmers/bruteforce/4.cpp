/*
완전탐색 > 카펫
Level 2
느낀점: 모든 가능한 2차원 배열의 경우의 수를 구하여 각 경우의 수마다 옐로우의 칸의 수와 파라미터로 받은 옐로우의 개수와 동일하면 리턴하도록 했다.
근데 이게 비효율적이라고 생각을 한 것이, 굳이 2차원 배열을 선언할 필요 없이 수식적으로 바깥쪽 라인의 개수만 세서 브라운 개수와 동일한지로도 구할 수 있을 것 같다
하지만, 내가 머리 쓰기 싫어서 그냥 배열로 진행함.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    vector<pair<int,int>> v; // (row, column)
    for (int i = 3; i < total; i++) {
        if (total % i == 0) {
            if (i <= total/i) v.push_back({i, total/i});
        }
    }
    
    for (int i = 0; i < v.size(); i++) {
        int row = v[i].first;
        int column = v[i].second;
        vector<vector<int>> carpet(row, vector<int>(column, 0));
        int count = 0;
        for (int i = 0; i < carpet.size(); i++) {
            for (int j = 0; j < carpet[i].size(); j++) {
                if (i > 0 && j > 0 && i < carpet.size()-1 && j < carpet[i].size()-1) count++;
            }
        }
        
        if (count == yellow) {
            answer.push_back(column);
            answer.push_back(row);
            return answer;
        }
    }
    
}
