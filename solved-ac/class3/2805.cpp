#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // 나무의 수
	int need; // 필요한 트리의 길이

	cin >> n >> need;
	int num;
	vector<int> tree;

	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		tree.push_back(num);
		maxValue = max(maxValue, num);
	}

	int left = 0;
	int right = maxValue;
	int answer = 0;
	// binary search
	while (left <= right) {
		int mid = (left + right) / 2;

		long long int sum = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] - mid >= 0) {
				sum = sum + (tree[i] - mid);
			}
		}

		if (sum >= need) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << answer;

}