/*
BOJ No.12851
숨바꼭질 2
*/

/*
일반적인 true/false visit으로는 풀 수 없는 문제
*/
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int cnt;
int t = -1;
vector<int> visit(100001, -1);
queue<pair<int, int>> q;

// BFS 풀이
void solve(int n, int k) {
	q.push({ n,0 });
	visit[n] = 0;

	while (!q.empty()) {
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();

		if (pos == k) { // 동생을 찾았을 때
			if (cnt == 0) {
				t = time;
				cnt++;
				continue;
			}

			if (time == t) {
				cnt++;
				continue;
			}
			continue;
		}

		if (pos + 1 <= 100000) {
			if (visit[pos + 1] == -1) {
				visit[pos + 1] = time+1;
				q.push({ pos + 1,time + 1 });
			}
			else if (visit[pos + 1] >= time+1) {
				visit[pos + 1] = time + 1;
				q.push({ pos + 1,time + 1 });
			}
			
		}
		if (pos - 1 >= 0) {
			if (visit[pos - 1] == -1) {
				visit[pos - 1] = time + 1;
				q.push({ pos - 1,time + 1 });
			}
			else if (visit[pos - 1] >= time + 1) {
				visit[pos - 1] = time + 1;
				q.push({ pos - 1,time + 1 });
			}
		}
		if (2 * pos <= 100000) {
			if (visit[2*pos] == -1) {
				visit[2*pos] = time + 1;
				q.push({ 2*pos,time + 1 });
			}
			else if (visit[2*pos] >= time + 1) {
				visit[2*pos] = time + 1;
				q.push({ 2*pos,time + 1 });
			}
		}

	}

}

int main() {
	int n, k;
	cin >> n >> k;
	solve(n, k);
	cout << t << "\n" << cnt;
}
