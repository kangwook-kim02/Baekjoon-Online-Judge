/*
BOJ No.11286
Àý´ñ°ª Èü
*/

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		return a > b;
	}
};

int main() {
	int n;

	cin >> n;
	priority_queue<int, vector<int>, compare> pq;
	int num;
	while (n--) {
		cin >> num;
		if (num == 0 && pq.empty()) {
			cout << 0 << "\n";
			continue;
		}

		if (num == 0) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		else {
			pq.push(num);
		}
	}
} 