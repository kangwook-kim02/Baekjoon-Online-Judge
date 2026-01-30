/*
BOJ No.11660
구간 합 구하기 5
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<vector<int>> dp(n, vector<int>(n, 0));

	// O(n^2)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	
	// O(n^2)
	dp[0][0] = v[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			if (j == 0) {
				dp[i][j] = dp[i - 1][n - 1] + v[i][j];
			}
			else {
				dp[i][j] = dp[i][j - 1] + v[i][j];
			}
		}
	}

	// o(m*n)
	for (int i = 0; i < m; i++) {
		int sum = 0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// n*n 행렬에서 0,0부터 시작하는 것을 맞추기 위해 1씩 빼기
		x1--;
		y1--;
		x2--;
		y2--;

		for (int i = x1; i <= x2; i++) {
			sum += dp[i][y2];
			if (y1 == 0) {
				if (i > 0) sum = sum - dp[i - 1][n - 1];
				continue;
			}
			sum = sum - dp[i][y1 - 1];
			
		}
		cout << sum << "\n";
	}
}
