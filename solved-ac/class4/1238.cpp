/*
BOJ No.1238
파티
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra(vector<vector<pair<int,int>>> &graph, vector<bool> &visit, vector<int> &dist ,int src) {
	dist[src] = 0;
	pq.push({ 0,src });
	while (!pq.empty()) {
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (visit[curNode]) continue;
		visit[curNode] = true;

		for (int i = 0; i < graph[curNode].size(); i++) {
			if (dist[graph[curNode][i].first] > curDist + graph[curNode][i].second) {
				dist[graph[curNode][i].first] = curDist + graph[curNode][i].second;
				pq.push({ dist[graph[curNode][i].first], graph[curNode][i].first });
			}
		}
	}
}

int main() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<bool> visit(n + 1, false);
	for (int i = 0; i < m; i++) {
		int src, dst, cost;
		cin >> src >> dst >> cost;
		graph[src].push_back({ dst,cost });
	}

	// x 마을에 대해 다익스트라
	vector<int> x_dist(n + 1, 987654321);
	Dijkstra(graph, visit, x_dist, x);

	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) {
			continue;
		}
		vector<bool> visit(n + 1, false);
		vector<int> dist(n + 1, 987654321);
		Dijkstra(graph, visit, dist, i);

		result = max(result, dist[x] + x_dist[i]);
	}

	cout << result;
}
