/*
BOJ No.11053
가장 긴 증가하는 부분 수열
*/
/*
BruteForce는 시간초과

*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// dp[i]는 i번째 원소까지의 증가하는 부분 수열의 개수
	// 처음에는 자기 자신 원소만 포함하므로 1이라고 초기화
	vector<int> dp(n, 1); // O(n)
	for (int i = 0; i < n; i++) { // i번째 원소까지
		for (int j = 0; j < i; j++) { // j번째까지의 증가하는 부분 수열
			if (v[i] > v[j]) { // i번쨰 원소가 j번째 원소보다 값이 크면
				dp[i] = max(dp[i], dp[j] + 1); // j번째까지의 증가하는 부분 수열의 개수에서 + 1
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}
	cout << result;
}
