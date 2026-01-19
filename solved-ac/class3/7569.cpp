/*
BOJ No.7569
토마토
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(vector<vector<int>>& box, int M, vector<vector<int>>& visited, int N, int &day, queue<pair<int,int>> &q) {
	
	vector<vector<int>> depth(box.size());
	for (int i = 0; i < depth.size(); i++) {
		for (int j = 0; j < M; j++) {
			depth[i].push_back(0);
		}
	}

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		day = max(day, depth[i][j]);
		q.pop();

		if (i + 1 < box.size() &&
			i / N == (i + 1) / N &&
			box[i + 1][j] != -1 &&
			visited[i + 1][j] == -1) {
			box[i + 1][j] = 1;
			visited[i + 1][j] = 1;
			q.push({ i + 1,j });
			depth[i + 1][j] = depth[i][j] + 1;
		}

		if (i - 1 >= 0 && i / N == (i - 1) / N && box[i - 1][j] == 0 && visited[i - 1][j] == -1) {
			box[i - 1][j] = 1;
			visited[i - 1][j] = 1;
			q.push({ i - 1,j });
			depth[i - 1][j] = depth[i][j] + 1;
		}

		if (j - 1 >= 0 && box[i][j - 1] == 0 && visited[i][j - 1] == -1) {
			box[i][j-1] = 1;
			visited[i][j-1] = 1;
			q.push({ i ,j-1 });
			depth[i][j - 1] = depth[i][j] + 1;
		}

		if (j + 1 < M && box[i][j + 1] == 0 && visited[i][j + 1] == -1) {
			box[i][j+1] = 1;
			visited[i][j+1] = 1;
			q.push({ i,j+1 });
			depth[i][j + 1] = depth[i][j] + 1;
		}

		if (i - N >= 0 && box[i - N][j] == 0 && visited[i - N][j] == -1) {
			box[i - N][j] = 1;
			visited[i - N][j] = 1;
			q.push({ i - N,j });
			depth[i - N][j] = depth[i][j] + 1;
		}

		if (i + N < box.size() && box[i + N][j] == 0 && visited[i + N][j] == -1) {
			box[i +N][j] = 1;
			visited[i + N][j] = 1;
			q.push({ i + N,j });
			depth[i + N][j] = depth[i][j] + 1;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int M, N, H;
	cin >> M >> N >> H;
	vector<vector<int>> box(N * H);
	vector<vector<int>> visited(N * H);

	for (int i = 0; i < N * H; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			box[i].push_back(num);
			visited[i].push_back(-1);
		}
	}

	// BFS로 day값 계산
	int day = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < box.size(); i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 1 && visited[i][j] == -1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	BFS(box, M, visited, N, day, q);

	for (int i = 0; i < box.size(); i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				day = -1;
				break;
			}
		}
		if (day == -1) {
			break;
		}
	}
	
	cout << day;
}
