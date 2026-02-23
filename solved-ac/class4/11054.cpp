/*
BOJ No.11054
가장 긴 바이토닉 부분 수열
DP 풀이
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> dp(n, 1);
	vector<int> dp_down(n, 1);
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (v[i] > v[j]) {
				dp_down[i] = max(dp_down[i], dp_down[j] + 1);
			}
		}
	}
	int max_up = 0;
	int max_down = 0;
	int result = 0;
	for (int i = 0; i < n; i++) {
		max_up = max(max_up, dp[i]);
		max_down = 0;

		for (int j = i; j < n; j++) {
			max_down = max(max_down, dp_down[j]);
		}

		result = max(result, max_up + max_down);
	}
	cout << result-1;

}
