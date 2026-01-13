/*
baekjoon 1874
sliver 2
memory: 3612kb
time: 60ms
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];

	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	stack<int> stk;
	int num = 1;
	int idx = 0;
	
	vector<int> v;
	vector<char> op;
	int count = 0;
	while (1) {
		if (num == arr[idx]) {
			stk.push(num);
			op.push_back('+');
			num++;
			v.push_back(stk.top());
			stk.pop();
			count++;
			op.push_back('-');
			idx++;
		}
		else {
			if (num < arr[idx]) {
				stk.push(num);
				op.push_back('+');
				num++;
			}
			else {
				v.push_back(stk.top());
				stk.pop();
				idx++;
				count++;
				op.push_back('-');
			}
		}

		if (count >= n) {
			break;
		}
	}

	int check = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != v[i]) {
			check = 1;
			break;
		}
	}

	if (check == 1) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < op.size(); i++) {
			cout << op[i] << "\n";
		}
	}

}