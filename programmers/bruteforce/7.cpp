/*
완전탐색 > 모음사전
Level 2
느낀점: 처음에 어떻게 풀어야하지. 규칙이 없나 고민을 하다가 도저히 규칙이 보이지 않았다
그래서 메모장을 키고 했으나 규칙이 보이지 않았다.
하지만, 일단 모든 경우의수를 돌아야한다는 생각이 있었기 때문에
for문 5개를 넣으면 된다는 것까지는 알고 있었고
문제 규칙을 보면 A -> AA -> AAA -> AAAA -> AAAAA -> AAAAE -> AAAAI -> AAAAO -> AAAAU
이런식으로 값이 증가하는 것을 확인하였다.
결국 각 for문은 각 자리수의 가능한 경우의 수를 놓고 돌리면서 뒤에서부터 하나씩 바꿔가면 된다는 것을 깨달았다.

처음에는 DFS도 생각했으나 그 방식은 도저히 생각나지 않았고,
문해기 시간에 예전에 석사 선배님이 힌트로 그냥 이거 포문 24번 돌리면 되요 라고 말씀해주셔서
그 말이 기억나 풀 수 있었던 문제
*/

#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    vector<char> v = {'A', 'E', 'I', 'O', 'U'};
    int count = 0;
    for (int i = 0; i < 5; i++) {
        char first = v[i];
        count++;
        if (word.size() == 1 && word[0] == first) {
            return count;
        }
        for (int j = 0; j < 5; j++) {
            char second = v[j];
            count++;
            if (word.size() == 2 && word[0] == first && word[1] == second) {
                return count;
            }
            for (int k = 0; k < 5; k++) {
                char third = v[k];
                count++;
                if (word.size() == 3 && word[0] == first && word[1] == second && word[2] == third) {
                    return count;
                }
                for (int l = 0; l < 5; l++) {
                    char fourth = v[l];
                    count++;
                    if (word.size() == 4 && word[0] == first &&
                        word[1] == second && word[2] == third && word[3] == fourth) {
                     return count;
                    }
                    for (int m = 0; m < 5; m++) {
                        char fifth = v[m];
                        count++;
                        if (word.size() == 5 && word[0] == first &&
                        word[1] == second && word[2] == third && word[3] == fourth && word[4] == fifth) {
                            return count;
                        }
                    }
                }
            }
        }
    }
}
