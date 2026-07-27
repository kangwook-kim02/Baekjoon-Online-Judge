/*
완전탐색 > 모의고사
Level 1
느낀점: 처음에는 각 수포자의 패턴을 분석하는 방식으로 해당 인덱스에서 어떤 값이 나올지 고민을 하였으나
주기가 존재했기 때문에 그럴 필요가 없었다는 것을 10분 고민한 뒤에 꺠달았다.

    vector<int> result = {numAnsweroOfOne, numAnsweroOfTwo, numAnsweroOfThree};
    
    int maxIdx = 0;
    for (int i = 1; i < 3; i++) {
        if (result[i] > result[maxIdx]) maxIdx = i;
    }    

    for (int i = 0; i < 3; i++) {
        if (result[maxIdx] == result[i]) answer.push_back(i+1);
    }

    또한 최댓값 찾기에 대해서 이렇게 작성한 코드가 비효율적인 것 같다는 생각이 들어
    다른 방법을찾아야할 것 같다 
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> one_answer = {1,2,3,4,5};
    int numAnsweroOfOne = 0;
    vector<int> two_answer = {2,1,2,3,2,4,2,5};
    int numAnsweroOfTwo = 0;
    vector<int> three_answer = {3,3,1,1,2,2,4,4,5,5};
    int numAnsweroOfThree = 0;
    
    
    
    for (int i = 0; i < answers.size(); i++) {
        if (one_answer[i%one_answer.size()] == answers[i]) {
            numAnsweroOfOne++;
        }
        
        if (two_answer[i%two_answer.size()] == answers[i]) {
            numAnsweroOfTwo++;
        }
        if (three_answer[i%three_answer.size()] == answers[i]) {
            numAnsweroOfThree++;
        }
    }
    
    vector<int> result = {numAnsweroOfOne, numAnsweroOfTwo, numAnsweroOfThree};
    
    int maxIdx = 0;
    for (int i = 1; i < 3; i++) {
        if (result[i] > result[maxIdx]) maxIdx = i;
    }    

    for (int i = 0; i < 3; i++) {
        if (result[maxIdx] == result[i]) answer.push_back(i+1);
    }
    
    return answer;
}
