/*
BOJ No.1697
숨바꼭질
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int>& v, queue<int> &q) {
	while (!q.empty()) {
		int idx = q.front();
		q.pop();

		if (idx - 1 >= 0 && v[idx - 1] == -1) {
			v[idx - 1] = v[idx] + 1;
			q.push(idx - 1);
		}
		if (idx + 1 < v.size() && v[idx + 1] == -1) {
			v[idx + 1] = v[idx] + 1;
			q.push(idx + 1);
		} 
		if (idx != 0 && 2 * idx < v.size() && v[2 * idx] == -1) {
			v[2 * idx] = v[idx] + 1;
			q.push(2 * idx);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> v(100001);
	for (int i = 0; i < v.size(); i++) {
		v[i] = -1; // 방문하지 않음
	}
	queue<int> q;
	v[n] = 0;
	q.push(n);
	BFS(v, q);
	cout << v[k];
}