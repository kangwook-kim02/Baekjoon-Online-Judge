/*
BOJ No.9465
스티커
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> v(2, vector<int>(n, 0));
		vector<vector<int>> dp(2, vector<int>(n,0));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}

		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		int result = max(dp[0][0], dp[1][0]);
		if (n > 1) {
			dp[0][1] = dp[1][0] + v[0][1];
			dp[1][1] = dp[0][0] + v[1][1];
			result = max(dp[0][1], dp[1][1]);
		}
		for (int j = 2; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					dp[i][j] = max(dp[i + 1][j - 1], dp[i + 1][j - 2])+v[i][j];
					
				} 
				else if (i == 1) {
					dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j - 2]) + v[i][j];
				}
				result = max(result, dp[i][j]);
			}
		}
		
		cout << result << "\n";

	}
}
