/*
baekjoon 18110
silver 4
solved.ac
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	float except = n * 0.15;
	if (except >= (int)except + 0.5) { // 반올림
		except = (int)except + 1;
	}
	else {
		except = (int)except;
	}

	int final_except = (int)except;

	int sum = 0;
	for (int i = final_except; i < n - final_except; i++) {
		/*cout << arr[i] << "\n";*/
		sum = sum + arr[i];
	}
	float result = (float)sum / (n - (2 * final_except));
	
	if (result >= (int)result + 0.5) { // 반올림
		result = (int)result + 1;
	}
	else {
		result = (int)result;
	}

	if (n == 0) {
		result = 0;
	}

	cout << result;
}