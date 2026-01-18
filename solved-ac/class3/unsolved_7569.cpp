/*
BOJ No.7569
토마토
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int start_i,int start_j, vector<vector<int>>& box, int M, vector<vector<int>>& visited, bool& check, int N) {
	visited[start_i][start_j] = 1;
	if (box[start_i][start_j] == 1) {
		check = true;
	}



	if (start_i + 1 < box.size() && 
		start_i / N  == (start_i + 1) / N &&
		box[start_i+1][start_j] != -1 &&
		visited[start_i+1][start_j] == -1) {
		DFS(start_i + 1, start_j, box, M, visited, check, N);
	}

	if (start_i - 1 >= 0 && start_i / N == (start_i - 1) / N && box[start_i-1][start_j] != -1 && visited[start_i - 1][start_j] == -1) {
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

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int M, N, H;
	cin >> M >> N >> H;
	vector<vector<int>> box(N*H);
	vector<vector<int>> visited(N * H);

	for (int i = 0; i < N*H; i++) {
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
	
	int day = 0;
	stack<pair<int, int>> stk;
	while (1) {
		while (!stk.empty()) {
			box[stk.top().first][stk.top().second] = 1;
			stk.pop();
		}

		for (int i = 0; i < N * H; i++) {
			for (int j = 0; j < M; j++) {
				// 왼쪽
				if ( box[i][j] == 0 && ((j - 1 >= 0 && box[i][j - 1] == 1) ||
					(j + 1 < M && box[i][j + 1] == 1) ||
					(i - 1 >= 0 && i / N == (i - 1) / N && box[i - 1][j] == 1) ||
					(i + 1 < N * H && i / N == (i + 1) / N && box[i + 1][j] == 1) ||
					(i + N < N * H && box[i + N][j] == 1) ||
					(i - N >= 0 && box[i - N][j] == 1))
					) {
					box[i][j] = 2;
					stk.push({ i,j });
					continue;
				}
			}
		}

		// 익은 토마토가 없다면
		if (stk.empty()) {
			break;
		}

		day++;
	}
	cout << day;
}
