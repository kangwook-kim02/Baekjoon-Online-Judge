/*
BOJ No.9251
LCS (Longest Commong Subsequence)
--> DP로 풀 수 있음.
--> 얘는 풀이 과정을 아에 모르면 내 능력상 풀 수 없었음.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	vector<vector<int>> v(b.size() + 1, vector<int>(a.size() + 1, 0));

	for (int i = 1; i < v.size(); i++) {
		for (int j = 1; j < v[i].size(); j++) {
			if (a[j - 1] == b[i - 1]) {
				v[i][j] = v[i - 1][j - 1] + 1;
			}
			else {
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
			}
		}
	}

	cout << v[b.size()][a.size()];
}
