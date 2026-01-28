/*
BOJ No.1629
곱셈
*/
#include <iostream>

using namespace std;

long long a, b, c;

long long solve(long long x) {
	
	// breakpoint
	if (x == 0) {
		return 1;
	}
	if (x == 1) {
		return a % c;
	}
	// leftChild와 rightChild를 전역변수 처리를 하면 덮어씌워지기 때문에 문제가 발생할 수 있음
	// 따라서 지역변수 처리를 해야함
	// int int를 해서 틀림
	long long leftChild;
	long long rightChild;
	leftChild = solve(x / 2)%c;
	rightChild = x % 2 == 0 ? leftChild : solve(x/2 +1) % c;
 	return (leftChild * rightChild) % c;
}

int main() {
	cin >> a >> b >> c;
	cout << solve(b);
}
