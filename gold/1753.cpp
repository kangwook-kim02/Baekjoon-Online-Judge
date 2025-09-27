#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

void Dijkstra(int start, int* visit, int* dist, vector<vector<pair<int, int>>> &graph , int v) {
	dist[start] = 0; // start의 distance를 0으로 둔다
	pq.push({0, start});

	// vertex의 개수가 v개 인데, 이미 시작 정점은 초기화 했으니까 v-1번 반복 진행
	while(!pq.empty()) {
		// 최소 Distance가 누구인지 찾는 알고리즘
		int minDist, minIdx; 
		pair<int, int> p = pq.top();
		pq.pop();
		if (visit[p.second] == 1) continue;

		minDist = p.first;
		minIdx = p.second;


		visit[minIdx] = 1; // 해당 노드가 있으면 방문
		int curdist = dist[minIdx]; // 시작 정점에서 minIdx까지의 거리

		for (int j = 1; j < graph[minIdx].size(); j++) { // minIdx로부터 이웃한 엣지들을 다 구해서

			if (visit[graph[minIdx][j].first] == 1) continue; // 방문했으면 찾아갈 필요 없음

			if (dist[graph[minIdx][j].first] > curdist + graph[minIdx][j].second) { // dist가 더 작으면 갱신
				dist[graph[minIdx][j].first] = curdist + graph[minIdx][j].second;
				pq.push({ curdist + graph[minIdx][j].second, graph[minIdx][j].first });
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);


	int v;
	int e;

	cin >> v >> e;
	int start;
	cin >> start;

	int inf = 987654321;
	int* dist = new int[v+1];
	int* visit = new int[v+1];

	for (int i = 1; i <= v; i++) {
		dist[i] = inf; // 각각 최댓값을 삽입
	}

	for (int i = 1; i <= v; i++) {
		visit[i] = 0; // visit 여부
	}

	vector<vector<pair<int, int>>> graph;
	for (int i = 0; i <= v; i++) {
		vector<pair<int, int>> v;
		v.push_back({ -1,-1 });
		graph.push_back(v);
	}

	for (int i = 0; i < e; i++) {
		int u;
		int v;
		int w;

		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	Dijkstra(start, visit, dist, graph, v);

	for (int i = 1; i <= v; i++) {
		if (dist[i] == 987654321) {
			cout << "INF" << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}