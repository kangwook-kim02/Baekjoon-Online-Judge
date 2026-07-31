/*
탐욕법 > 체육복
Level 1
느낀점: 정렬을 안했는데, 사실 문제조건에 순서 없이 배치되어있다라는 힌트가 없었기 때문이다.
따라서 AI의 도움을 받아 정렬 힌트를 받았고, 다음부터는 이에 유의를 해야한다.
또한 유튜브 그리디 강의에서 정렬이 필요하다고 했었다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == -1) continue;
            if (lost[i] == reserve[j]) {
                lost[i] = -1;
                reserve[j] = -1;
                answer++;
                break;
            }
        }
    }
    
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == -1) {
            continue;
        }
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == -1) continue;
            
            if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) {
                reserve[j] = -1;
                answer++;
                break;
            }
        }
    }
    return answer;
}
