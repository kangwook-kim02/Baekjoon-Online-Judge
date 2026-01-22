/*
BOJ No.7662
이중 우선순위 큐
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int k;
		cin >> k;
		
		// pair의 first를 기준으로 뽑는다
		priority_queue<pair<int, int>, vector<pair<int, int>>> max_heap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> min_heap;
		vector<bool> visit(1000000, false);
		int id = 0;
		while (k--) {
			char op;
			int n;
			cin >> op >> n;
			if (op == 'I') {
				max_heap.push({ n,id });
				min_heap.push({ n,id });
				id++;
			}
			else {
				if (n == 1) {
					while (max_heap.size() > 0 && visit[max_heap.top().second]) {
						max_heap.pop();
					}
					
					if (max_heap.size() > 0) {
						visit[max_heap.top().second] = true;
						max_heap.pop();
					}
				}
				else {
					while (min_heap.size() > 0 && visit[min_heap.top().second]) {
						min_heap.pop();
					}

					if (min_heap.size() > 0) {
						visit[min_heap.top().second] = true;
						min_heap.pop();
					}
				}
			}
		}
		
		// id가 true인 값 제거
		while (max_heap.size() > 0 && visit[max_heap.top().second]) {
			max_heap.pop();
		}
		while (min_heap.size() > 0 && visit[min_heap.top().second]) {
			min_heap.pop();
		}

		if (min_heap.empty() && max_heap.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			int max = max_heap.size() > 0 ? max_heap.top().first : min_heap.top().first;
			int min = min_heap.size() > 0 ? min_heap.top().first : max_heap.top().first;
			cout << max << " " << min << "\n";
		}
	}
}
