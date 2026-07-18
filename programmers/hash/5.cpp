/*
해시 > 베스트 엘범, Level 3
문법적으로 오류를 범했는데, comp 함수에서 파라미터로 벡터 내의 저장되는 원소들의 타입을 전달해야 한다.
하지만 나는 vector 자체를 전달할려고 해서 문법적으로 오류가 있었으나 이를 캐치하지 못했다.

핵심 알고리즘
1. 각 장르들의 플레이 수를 계산하기 위해 unordered_map에 저장한다.
2. set 함수를 통해 전체 장르 집합을 구한다.
3. set을 순회하면서 장르를 얻고, unordered_map에 저장된 플레이 수를 벡터(sum_genres)에 저장을 한다.
5. 저장된 벡터를 comp 함수를 통해 정렬한다. (문제 조건 중, 총 플레이 수가 많은 장르 순으로 출력)
6. sum_genres를 순회하면서, 특정 장르에 해당하는 모든 노래를 가져오고, 그 노래들을 comp2 함수를 통해 정렬한다.
7. answer에 저장한다.

알고리즘 분류: 맵, 해쉬, 완전탐색(Brute-force)
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

bool comp(pair<string,int> a, pair<string,int> b) {
    return a.second > b.second;
}

bool comp2(pair<int,int> a, pair<int,int> b) {
    if (a.second != b.second) return a.second > b.second;
    
    return a.first < b.first;
}

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> um;
    set<string> s;
    
    for (int i = 0; i < genres.size(); i++) {
        um[genres[i]] += plays[i];
        s.insert(genres[i]);
    }
    
    vector<pair<string,int>> sum_genres; // 각 장르마다 재생 횟수를 벡터의 저장
    for (auto iter : s) {
        sum_genres.push_back({iter, um[iter]});
    }
    
    sort(sum_genres.begin(), sum_genres.end(), comp);
    vector<int> answer;
    
    for (int i = 0; i < sum_genres.size(); i++) {
        vector<pair<int,int>> temp; // idx, plays
        for (int j = 0; j < plays.size(); j++) {
            if (genres[j] == sum_genres[i].first) temp.push_back({j, plays[j]});
        }
        
        sort(temp.begin(), temp.end(), comp2);
        answer.push_back(temp[0].first);
        if (temp.size() >= 2) answer.push_back(temp[1].first);
     }
    
    
    
    return answer;
}
