/*
BOJ No.10830
행렬 제곱
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solve(long long B, vector<vector<int>> &matrix) {
	
	// breakpoint
	if (B == 1) {
		return matrix;
	}

	vector<vector<int>> a;
	vector<vector<int>> b(matrix.size(), vector<int>(matrix.size(), 0));
	vector<vector<int>> c(matrix.size(), vector<int>(matrix.size(), 0));

	if (B % 2 == 0) { // 짝수 일경우
		a = solve(B / 2, matrix);
		b = a;
	} 
	else { // 홀수 일경우
		a = solve(B / 2, matrix);
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				for (int k = 0; k < matrix.size(); k++) {
					b[i][j] += (a[i][k] % 1000 * matrix[k][j] % 1000) % 1000;
				}
			}
		}
	}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			for (int k = 0; k < matrix.size(); k++) {
				c[i][j] += (a[i][k]%1000 * b[k][j]%1000)%1000;
			}
		}
	}

	return c;

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	long long B;
	cin >> n >> B;
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	vector<vector<int>> result(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	
	result = solve(B, matrix);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j]%1000 << " ";
		}
		cout << "\n";
	}
}
