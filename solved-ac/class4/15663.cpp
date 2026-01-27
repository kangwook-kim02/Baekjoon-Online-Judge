/*
BOJ No.15663
N과 M (9)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> v(8);
vector<bool> visit(8, false);
vector<int> result(8); 
int n, m;

void solve(int depth) {

	/*
	재귀로 다시 들어왔다는 뜻은, 이미 앞전 상황에서 중복이 없어 들어왔음
	따라서 그 이후에 값은 중복이 없을 것이므로 다음과 같이 초기화를 시켜야함
	이 조건을 찾은 반례
	4 4
	1 1 1 2
	ans
	1 1 1 2
	1 1 2 1
	1 2 1 1
	2 1 1 1
	해당 조건이 없을 경우 out
	1 1 1 2
	1 1 2 1
	*/
	for (int i = depth; i < n; i++) {
		result[i] = -1;
	}

	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			if (result[depth] != v[i]) {
				result[depth] = v[i];
				solve(depth + 1);
			}
			visit[i] = false;
		}
	}

}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.begin() + n); // 사전순으로 정렬
	solve(0);
}
