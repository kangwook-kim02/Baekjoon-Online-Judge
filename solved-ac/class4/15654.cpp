/*
BOJ No. 15654
N과 M (5)
중복이 있으면 안됨
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v(8);
vector<int> num(8);
vector<bool> visit(8, false);

void solve(int depth) {
	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			v[depth] = num[i];
			visit[i] = true;
			solve(depth + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.begin() + n); // 오름차순 정렬
	solve(0);
}
