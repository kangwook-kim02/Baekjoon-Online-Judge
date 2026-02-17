/*
BOJ No.5639
이진 검색 트리
*/

#include <iostream>
#include <vector>
using namespace std;

int root;
vector<pair<int, int>> child(1000000, {-1, -1});

void postOrder(int cur) {
	if (child[cur].first != -1) postOrder(child[cur].first);
	if (child[cur].second != -1) postOrder(child[cur].second);
	cout << cur << "\n";
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int idx = 0;
	while (1) {
		int num;
		cin >> num;
		if (cin.eof()) {
			break;
		}

		if (idx == 0) {
			root = num;
			idx++;
			continue;
		}

		int cur = root;
		while (1) {
			if (num > cur) {
				if (child[cur].second == -1) {
					child[cur].second = num;
					break;
				}
				else {
					cur = child[cur].second;
				}
			}
			else if (num < cur) {
				if (child[cur].first == -1) {
					child[cur].first = num;
					break;
				}
				else {
					cur = child[cur].first;
				}
			}
		}
	}
	postOrder(root);

}
