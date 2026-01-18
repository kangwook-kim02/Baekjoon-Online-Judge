/*
BOJ No.7569
토마토
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(int start_i, int start_j, vector<vector<int>>& box, int M, vector<vector<int>>& visited, bool& check, int N) {
	visited[start_i][start_j] = 1;
	if (box[start_i][start_j] == 1) {
		check = true;
	}



	if (start_i + 1 < box.size() &&
		start_i / N == (start_i + 1) / N &&
		box[start_i + 1][start_j] != -1 &&
		visited[start_i + 1][start_j] == -1) {
		DFS(start_i + 1, start_j, box, M, visited, check, N);
	}

	if (start_i - 1 >= 0 && start_i / N == (start_i - 1) / N && box[start_i - 1][start_j] != -1 && visited[start_i - 1][start_j] == -1) {
		DFS(start_i - 1, start_j, box, M, visited, check, N);
	}

	if (start_j - 1 >= 0 && box[start_i][start_j - 1] != -1 && visited[start_i][start_j - 1] == -1) {
		DFS(start_i, start_j - 1, box, M, visited, check, N);
	}

	if (start_j + 1 < M && box[start_i][start_j + 1] != -1 && visited[start_i][start_j + 1] == -1) {
		DFS(start_i, start_j + 1, box, M, visited, check, N);
	}

	if (start_i - N >= 0 && box[start_i - N][start_j] != -1 && visited[start_i - N][start_j] == -1) {
		DFS(start_i - N, start_j, box, M, visited, check, N);
	}

	if (start_i + N < box.size() && box[start_i + N][start_j] != -1 && visited[start_i + N][start_j] == -1) {
		DFS(start_i + N, start_j, box, M, visited, check, N);
	}

}

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

	// 토마토가 모두 익지 못하는 상황 --> DFS로 1을 갖는 토마토 파악하기
	for (int i = 0; i < box.size(); i++) {
		for (int j = 0; j < M; j++) {
			bool check = false;
			if (box[i][j] != -1 && visited[i][j] == -1) {
				DFS(i, j, box, M, visited, check, N);
				if (check == false) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	bool check = true;
	for (int i = 0; i < box.size(); i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				check = false;
				break;
			}
		}
	}

	if (check) {
		cout << "0";
		return 0;
	}

	// visited 초기화
	for (int i = 0; i < N * H; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = -1;
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
	
	cout << day;
}
