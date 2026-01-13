/*
beakjoon 9461
silver 3
파도반 수열
DP (Dynamic programming) - bottom up
*/
#include <iostream>
using namespace std;

long long dp[101]; // 전역 변수 처리하는 이유는 0으로 모두 초기화 하기 위함.

int main() {
	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 100; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}