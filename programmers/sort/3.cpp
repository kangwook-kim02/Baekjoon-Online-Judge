/*
정렬 > H-index
Level 2
느낀점: 단순히 정렬 하고, citations의 값 하나씩 추출해서 그 이상만큼 있으면 h에 해당값을 저장하는 방식으로 했으나
그건 H-index라고 할 수 없었다. 예를 들어 [4,4,4]로 구성되어있을 때 H-index는 3이지만 내 알고리즘으로 돌리게 되면
0이 뜨는 것이다. 따라서 풀이 방식을 바꾸어
h 값을 0부터 돌려서 h 이상의 값의 개수를 array.size() - index로 계산을 하여 업데이트 하는 방식으로 변경하였다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    
    sort(citations.begin(), citations.end());
    int h = 0;
    int idx = 0;
    while (1) {
        int len = 0;
        for (int i = idx; i < citations.size(); i++) {
            if (h <= citations[i]) {
                idx = i;
                len = citations.size() - i;
                break;
            }
        }
        
        if (len >= h) {
            h++;
        }
        else {
            h--;
            break;
        }
    }
    
    for (int i = 0; i < citations.size(); i++) {
        if (h < citations[i] && citations.size()-i >= citations[i]) {
            h = citations[i];
        }
    }
    
    int answer = h;
    return answer;
}
