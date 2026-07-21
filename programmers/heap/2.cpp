/*
힙 > 디스크 컨트롤러
Level 3
느낀점: 안뇽 스케줄러라는 문제 해결 기법과 거의 동일한 문제
jobs를 처음에 정렬을 해줘야 나중에 while에서 jobs를 우선순위 큐로 넣을 때 문제가 생기지 않음
jobs는 작업이 요청되는 시점을 기준으로 정렬함
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        if (a[1] != b[1]) return a[1] > b[1];
        if (a[0] != b[0]) return a[0] > b[0];
        return a[2] > b[2];
    }
};

bool comp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    for (int i = 0; i < jobs.size(); i++) {
        jobs[i].push_back(i);
    }
    
    sort(jobs.begin(),jobs.end(), comp);
    
    int time = 0;
    int idx = 0;
    while (idx <= jobs.size()-1 || !pq.empty()) {
        while (idx <= jobs.size()-1 && jobs[idx][0] <= time) {
            pq.push(jobs[idx]);
            idx++;
        }
        
        if (!pq.empty()) {
            vector<int> task = pq.top();
            pq.pop();
            time += task[1];
            answer += time - task[0];
            continue;
        }
        
        time++;
    }
    
    answer = answer / jobs.size();
    
    return answer;
}
