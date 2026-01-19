/*
BOJ No. 7576
토마토
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

void BFS(vector<vector<int>>& box, vector<vector<int>>& visit ,queue<pair<int, int>>& q, int &day) {

	vector<vector<int>> depth(box.size(), vector<int>(box[0].size(), 0));
	
	while (!q.empty()) {
		int idx = q.front().first;
		int jdx = q.front().second;
		q.pop();

		day = max(day, depth[idx][jdx]);

		for (int i = 0; i < 4; i++) {
			int connect_i = idx + di[i];
			int connect_j = jdx + dj[i];

			if (connect_i >= 0 && connect_i < box.size() && connect_j >= 0 && connect_j < box[connect_i].size()&&
				box[connect_i][connect_j] == 0 && visit[connect_i][connect_j] == -1
				) {
				visit[connect_i][connect_j] = 1;
				box[connect_i][connect_j] = 1;
				depth[connect_i][connect_j] = depth[idx][jdx] + 1;
				q.push({ connect_i,connect_j });
			}

		}
	}
}

int main() {
	int M, N;
	cin >> M >> N;
	vector<vector<int>> box(N, vector<int>(M,0)); // N*M Matrix 한 번에 초기화
	vector<vector<int>> visit(N, vector<int>(M, -1)); // visit
	queue<pair<int, int>> q;
	

	for (int i = 0; i < box.size(); i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}

	int day = 0;
	BFS(box, visit, q, day);

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
