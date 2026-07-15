/*
프로그래머스
해시
포켓몬
Level 1
*/

#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;
    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }
    
    if (s.size() >= nums.size() / 2) 
        answer = nums.size() / 2;
    else
        answer = s.size();
    
    return answer;
}
