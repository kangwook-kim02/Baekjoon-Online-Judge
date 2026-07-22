/*
정렬 > K번째 수
Level 1
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        int j = commands[i][0] - 1;
        int k = commands[i][1] - 1;
        int l = commands[i][2] - 1;
        vector<int> temp;
        for (int m = j; m <= k; m++) {
            temp.push_back(array[m]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[l]);
    }
    return answer;
}
