/*
BOJ No.16928
뱀과 사다리 게임
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph(101);
vector<int> visit(101); // unvisited: 0, visited: 1
queue<int> q;
vector<int> depth(101);
void BFS() {
	q.push(1);
	visit[1] = 1;
	depth[1] = 0;
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		// 주사위를 던질 때
		if (graph[idx] == 0) {
			for (int i = idx + 1; i <= idx + 6; i++) {
				if (i > 100) continue;

				if (visit[i] == 0) {
					visit[i] = 1;
					depth[i] = depth[idx] + 1;
					// 즉시 이동 처리를 해야함
					// 기존에는 즉시 이동 처리를 하지 않아 큐에서 후순위로 밀리면서,
					// depth[100]의 값이 올바르지 않게 나올 가능성이 있음
					if (graph[i] != 0) {
						if (visit[graph[i]] == 0) {
							depth[graph[i]] = depth[i];
							visit[graph[i]] = 1;
							q.push(graph[i]);
						}
						continue;
					}
					q.push(i);
				}
			}
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		graph[x] = y;
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u] = v;
	}

	BFS();
	cout << depth[100];
}
