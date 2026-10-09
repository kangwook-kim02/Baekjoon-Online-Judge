/*
택배하차

느낀점: 시뮬레이션 디버깅 하는 법에 대해서 이번 기회에 연습할 수 있었음.

시뮬레이션 디버깅은 사실 브레이크 포인트 찍어서 F10 하나하나 디버깅 하는거? 사실 말이 안됨.
그렇기에 나는 전체 격자 상황을 함수로 작성 - 여기선 test() 함수
그리고 어디가 틀린지 모를 때, test() 함수로 STEP 마다 찍어서
실제 시뮬레이션이 문제 상황과 동일하게 일어나는지 찍어보았음.

그럼 실전에서는 어떻게 해야하냐.
혹시라도 TC 10개를 다 맞췄다는 가정하에 바로 제출하지 말고,
각 스텝마다 상황을 찍어본 후 정말 문제 상황과 동일하게 정상적으로 동작하는지 확인하면 됨.

또한 이번 문제에서 깨달은 건
입력 변수가 k 가 있었다는 거임.
k 때문에 3중 포문을 돌게 되었을 때, k 변수가 섞여 활용될 수 있음.
나는 이걸 바로 알아차려서 이문제에는 크게 고생하지 않았지만, 실전에서는 다를 수 있음.
따라서 k --> b_k 이런식으로 쓰는 연습이 필요함.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test(vector<vector<int>> &grid) {
	int N = grid.size();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << grid[i][j];
		}
		cout << "\n";
	}
}


// r --> 현재 상자의 최상단 높이, c --> 제일 왼쪽 열 
// 디버깅 완료 --> 잘 동작하는 것을 확인함.
int gravity(vector<vector<int>> &grid, int k, int h, int w, int r, int c) {
	int N = grid.size();
	int check_r = r + h; // 검사할 행
	bool can_down = true;


	
	// 만약 내려갈 수 있으면 계속 내려감
	while (can_down) {
		if (check_r >= N) {
			can_down = false;
			break;
		}

		for (int i = 0; i < w; i++) {
			if (check_r < N && grid[check_r][c + i] != 0) {
				can_down = false;
			}
		}

		// 실제로 한 칸 내려가는 알고리즘
		if (can_down) {
			for (int i = check_r; i > check_r - h; i--) {
				for (int j = 0; j < w; j++) {
					grid[i][c+j] = k;
				}
			}

			for (int i = 0; i < w; i++) {
				grid[r][c + i] = 0;
			}
			r++;
			check_r++;
		}
	}
	return r;
}

bool emptyLeft(vector<vector<int>> &grid, int k, int h, int w, int r, int c) {
	if (c == 0) return true;

	for (int i = r; i < r+h; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] != 0) return false;
		}
	}

	return true;

}

bool emptyRight(vector<vector<int>>& grid, int k, int h, int w, int r, int c) {
	int N = grid.size();
	if (c == N-1) return true;

	for (int i = r; i < r + h; i++) {
		for (int j = c+w; j < N; j++) {
			if (grid[i][j] != 0) return false;
		}
	}

	return true;

}

void del_box(vector<vector<int>>& grid, int k, int h, int w, int r, int c) {
	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
			grid[i][j] = 0;
		}
	}
}

bool comp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

void get_temp(vector<vector<int>>& grid, vector<int> &temp, int r, int c, int w) {
	// temp 순으로 gravitiy 처리하면 됨..
	int N = grid.size();
	for (int i = r - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] != 0) {
				bool check = true;
				for (int k = 0; k < temp.size(); k++) {
					if (temp[k] == grid[i][j]) {
						check = false;
						break;
					}
				}
				if (check) {
					temp.push_back(grid[i][j]);
				}

			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> grid(N, vector<int>(N, 0));
	vector<vector<int>> box;
	for (int i = 0; i < M; i++) {
		int k, h, w, c;
		cin >> k >> h >> w >> c;
		
		c = c - 1;
		

		// 택배 투입
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				grid[i][c+j] = k;
			}			
		}
		// 중력 작용
		int r = gravity(grid, k, h, w, 0, c);
		box.push_back({ k,h,w,r,c });

	}

	sort(box.begin(), box.end(), comp);

	while (!box.empty()) {
		//cout << "======= 현재 택배 상황 ==========" << "\n";
		//test(grid);
		//cout << "=================================" << "\n";
		// 택배 하차 (좌측) 
		for (int i = 0; i < box.size(); i++) {
			int k = box[i][0];
			int h = box[i][1];
			int w = box[i][2];
			int r = box[i][3];
			int c = box[i][4];

			if (emptyLeft(grid, k, h, w, r, c)) {
				del_box(grid, k, h, w, r, c);
				cout << k << "\n";
				box.erase(box.begin() + i);
				//cout << "======= 좌측 택배 뽑은 후 ==========" << "\n";
				//test(grid);
				//cout << "=================================" << "\n";
				vector<int> temp;

				// temp 순으로 gravitiy 처리하면 됨..
				get_temp(grid, temp, r, c, w);

				for (int j = 0; j < temp.size(); j++) {
					int b_k = temp[j];
					int b_h = -1;
					int b_w = -1;
					int b_r = -1;
					int b_c = -1;
					for (int m = 0; m < box.size(); m++) {
						if (box[m][0] == b_k) {
							b_h = box[m][1];
							b_w = box[m][2];
							b_r = box[m][3];
							b_c = box[m][4];
							b_r = gravity(grid, b_k, b_h, b_w, b_r, b_c);
							box[m][3] = b_r;
							break;
						}
					}
				}
				break;
			}
		}
		//cout << "======= 좌측 택배 하강 후==========" << "\n";
		//test(grid);
		//cout << "=================================" << "\n";

		// 택배 하차 우측
		for (int i = 0; i < box.size(); i++) {
			int k = box[i][0];
			int h = box[i][1];
			int w = box[i][2];
			int r = box[i][3];
			int c = box[i][4];

			if (emptyRight(grid, k, h, w, r, c)) {
				del_box(grid, k, h, w, r, c);
				cout << k << "\n";
				//cout << "======= 우축 택배 뽑은 후==========" << "\n";
				//test(grid);
				//cout << "=================================" << "\n";
				box.erase(box.begin() + i);
				vector<int> temp;

				// temp 순으로 gravitiy 처리하면 됨..
				get_temp(grid, temp, r, c, w);
				//cout << "gravitity 처리 후보" << "\n";
				//for (int i = 0; i < temp.size(); i++) {
				//	cout << temp[i] << " " << "\n";
				//}

				for (int j = 0; j < temp.size(); j++) {
					int b_k = temp[j];
					int b_h = -1;
					int b_w = -1;
					int b_r = -1;
					int b_c = -1;
					for (int m = 0; m < box.size(); m++) {
						if (box[m][0] == b_k) {
							b_h = box[m][1];
							b_w = box[m][2];
							b_r = box[m][3];
							b_c = box[m][4];
							b_r = gravity(grid, b_k, b_h, b_w, b_r, b_c);
							box[m][3] = b_r;
							break;
						}
					}
				}
				break;
			}

		}
		//cout << "======= 우축 택배 하강 후==========" << "\n";
		//test(grid);
		//cout << "=================================" << "\n";
	}
}
