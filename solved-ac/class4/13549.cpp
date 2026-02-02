/*
BOJ No.13549
숨바꼭질 3
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
queue<pair<int,int>> q;
vector<bool> visit(100001, false);

int BFS() {
	q.push({ n,0 });
	visit[n] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		if (cur == k) {
			return time;
		}


		// cur*2를 if문 제일 앞에 써줘야 가장 짧은 시간을 구할 수 있다.
		if (cur * 2 <= 100000 && !visit[cur * 2]) {
			visit[cur * 2] = true;
			q.push({ cur * 2, time });
		}
		if (cur - 1 >= 0 && !visit[cur-1]) {
			visit[cur - 1] = true;
			q.push({ cur - 1,time + 1 });
		}
		if (cur + 1 <= 100000 && !visit[cur+1]) {
			visit[cur + 1] = true;
			q.push({ cur + 1, time + 1 });
		}

	}
}

int main() {

	cin >> n >> k;
	cout << BFS();
}
