/*
AI 로봇청소기


이 문제를 내가 잘 풀지 못한 이유

1. BFS를 사용해서 우선순위를 두면 될 거라고 생각했지만,
행 열을 기준으로 우선순위를 물어볼 경우 실제로 가장 가까운 격자 위치를 다 갖고 와서
행 열 조건을 따져야한다.
나는 처음에 행이 작은 순, 열이 작은 순이여서 우선 순위가 상,좌,우,하로 처리하면 되는 줄 알았으나 그 순으로 뽑은게 행이 항상 작고 열이 항상 작다고 가정할 수 없다.
-- 왜?
아 그러면 방향에 우선순위가 있냐

아니면 목적지 자체에 우선순위가 있냐에 따라 풀이가 달라진다는거네?
삼성 코테에서 만약
최단 거리가 동일하다면, (좌,우,상,하)순으로 객체를 이동해라 라는 말이 있으면 --> 그냥 dx dy 해가지고 배열 처리로 진행을 하면 된다는 것이고,
목적지 자체에 우선순위가 있으면 그냥 가능한 최단거리 다 찾아서 목적지들에 조건 중 가장 적합한 목적지를 뽑아야 된다는 거네?

"가장 가까운 격자가 여러 개일 경우 행 번호가 작은 격자로 이동하고, 행 번호가 같을 경우에는 열 번호가 작은 격자로 이동합니다."
--> 목적지가 여러 개인 상황이면서, 목적지의 조건을 주는 경우
--> 목적지의 조건이 (행, 열에 대해 제안)

"최단 경로가 여러 개라면 우(→), 하(↓), 좌(←), 상(↑) 순서로 우선순위를 두어 첫 이동 방향을 결정합니다."
--> 방향에 우선 순위를 주었음: 우,하,좌,상
========================

2. 방향 조건을 잘못이해했다. 나는 처음에 먼지의 양을 다 더해서 가장 큰 것을 구하면 되는 줄 알았지만, 그게 아니라
최대 청소가능한 양이 20이니까 각 격자당 최대 20을 기준으로 더해서 가장 큰 것을 구해야 했다.

3. 확산조건을 잘못이해했다. 처음에 나는 각 격자에 대해서 확산된 값을 나누기 10한 몫을 다 더하면 되는구나 싶었지만 문제에서는 그게 아닌,
각 확산된 값에 대해 다 더한 후 나누기 10을 했어야 했다.

4. dc[4] dr[4]를 사용하여 새로운 좌표값을 찾을 떄 정말 new_c = cur_c + dc[i], new_r = cur_r + dr[i] 인지도 검토해야한다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 상, 좌, 우, 하 (우선순위)
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

// 청소 방향 우선순위 (우하좌상)
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) return a.first < b.first;

	return a.second < b.second;
}

// 비효율적인 풀이인 것 같다는 생각이 들음
// 만약 시간 초과가 생긴다면, 먼지 자체를 새로운 gird에 두어서 제거하면 될 것 같다는 생각이 들음.
void robot_move(vector<vector<int>> &grid, vector<pair<int,int>> &robot, vector<pair<int,int>> &dust, int idx) {
	// 현재 위치 오염 여부 파악
	// 먼지가 있을 수도 있다는 사실, grid에서는 로봇이 먼지를 덮어쓰는 상황으로 코딩함 (벽의 역할로 인해서..)
	// --> 현재 위치에서 오염이 생긴다면 로봇을 움직일 필요가 없음.
	int r = robot[idx].first;
	int c = robot[idx].second;
	for (int i = 0; i < dust.size(); i++) {
		int dust_r = dust[i].first;
		int dust_c = dust[i].second;

		if (r == dust_r && c == dust_c) {
			return;
		}
	}

	int N = grid.size();
	vector<vector<bool>> visit(N, vector<bool>(N, false));
	queue<pair<pair<int,int>, int>> q;
	q.push({{r,c}, 0});
	visit[r][c] = true;
	vector<pair<int, int>> result;
	int cri_dist = 0;
	
	while (!q.empty()) {
		int cur_r = q.front().first.first;
		int cur_c = q.front().first.second;
		int dist = q.front().second;
		q.pop(); // 이거 가끔 pop을 내가 쓰지 않는 실수가 있어서 --> infinite Loop에 걸림

		// 가장 가까운 위치에 먼지가 존재한다면
		if (grid[cur_r][cur_c] == 1) {
			if (result.empty()) {
				result.push_back({ cur_r,cur_c });
				cri_dist = dist;
			}
			else {
				if (dist == cri_dist) {
					result.push_back({ cur_r,cur_c });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int new_r = cur_r + dx[i];
			int new_c = cur_c + dy[i];

			if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N &&
				!visit[new_r][new_c] && grid[new_r][new_c] != -1 && grid[new_r][new_c] != 2) {
				q.push({ {new_r, new_c}, dist+1});
				visit[new_r][new_c] = true;
			}
		}
	}

	// 로봇이 움직일 곳이 없다면 --> 안움직인다.
	if (result.empty()) {
		return;
	}
	
	sort(result.begin(), result.end(), comp); // comp 함수 만들어야함.
	grid[r][c] = 0;
	robot[idx].first = result[0].first;
	robot[idx].second = result[0].second;
	grid[result[0].first][result[0].second] = 2;
}

int select_direction(vector<vector<int>> &grid, vector<pair<int,int>> &dust, vector<int> &amount_dust, int r, int c) {
	int N = grid.size();
	// 0 --> 우
	// 1 --> 하
	// 2 --> 좌
	// 3 --> 상
	int max = 0;
	int pos = -1;
	for (int i = 0; i < 4; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			int new_r = r + dr[(i + 3 + j) % 4];
			int new_c = c + dc[(i + 3 + j) % 4];

			// 먼지가 있다면?
			if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N &&
				grid[new_r][new_c] != 0 && grid[new_r][new_c] != -1) {
				for (int k = 0; k < dust.size(); k++) {
					int dust_r = dust[k].first;
					int dust_c = dust[k].second;
					if (dust_r == new_r && dust_c == new_c) {
						if (amount_dust[k] > 20) {
							sum += 20;
						}
						else {
							sum += amount_dust[k];
						}
						break;
					}
				}
			}
		}

		// max를 넣어버리지 않는 실수를 했다..
		if (max < sum) {
			max = sum;
			pos = i;
		}
	}

	// pos가 -1이라면 청소할 필요가 없다는 뜻임
	return pos;
}

// r,c 위치 청소시키기
void clean_grid(vector<vector<int>> &grid, vector<pair<int,int>> &dust, vector<int> &amount_dust ,int r, int c) {
	int idx = -1;
	for (int i = 0; i < dust.size(); i++) {
		int dust_r = dust[i].first;
		int dust_c = dust[i].second;
		if (r == dust_r && c == dust_c) {
			idx = i;
			break;
		}
	}

	// -1이라는 뜻은 현재 위치는 먼지가 없다는 뜻임.
	if (idx != -1) {
		if (amount_dust[idx] > 20) {
			amount_dust[idx] = amount_dust[idx] - 20;
			return;
		}
		
		// bug fix
		amount_dust[idx] = 0; 
		dust.erase(dust.begin() + idx);
		amount_dust.erase(amount_dust.begin() + idx);
		if (grid[r][c] == 1) {
			grid[r][c] = 0;
		}
	}
}

int main() {
	int N, K, L;
	cin >> N >> K >> L;
	
	// -1: 물건, 0: 빈공간, 1: 먼지, 2: 청소기
	vector<vector<int>> grid(N, vector<int>(N, 0));
	vector<pair<int, int>> dust; // 먼지의 위치를 저장
	vector<int> amount_dust;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if (input >= 1) {
				grid[i][j] = 1; // 좌표 위에 먼지가 있다면 --> 1로 표시
				dust.push_back({ i,j });
				amount_dust.push_back(input);
				continue;
			}

			grid[i][j] = input;
		}
	}
	
	vector<pair<int, int>> robot; // 로봇 청소기 좌표 정보
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		r--;
		c--;
		robot.push_back({ r,c });
		grid[r][c] = 2; // 좌표 위에 청소기를 놓기
	}
	
	while (L--) {
		// 1. 청소기 이동
		for (int i = 0; i < robot.size(); i++) {
			robot_move(grid, robot, dust, i);
		}


		// 2. 청소
		for (int i = 0; i < robot.size(); i++) {
			int r = robot[i].first;
			int c = robot[i].second;
			int pos = select_direction(grid, dust, amount_dust, r, c);
			clean_grid(grid, dust, amount_dust, r, c); // 현재 위치는 무조건 청소한다고 가정
			if (pos != -1) {
				// 실제 청소 진행
				for (int j = 0; j < 3; j++) {
					int new_r = r + dr[(pos + 3 + j) % 4];
					int new_c = c + dc[(pos + 3 + j) % 4];
					if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N &&
						grid[new_r][new_c] != -1 && grid[new_r][new_c] != 0
						) {
						clean_grid(grid, dust, amount_dust, new_r, new_c);
					}
				}
				
			}
		}

		
		// 3. 먼지 축적
		for (int i = 0; i < amount_dust.size(); i++) {
			amount_dust[i] = amount_dust[i] + 5;
		}

		// 4. 먼지 확산

		// 먼지 확산을 위한 초기 작업
		vector<vector<int>> temp_grid(N, vector<int>(N, 0));
		for (int i = 0; i < dust.size(); i++) {
			int r = dust[i].first;
			int c = dust[i].second;
			temp_grid[r][c] = amount_dust[i];
		}

		// 먼지 확산
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (grid[i][j] == 0 || grid[i][j] == 2) {

					int check = true;
					// 로봇 청소기 자리에 먼지가 있다면 해당 격자로 확산될 수 없음
					if (grid[i][j] == 2 && temp_grid[i][j] != 0) {
						check = false;
					}

					if (!check) continue;

					int sum = 0;
					for (int k = 0; k < 4; k++) {
						int new_r = i + dx[k];
						int new_c = j + dy[k];
						if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N) {
							sum = sum + temp_grid[new_r][new_c];
						}
					}

					sum = sum / 10;
					if (sum > 0) {
						dust.push_back({ i,j });
						amount_dust.push_back(sum);
						if (grid[i][j] == 0) {
							grid[i][j] = 1;
						}
					}
				}
			}
		}

		int result = 0;
		for (int i = 0; i < amount_dust.size(); i++) {
			result += amount_dust[i];
		}
		cout << result << "\n";
		
	}
}
