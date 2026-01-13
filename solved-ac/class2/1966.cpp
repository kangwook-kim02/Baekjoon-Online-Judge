/*
baekjoon 1966
printer queue
silver 3
memory: 2020KB 
time: 4ms 
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct document {
	int priority = -1; // 중요도
	int find = -1; // 찾고자 할 문서인 경우 0
};

int main() {
	int test;
	cin >> test;
	int idx = 0;
	for (int i = 0; i < test; i++) {
		int n;
		int find_document;
		cin >> n >> find_document;

		vector<document> v;
		
		int priority;
		for (int i = 0; i < n; i++) {
			cin >> priority;
			document d;
			d.priority = priority;
			if (find_document == i) {
				d.find = 0;
			}
			v.push_back(d);
		}
	/*	cout << "문서 개수: " << v.size() << "\n";*/ //debug
		int count = 0;
		int idx = 0;
		while (1) {
			document temp = v[idx];
			int max_priority = temp.priority;
			for (int i = idx; i < v.size(); i++) {
				if (temp.priority < v[i].priority) {
					v.push_back(temp);
					max_priority = v[i].priority;
					break;
				}
			}
			idx++;
			if (max_priority == temp.priority) {
				//cout << "출력된 문서의 우선 순위: " << temp.priority << "\n"; // debug
				count++;
				if (temp.find == 0) {
					break;
				}
			}
		}
		cout << count << "\n";
	}
}