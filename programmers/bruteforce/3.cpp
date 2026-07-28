/*
완전 탐색 > 소수 찾기
Level 2
느낀점: 나한테는 어렵다고 느껴졌다. 오랜만에 DFS를 작성하려니 감이 잘 잡히지 않았고,
실제로 테스트 케이스 실패를 떠서야 고칠 수가 있었다. 만약 실전에서 내가 푼 알고리즘이 맞았는지 틀렸는지 알려주지 않는다면
분명히 예외에서 털렸을 문제.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> visit(10000000, false);

void dfs(int start, string numbers, string num, vector<int>& candidate, vector<bool>& v) {
    if (num.size() > numbers.size()) {
        return;
    }
    
    
    if (num.size() == 1 && !visit[num[0] - '0']) {
        candidate.push_back(num[0] - '0');    
        visit[num[0] - '0'] = true;
    }
    
    if (num.size() > 1 && !visit[stoi(num)]) {
        candidate.push_back(stoi(num));
        visit[stoi(num)] = true;
    }
    
    
    for (int i = 0; i < numbers.size(); i++) {
        if (i == start) {
            continue;
        }
        
        if (!v[i]) {
            v[i] = true;
            dfs(i, numbers, num+numbers[i], candidate, v);
            dfs(i, numbers ,numbers[i]+num, candidate, v);
            v[i] = false;
        }  
    }
}

bool isPrime(int num) {
    int count = 0;
    if (num == 1  || num == 0) {
        return false;
    }
    
    if (num == 2) {
        return true;
    }
    
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> candidate;
    vector<bool> v(7, false);
    dfs(-1, numbers, "", candidate,v);
    
    vector<bool> prime(10000000, false);
    
    for (int i = 0; i < candidate.size(); i++) {
        if (isPrime(candidate[i]) && !prime[candidate[i]]) {
            answer++;
            prime[candidate[i]] = true;
            // cout << candidate[i] << " ";
        }
    }
    
    return answer;
}
