/*
정렬 > 가장 큰 수
Level 2
느낀점: compare 함수를 작성할 때 복잡한 방식으로 비교를 하려고 했다
내가 처음 생각한 방식은 각 숫자의 자리수끼리 해서 숫자값이 클수록 앞에 오도록 비교하는 방식을 하였는데
이것은 문제가 있다 예를 들어, 3과 34가 있을 때 334 343 중 343이 크므로, 34가 앞으로 와야하지만
내가 푼 문제로는 334가 되어버린다. 따라서 추가적인 고민이 필요했는데
사실 아주 간단하게 두 원소를 입력 받을 때 조합 2개를 해서 즉 334와 343 중에 큰값이 앞으로 오도록 하면 되지 않을까? 생각을 하였고
그 방식으로 구현을 잘 동작하였고, 추가적으로 모든 원소 값이 0일 때 조건을 추가하여 해결하였다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (int a, int b) {
    string str_a = to_string(a);
    string str_b = to_string(b);
    
    int num1 = stoi(str_a + str_b);
    int num2 = stoi(str_b + str_a);
    
    return num1>num2;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    bool check = false;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] != 0) {
            check = true;
        }
        answer += to_string(numbers[i]);
    }
    
    if (!check) answer = "0";
    return answer;
}
