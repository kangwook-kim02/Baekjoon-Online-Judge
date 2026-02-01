/*
BOJ No.1916
최소 비용 구하기
다익스트라
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra(int src,vector<vector<pair<int,int>>>& graph, vector<int>& dist, vector<bool>& visit) {
	dist[src] = 0;
	pq.push({ dist[src],src }); // pop 연산을 할 때 first로 비교하므로, first에 dist로 삽입
	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curDist = pq.top().first;
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
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<int> dist(n + 1, 987654321); // INF로 초기화
	vector<bool> visit(n + 1, false); 

	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		graph[u].push_back({ v,cost });
	}

	int src, dst;
	cin >> src >> dst;
	Dijkstra(src, graph, dist, visit);
	cout << dist[dst];
}
