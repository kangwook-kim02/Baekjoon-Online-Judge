/*
BOJ No.1504
특정한 최단 경로
*/
/*
다익스트라 3번 돌려서 풀 수 있음
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra(int start, vector<vector<pair<int,int>>>& graph, vector<bool>& visit, vector<int>& dist) {
	dist[start] = 0;
	pq.push({ 0,start });
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

	for (int i = 0; i < visit.size(); i++) {
		visit[i] = false;
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<bool> visit(n + 1, false);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	vector<int> dist_start(n + 1, 987654321);
	vector<int> dist_u(n + 1, 987654321);
	vector<int> dist_v(n + 1, 987654321);

	int u, v;
	cin >> u >> v;
	Dijkstra(1, graph, visit, dist_start);
	Dijkstra(u, graph, visit, dist_u);
	Dijkstra(v, graph, visit, dist_v);

	
	// 조건 처리를 잘 해야겠군 --> route1과 route2 모두 경로가 존재하지 않을 경우
	if ((dist_start[u] == 987654321 || dist_u[v] == 987654321 || dist_v[n] == 987654321) && 
		(dist_start[v] == 987654321 || dist_v[u] == 987654321 || dist_u[n] == 987654321)) {
		cout << -1;
		return 0;
	}


	long long route1 = dist_start[u] + dist_u[v] + dist_v[n];
	long long route2 = dist_start[v] + dist_v[u] + dist_u[n];
	cout << min(route1, route2);

}
