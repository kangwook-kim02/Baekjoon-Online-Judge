#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// 우, 하, 좌, 상
int dx[4] = {0, 1, 0, -1}; // row
int dy[4] = {1, 0, -1, 0}; // column

// 바다거북 이동, BFS로 구현
// q의 second에 전체 이동 경로를 넣을 필요 없이, 처음 이동 경로만 넣으면 좋을 것 같음. --> 메모리 낭비 방지
// 혹시라도 메모리 초과가 발생한다면 처음 이동 경로만 넣어보자
int turtle_move(vector<vector<int>>& sea, int r, int c) {
	int N = sea.size();
	vector<vector<bool>> visit(N, vector<bool>(N, false));
	queue<pair<pair<int, int>, vector<int>>> q;
	vector<int> pos;
	q.push({ {r,c},pos });
	visit[r][c] = true;
	while (!q.empty()) {
		int cur_r = q.front().first.first;
		int cur_c = q.front().first.second;
		vector<int> cur_pos = q.front().second;
		q.pop();

		if (cur_r == N - 1 && cur_c == N - 1) {
			return cur_pos[0];
		}

		for (int i = 0; i < 4; i++) {
			// 주의할 점: r,c 구분 잘하기
			int new_r = cur_r + dx[i];
			int new_c = cur_c + dy[i];

			if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N &&
				!visit[new_r][new_c] && sea[new_r][new_c] != 1 && sea[new_r][new_c] != 2 && sea[new_r][new_c] != 3) {
				vector<int> new_pos = cur_pos;
				new_pos.push_back(i);
				visit[new_r][new_c] = true;
				q.push({ {new_r,new_c},new_pos });
			}
		}

	}
	// 안식처에 도달하지 못한다면 -1을 반환
	return -1;
}

// 열기 전파
void smoke(vector<vector<int>> &temp_sea, vector<vector<int>> &sea, int r, int c, int p) {
	int temp_p = p;
	temp_sea[r][c] += temp_p;
	int N = temp_sea.size();

	// 상으로 퍼져나가기
	for (int i = r-1; i >= 0; i--) {
		temp_p = temp_p / 2;
		if (temp_p == 0 || sea[i][c] == 1) {
			break;
		}
		temp_sea[i][c] = temp_sea[i][c] + temp_p;
	}
	temp_p = p;
	
	// 하로 퍼져나가기
	for (int i = r+1; i < N; i++) {
		temp_p = temp_p / 2;
		if (temp_p == 0 || sea[i][c] == 1) {
			break;
		}
		temp_sea[i][c] = temp_sea[i][c] + temp_p;
	}
	temp_p = p;

	// 좌로 퍼져나가기
	for (int i = c - 1; i >= 0; i--) {
		temp_p = temp_p / 2;
		if (temp_p == 0 || sea[r][i] == 1) {
			break;
		}
		temp_sea[r][i] = temp_sea[r][i] + temp_p;
	}
	temp_p = p;

	// 우로 퍼져나가기
	for (int i = c + 1; i < N; i++) {
		temp_p = temp_p / 2;
		if (temp_p == 0 || sea[r][i] == 1) {
			break;
		}
		temp_sea[r][i] = temp_sea[r][i] + temp_p;
	}
	
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	// 0: 빈 공간, 1: 산호초, 2:바다거북, 3: 화석, 4: 화산
	vector<vector<int>> sea(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sea[i][j];
		}
	}

	// index가 거북이의 ID
	vector<pair<int, int>> turtle;
	vector<int> timestamp_turtle(M, -1); // 거북이가 안식처에 도달한 시간
	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		sea[r][c] = 2;
		turtle.push_back({ r,c });
	}

	vector<pair<int, int>> hwasan;
	vector<int> hwasan_threshold;
	vector<int> hwasan_p;
	for (int i = 0; i < K; i++) {
		int r, c, p;
		cin >> r >> c >> p;
		hwasan.push_back({ r,c });
		sea[r][c] = 4;
		hwasan_threshold.push_back(p);
		hwasan_p.push_back(0);
	}
	int turn = 0;
	while (turn <= 100) {
		turn++;

		// STEP 1 바다거북 이동
		for (int i = 0; i < M; i++) {
			int r = turtle[i].first;
			int c = turtle[i].second;

			// 안식처에 도착했다면 패스
			if (r == N - 1 && c == N - 1) continue;

			// 최단거리를 가려면 어느 방향으로 가야할지 pos에 저장
			int pos = turtle_move(sea, r, c);

			// 최단경로가 존재한다면
			if (pos != -1) {
				int new_r = r + dx[pos];
				int new_c = c + dy[pos];
				sea[r][c] = 0;
				sea[new_r][new_c] = 2;

				// 지도에서 즉시 제외
				if (new_r == N - 1 && new_c == N - 1) {
					timestamp_turtle[i] = turn;
					sea[new_r][new_c] = 0;
				}
				turtle[i].first = new_r;
				turtle[i].second = new_c;
			}
		}

		// STEP 2 화산 압력 증가
		vector<int> explosion_hwasan;
		set<int> s;
		for (int i = 0; i < hwasan_p.size(); i++) {
			hwasan_p[i] += 10;
			// 분출 임계치를 넘으면, 뜨거운 열기 분출
			if (hwasan_p[i] >= hwasan_threshold[i]) {
				explosion_hwasan.push_back(i);
				s.insert(i);
			}
		}
		
		// STEP 3 화산 분출 및 연쇄 반응

		vector<vector<int>> temp_sea(N, vector<int>(N, 0)); // 열기를 저장해야함. 
		// 1. 열기 전파
		for (int i = 0; i < explosion_hwasan.size(); i++) {
			int idx = explosion_hwasan[i];
			int r = hwasan[idx].first;
			int c = hwasan[idx].second;
			int p = hwasan_threshold[idx];

			smoke(temp_sea, sea, r, c, p);
		}

		int end_idx = explosion_hwasan.size();
		// 2. 연쇄 반응
		while (1) {
			bool check = false;

			// 연쇄반응에 참여할 화산
			for (int i = 0; i < hwasan.size(); i++) {
				int r = hwasan[i].first;
				int c = hwasan[i].second;
				int fire = temp_sea[r][c];
				if (fire + hwasan_p[i] >= hwasan_threshold[i]) {
					int size = s.size();
					s.insert(i);
					int after_size = s.size();

					// 폭발하지 않는 화산이라면 다시 폭발할 화산에 넣어야함
					if (after_size > size) {
						check = true;
						explosion_hwasan.push_back(i);
					}
				}
			}

			if (!check) {
				break;
			}

			for (int i = end_idx; i < explosion_hwasan.size(); i++) {
				int idx = explosion_hwasan[i];
				int r = hwasan[idx].first;
				int c = hwasan[idx].second;
				int p = hwasan_threshold[idx];

				smoke(temp_sea, sea, r, c, p);
			}

			end_idx = explosion_hwasan.size();
		}


		// 3. 화석화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (temp_sea[i][j] >= 20 && sea[i][j] == 2) {
					sea[i][j] = 3;
					for (int k = 0; k < turtle.size(); k++) {
						if (turtle[k].first == i && turtle[k].second == j) {
							turtle[k].first = N - 1;
							turtle[k].second = N - 1;
							break;
						}
					}
				}
			}
		}
		
		// reset
		for (int i = 0; i < explosion_hwasan.size(); i++) {
			int idx = explosion_hwasan[i];
			hwasan_p[idx] = 0;
		}

	}

	for (int i = 0; i < timestamp_turtle.size(); i++) {
		cout << timestamp_turtle[i] << "\n";
	}
}

