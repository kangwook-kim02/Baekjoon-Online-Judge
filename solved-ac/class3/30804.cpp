/*
BOJ No.30804
과일 탕후루
*/

/*
문제 풀이 전략
Greedy 전략으로 앞쪽과 뒤쪽 중에 
해당 종류의 과일의 개수가 더 적은 것을 빼도록 하자
case 
9
5 5 5 1 1 1 1 2 1
에 대해서 7이 나와야하지만 6이 나옴
그리디 전략을 사용할 경우 5 5 5를 제거해버리므로 그리디 전략으로 풀 수 없음
-----------------------
슬라이딩 윈도우 전략
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> f(n); 
	vector<int> fruit(10);
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}

	int front = 0;
	int rear = 0;
	int category = 0;
	fruit[f[0]]++;
	category++;
	int result = 1;
	int count = 1;
	for (int i = 0; i < n-1; i++) {
		rear++;
		fruit[f[rear]]++;
		count++;
		if (fruit[f[rear]] == 1) {
			category++;
		}

		if (category > 2) {
			while (category > 2) {
				fruit[f[front]]--;
				count--;
				if (fruit[f[front]] == 0) category--;
				front++;
			}
		}

		result = max(result, count);
	}
	
	cout << result;
}