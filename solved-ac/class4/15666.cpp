/*
BOJ No.15666
N과 M (12)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v(8);
vector<int> result(8);

void solve(int depth) {

	for (int i = depth; i < n; i++) {
		result[depth] = -1;
	}

	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (result[depth] != v[i]) {
			if (depth > 0 && result[depth - 1] > v[i]) continue;
			result[depth] = v[i];
			solve(depth + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.begin() + n);
	solve(0);
}
