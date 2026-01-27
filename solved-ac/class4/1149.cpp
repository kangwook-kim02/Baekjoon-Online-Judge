/*
BOJ No.1149
RGB 거리
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(3, 0));
	vector<bool> visit(3, false);
	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	/*
	각 i번째 집마다 각각 R,G,B로 칠했을 때 최소 비용을 구한 후
	n번째 집의 R,G,B 중 최소 비용 출력
	*/

	// dp[i][0]은 i번째 집을 R로 칠했을 때 최소 비용
	// dp[i][1]은 i번째 집을 G로 칠했을 떄 최소 비용
	// dp[i][2]은 i번째 집을 B로 칠했을 때 최소 비용
	vector<vector<int>> dp(n, vector<int>(3, 0));
	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
	}

	int min = dp[n - 1][0];
	for (int i = 1; i < 3; i++) {
		min = dp[n-1][i] < min ? dp[n-1][i] : min;
	}
	cout << min;

}
