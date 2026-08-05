/*
탐욕법 > 조이스틱
Level 2
느낀점: 너무 어렵다.......
좌우로 움직일 때, 왔다갔다 움직이는 것보단,
한쪽으로 쭈욱 갔다가 반대쪽으로 쭉 되돌아오는 경우가 제일 짧은 상황.......
잘 이해가 되지 않는 코드

*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string name) {
    unordered_map<char,int> um;
    unordered_map<char,int> um_reverse;
    vector<char> words = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int i = 0; i < words.size(); i++) {
        um[words[i]] = i;
        um_reverse[words[i]] = (26-i) % 26;
    }
    
    int answer = 0;
    string temp = name;
    
    for (int i = 0; i < name.size(); i++) {
        answer += min(um[name[i]],um_reverse[name[i]]);
    }
    
    int move = name.size()-1;
    int n = name.size();
    for (int i = 0; i < name.size(); i++) {
        int j = i+1;
        while (j < n && name[j] == 'A') j++;
        move = min(move, i + (n - j) + min(i, n - j)); 
    }
    answer += move;
    return answer;
}
