/*
baekjoon 2579
silver 3

at first, I can't solute this problem 
but, I refer this blog ( http://yabmoons.tistory.com/20 )
so, I get the idea about recursive formula and I don't see code
*/
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* dp = new int[n]; // DP ¹è¿­
	int* score = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}

	dp[0] = score[0];
	for (int i = 1; i < n; i++) {

		if (i == 1) {
			dp[i] = score[0] + score[1];
			continue;
		}
		if (i == 2) {
			dp[i] = max(score[0] + score[2], score[1] + score[2]);
			continue;
		}

		if (dp[i - 2] + score[i] > dp[i - 3] + score[i - 1] + score[i]) {
			dp[i] = dp[i - 2] + score[i];
		}
		else {
			dp[i] = dp[i - 3] + score[i - 1] + score[i];
		}
	}

	cout << dp[n - 1];
}