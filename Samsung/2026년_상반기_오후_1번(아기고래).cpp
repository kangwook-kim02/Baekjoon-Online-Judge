/*
아기 고래의 첫 향해


깨달은 점
- visit을 통해서 while을 체크하게 된 경우, cout은 while 끝나기 전에 항상 두어야함.
- 만약 시작할 때 cout을 둔다면 (즉, visit 함수 true 하고 while 문이 끝난 후 cout을 하는 경우) visit으로 인해 마지막 cur_i와 cur_j가 cout되지 않을 수 있음.
- 따라서 cout은 적어도 visit 직후에 작성을 하는 것이 좋을듯 싶음.
- 또한 이 부분에서 방향에 대해서는 공통적으로 처리할 수 있도록 작성해야함. 그렇지 않으면 나중에 디버깅할 때 말이 안될 수도 있음.
  * 이 부분은 규칙이 존재함 (규칙을 찾아내는 연습은 내가 직접 여러번 해야할 듯)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,-1,0,1 };

// 시뮬레이션 종료 함수 --> 모두 방문했는지 안했는지
// 추후에 카운트로 관리할 수도 있지 않을까??
bool isEnd(vector<vector<bool>>& visit) {
	for (int i = 0; i < visit.size(); i++) {
		for (int j = 0; j < visit.size(); j++) {
			if (!visit[i][j]) {
				return false;
			}
		}
	}
	return true;
}

// BFS로 Dist를 구해야 중간에 벽을 만나도 넘어갈 수 있음.
// 만약 단순 cur_i - new_i 차이로만 구한다면 벽을 무시하는 경우임..
// 바다에서 현재 위치를 기준으로 모든 바다의 거리를 구해놓고 --> 실제로 바다이면서 방문 가능한 곳에서 min 값을 추출한다.
// min 값을 추출하는 이유는 뒤에 min 값을 통해 방문할 바다를 찾기 위함임.
// (행이 작은 순, 열이 작은 순) --> 그러면 그냥 순회해서 min 값과 동일한 경우를 찾으면 됨.
int updateDistandGetMin(vector<vector<bool>>& realVisit, vector<vector<int>>& sea, vector<vector<int>>& dist, int cur_i, int cur_j) {
	int N = sea.size();
	vector<vector<bool>> visit(N, vector<bool>(N, false));
	queue<pair<pair<int, int>, int>> q;
	q.push({{cur_i,cur_j}, 0});
	int d_i[4] = { 0,0,-1,1 };
	int d_j[4] = { -1,1,0,0 };
	while (!q.empty()) {
		cur_i = q.front().first.first;
		cur_j = q.front().first.second;
		int dis = q.front().second;
		dist[cur_i][cur_j] = dis;
		q.pop(); // pop이 없으면 무한루프에 걸릴 수도 있음
		// pop을 까먹고 안쓰는 경우가 종종 있음. --> 무한 루프
		// 그러면 실전에선? 무한루프 --> pop()을 안했나? 생각하기
		
		for (int i = 0; i < 4; i++) {
			int new_i = cur_i + d_i[i];
			int new_j = cur_j + d_j[i];

			// 새로운 좌표를 받았으면 항상 배열에서는 범위 체크(조건 검사) 하는 것이 중요
			if (new_i >= 0 && new_i < N && new_j >= 0 && new_j < N &&
				!visit[new_i][new_j] && sea[new_i][new_j] == 0) {
				visit[new_i][new_j] = true;
				q.push({ {new_i,new_j},dis + 1 });
			}
		}
	}
	
	//getMin
	int min = 9999999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!realVisit[i][j] && sea[i][j] == 0 && min > dist[i][j]) {
				min = dist[i][j];
			}
		}
	}

	return min;
}

// BFS를 통한 탐사
// 탐사의 목적을 정확히 알아야함
// 이미 가야할 곳은 알았으나, 방향만 모르는 상태 --> 목적지에 도착했을 때 방향을 구하기 위해 탐사를 진행하는 것.
int BFS(int cur_i, int cur_j, int direction ,vector<vector<int>>& sea, int target_i, int target_j) {
	queue<pair<pair<int, int>, int>> q;
	int N = sea.size();
	vector<vector<bool>> visit(N, vector<bool>(N, false));
	q.push({ {cur_i,cur_j}, direction });
	visit[cur_i][cur_j] = true;

	// 좌 하 우 상 (문제 조건)
	int d_i[4] = {0,1,0,-1};
	int d_j[4] = { -1,0,1,0 };
	int d[4] = { 3,2,4,1 }; // 해당 방향으로 갔을 떄 바라보고 있는 방향

	while (!q.empty()) {
		cur_i = q.front().first.first;
		cur_j = q.front().first.second;
		direction = q.front().second;
		q.pop(); // pop이 중요

		// 가장 먼저 발견한 경우
		if (cur_i == target_i && cur_j == target_j) {
			return direction;
		}


		for (int i = 0; i < 4; i++) {
			int new_i = cur_i + d_i[i];
			int new_j = cur_j + d_j[i];

			if (new_i >= 0 && new_i < N && new_j >= 0 && new_j < N &&
				sea[new_i][new_j] == 0 && !visit[new_i][new_j]) {
				q.push({ {new_i,new_j},d[i] });
				visit[new_i][new_j] = true;
			}
		}

	}

	return -1;

}

int main() {
	int N, r, c, d;
	cin >> N >> r >> c >> d;

	vector<vector<int>> sea(N, vector<int>(N));
	// 0이면 not viist, others: visit
	vector<vector<bool>> visit(N, vector<bool>(N, false));


	// 처리 실패
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sea[i][j];
			if (sea[i][j] == 1) {
				visit[i][j] = true;
			}
		}
	}

	// 현재 위치 (문제 기준에 맞춰서 r-1, c-1을 진행함)
	int cur_i = r-1;
	int cur_j = c-1;
	visit[cur_i][cur_j] = true;;
	int count = 2;
	cout << cur_i + 1 << " " << cur_j + 1 << "\n";
	vector<vector<int>> dist(N, vector<int>(N, 99999));
	while (!isEnd(visit)) {
		// =======================
		// 인접 탐험인 경우 (1단계)
		// =======================
		
		// 배열에 직진 위치에 맞게 d 값을 transform 진행함
		int transD = -1;
		if (d == 1) {
			transD = 0;
		}
		else if (d == 2) {
			transD = 2;
		}
		else if (d == 3) {
			transD = 1;
		}
		else if (d == 4) {
			transD = 3;
		}
		int next_i;
		int next_j;
		bool checkMove = false;
		for (int i = 0; i < 4; i++) {
			int x = i;
			if (x == 2) {
				x = 3;
			}
			else if (x == 3) {
				x = 2;
			}

			next_i = cur_i + di[(transD + x) % 4];
			next_j = cur_j + dj[(transD + x) % 4];

			if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < N &&
				sea[next_i][next_j] == 0 && !visit[next_i][next_j]) {
				//visit[next_i][next_j] = true; --> 얘땜에 마지막에 true가 되면 cout을 못할 수 있으니, cout을 처음에 하기 보단 마지막에 cout을 하는 것으로 고쳐야겠다.
				
				if (((transD + x) % 4) == 0) {
					d = 1;
				}
				else if (((transD + x) % 4) == 1) {
					d = 3;
				}
				else if (((transD + x) % 4) == 2) {
					d = 2;
				}
				else if (((transD + x) % 4) == 3) {
					d = 4;
				}

				cur_i = next_i;
				cur_j = next_j;
				checkMove = true;
				break;
			}
		}

		if (checkMove) {
			visit[cur_i][cur_j] = true;
			cout << cur_i + 1 << " " << cur_j + 1 << "\n";
			continue;
		}

		// ======================================
		// 가장 가까운 바다로 이동인 경우 (2단계)
		// ======================================
		
		// 가장 가까운 바다와의 거리 update Distance를 잘못구했었네
		// 최솟값도 무조건 BFS로 구했어야 했다.
		int min = updateDistandGetMin(visit, sea, dist, cur_i, cur_j);
		int new_i = -1;
		int new_j = -1;
		// 어디로 가야하는지 열 구하기
		bool check = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && sea[i][j] == 0 && dist[i][j] == min) {
					new_i = i;
					new_j = j;
					check = true;
					break;
				}
			}
			if (check) break;
		}
		
		// BFS로 탐사를 진행해야함
		d = BFS(cur_i, cur_j, d, sea, new_i, new_j);
		cur_i = new_i;
		cur_j = new_j;
		visit[cur_i][cur_j] = true;
		cout << cur_i + 1 << " " << cur_j + 1 << "\n";
	}
}
