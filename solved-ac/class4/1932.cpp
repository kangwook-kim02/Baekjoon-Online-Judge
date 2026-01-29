/*
BOJ No.1932
정수 삼각형
*/
/*
Dynamic Programming
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	// 입력이자, DP 테이블로 활용
	vector<vector<int>> v(n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0) {
				v[i][j] += v[i - 1][j];
				continue;
			}

			if (j == v[i].size() - 1) {
				v[i][j] += v[i - 1][j - 1];
				continue;
			}

			v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
		}
	}

	int maxNum = v[n - 1][0];
	for (int i = 1; i < v[n - 1].size(); i++) {
		if (maxNum < v[n - 1][i]) maxNum = v[n - 1][i];
	}
	cout << maxNum;
}
