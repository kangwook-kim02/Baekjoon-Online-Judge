/*
BOJ No.1043
거짓말
*/

/*
의문점 항상 지민이는 파티에서 얘기를 해야하나? --> 질문 게시판 보니까 항상 얘기해야함
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<bool> visit(n + 1, false);
	vector<vector<int>> party(m);
	int truePerson;
	cin >> truePerson;
	for (int i = 0; i < truePerson; i++) {
		int num;
		cin >> num;
		visit[num] = true;
	}

	// 파티
	for (int i = 0; i < m; i++) {
		int personNum;
		cin >> personNum;
		for (int j = 0; j < personNum; j++) {
			int num;
			cin >> num;
			party[i].push_back(num);
		}
	}

	// m번 반복을 해야 m개의 파티가 이어질 수 있음
	int loop = m;
	while (loop--) {
		for (int i = party.size() - 1; i >= 0; i--) {
			for (int j = 0; j < party[i].size(); j++) {
				if (visit[party[i][j]]) { // true인 사람이 존재한다면
					for (int k = 0; k < party[i].size(); k++) {
						visit[party[i][k]] = true; // 파티에 있는 모든 사람들을 true로 변경
					}
					break;
				}
			}
		}
	}

	int count = 0;
	for (int i = 0; i < party.size(); i++) {
		bool exist = false;
		for (int j = 0; j < party[i].size(); j++) {
			if (visit[party[i][j]]) {
				exist = true;
				break;
			}
		}
		if (!exist) count++;
	}

	cout << count;
}
