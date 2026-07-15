/*
프로그래머스
해시
전화번호 목록
Level 2
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> um;
    
    string maxS = phone_book[0];
    string minS = phone_book[0];
    for (int i = 0; i< phone_book.size(); i++) {
        if (maxS.size() < phone_book[i].size()) maxS = phone_book[i];
        if (minS.size() > phone_book[i].size()) minS = phone_book[i];
    }
    
    int maxLength = maxS.size();
    int minLength = minS.size();
    
    for (int i = 0; i < phone_book.size(); i++) {
        string prefix = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            prefix+= phone_book[i][j];
            if (prefix.size() >= minLength && prefix.size() < maxLength) um[prefix]++;
        }
    }
    
    for (int i = 0; i < phone_book.size(); i++) {
        if (um[phone_book[i]] >= 2) {
            answer = false;
            break;
        }
    }
    
    

    return answer;
}
