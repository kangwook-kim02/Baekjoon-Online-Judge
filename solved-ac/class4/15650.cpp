/*
BOJ No. 15650
N과 M (2)
*/
/*
모든 경우의 수를 계산
N은 8이므로, O(2^8) --> 재귀 풀이 가능, 1초 안에 풀 수 있음
*/
#include <iostream>
#include <queue>

using namespace std;

int n, m;
queue<int> q;
queue<int> temp_q;

void solve(int start ,int depth) {
	if (depth == m) {
		// 출력
		while (!q.empty()) {
			cout << q.front() << " ";
			temp_q.push(q.front());
			q.pop();
		}
		cout << "\n";
		// 원상복귀 
		while (!temp_q.empty()) {
			q.push(temp_q.front());
			temp_q.pop();
		}
		return;
	}

	for (int i = start; i <= n; i++) {
		q.push(i);
		solve(i+1, depth + 1);
		
		// 마지막 원소 삭제
		while (!q.empty()) {
			temp_q.push(q.front());
			q.pop();
		}
		while (temp_q.size() > 1) {
			q.push(temp_q.front());
			temp_q.pop();
		}
		temp_q.pop();
	}
}

int main() {
	cin >> n >> m;
	solve(1,0);
}
