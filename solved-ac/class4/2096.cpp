/*
BOJ No.2096
내려가기
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
	vector<int> v(3,0);
	vector<int> dp(3, 0);
	vector<int> dp_min(3, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[j];
		}
		if (i == 0) {
			dp[0] = v[0];
			dp[1] = v[1];
			dp[2] = v[2];
			dp_min[0] = v[0];
			dp_min[1] = v[1];
			dp_min[2] = v[2];
			continue;
		}

		int left, mid, right;
		int leftMin, midMin, rightMin;
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				left = max(dp[j], dp[j + 1]) + v[j];
				leftMin = min(dp_min[j], dp_min[j + 1]) + v[j];
			}
			else if (j == 1) {
				int max = 0;
				int min = 987654321; // 기존 min = 10으로 했지만, dp_min의 값은 10보다 큰 수가 올 수 있음
				for (int j = 0; j < 3; j++) {
					if (max < dp[j]) max = dp[j];
					if (min > dp_min[j]) min = dp_min[j];
				}
				mid = max + v[j];
				midMin = min + v[j];
			}
			else if (j == 2) {
				right = max(dp[j], dp[j - 1]) + v[j];
				rightMin = min(dp_min[j], dp_min[j - 1]) + v[j];
			}
		}
		dp[0] = left;
		dp[1] = mid;
		dp[2] = right;
		dp_min[0] = leftMin;
		dp_min[1] = midMin;
		dp_min[2] = rightMin;
		
	}
	int maxNum = 0; 
	int minNum = 987654321;
	for (int i = 0; i < 3; i++) {
		if (minNum > dp_min[i]) minNum = dp_min[i];
		if (maxNum < dp[i]) maxNum = dp[i];
	}

	cout << maxNum << " " << minNum;

}
