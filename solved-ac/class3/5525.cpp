/*
BOJ No.5430
AC
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);


	int T;
	cin >> T;

	while (T--) {
		bool error = false;
		string Func;
		cin >> Func;
		
		int arrSize;
		cin >> arrSize;
		
		vector<string> v;

		string arr;
		cin >> arr;

		string number = "";
		for (int i = 1; i < arr.size(); i++) {
			if (arr[i] == ',' || arr[i] == ']') {
				if (number != "") {
					v.push_back(number);
					number = "";
					continue;
				}
			}
			number += arr[i];
		}

		int left = 0;
		int right = arrSize - 1;
		bool reverse = false;

		for (int i = 0; i < Func.size(); i++) {
			if (Func[i] == 'R') { // Reverse
				reverse = reverse == true ? false : true;
			}
			else { // pop

				if (arrSize == 0) {
					error = true;
					continue;
				}


				if (reverse) {
					right--;
					arrSize--;
				}
				else {
					left++;
					arrSize--;
				}
			}
		}

		if (error) {
			cout << "error" << "\n";
			continue;
		}

		stack<string> stk;
		if (reverse) {
			for (int i = left; i <= right; i++) {
				stk.push(v[i]);
			}

			for (int i = left; i <= right; i++) {
				v[i] = stk.top();
				stk.pop();
			}
		}

		cout << "[";
		for (int i = left; i <= right; i++) {
			cout << v[i];
			if (i < right) {
				cout << ",";
			}
		}
		cout << "]" << "\n";
	}
}