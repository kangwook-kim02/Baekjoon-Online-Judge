/*
BOJ No.15903
카드 합체 놀이
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<long long> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < m; i++) {
		sort(v.begin(), v.end());
		long long sum = v[0] + v[1];
		v[0] = sum;
		v[1] = sum;
	}
	long long result = 0;
	for (int i = 0; i < n; i++) {
		result += v[i];
	}
	cout << result;
}
