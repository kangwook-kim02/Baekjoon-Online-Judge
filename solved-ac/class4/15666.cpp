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
		// breakpoint -- depth값이 m과 동일할 때
		if (depth == m) {
			for (int i = 0; i < depth; i++) {
				cout << result[i] << " ";
			}
			cout << "\n";
			return;
		}

		/*
		prev의 이전 원소의 값을 저장하여
		prev값과 현재 원소의 값이 동일하면 중복이 발생하므로
		재귀를 호출할 수 없음
		*/
		int prev = -1;
		for (int i = 0; i < n; i++) {
			if (prev != v[i]) {
				if (depth > 0 && result[depth - 1] > v[i]) continue;
				result[depth] = v[i];
				prev = v[i];
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
