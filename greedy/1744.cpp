/*
BOJ No.1744
수 묶기
greedy
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> positive;
	vector<int> negative;
	vector<int> zero;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > 0) positive.push_back(num);
		if (num == 0) zero.push_back(num);
		if (num < 0) negative.push_back(num);
	}

	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());
	int sum = 0;
	// 큰 수끼리 곱하기
	for (int i = positive.size() - 1; i >= 0; i = i - 2) {
		if (i == 0) {
			sum = sum + positive[i];
			break;
		}

		// 1인 경우 곱하면 손해
		if (positive[i] == 1 || positive[i - 1] == 1) {
			sum = sum + positive[i] + positive[i - 1];
			continue;
		}
		sum = sum + positive[i] * positive[i - 1];
	}

	// 절대값이 큰 수끼리 곱하기
	for (int i = 0; i < negative.size(); i=i+2) {
		if (i == negative.size() - 1) {
			if (zero.size() == 0) {
				sum = sum + negative[i];
			}
			break;
		}
		sum = sum + negative[i] * negative[i + 1];
	}
	cout << sum;

}
