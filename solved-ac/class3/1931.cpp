/*
백준 1931번
회의실 배정
골드 5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meet {
	int start;
	int end;
};

bool compare(meet a, meet b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	
	return a.end < b.end;
}

int main() {
	int n;
	cin >> n;
	int start, end;
	vector<meet> v;

	for (int i = 0; i < n; i++) {
		meet m;
		cin >> start >> end;
		m.start = start;
		m.end = end;
		v.push_back(m);
	}

	sort(v.begin(), v.end(), compare);


	int count = 0;
	end = 0;

	for (int i = 0; i < v.size(); i++) {
		if (end <= v[i].start) {
			end = v[i].end;
			count++;
		}
	}

	cout << count;
}