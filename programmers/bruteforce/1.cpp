/*
완전탐색 > 최소 직사각형
Level 1
풀이과정: 가장 큰 값을 찾는다.
그 값이 위치한 쪽의 축은 고정을 시킨 채로,
하나의 직사각형에 대해 다른 축의 값이 더 크다면 SWAP을 한다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_weight = 0;
    int max_height = 0;
    
    for (int i = 0; i < sizes.size(); i++) {
        if (max_weight < sizes[i][0]) {
            max_weight = sizes[i][0];
        }
        
        if (max_height < sizes[i][1]) {
            max_height = sizes[i][1];
        }
    }
    
    answer = max_weight*max_height;
    
    bool check = false;
    if (max_weight > max_height) {
        check = true;
    }
    
    for (int i = 0; i <sizes.size(); i++) {
        if (check && sizes[i][0] <= sizes[i][1]) {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        } else if (!check && sizes[i][0] >= sizes[i][1]) {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }
    int mul = max_height;
    int maxNum = 0;
    if (check) {
        mul = max_weight;
        for (int i = 0; i <sizes.size(); i++) {
            maxNum = max(maxNum, sizes[i][1]);
        }   
        
    }
    else {
        for (int i = 0; i <sizes.size(); i++) {
            maxNum = max(maxNum, sizes[i][0]);
        }   
    }
    answer = min (answer, mul * maxNum);
    
    return answer;
}
