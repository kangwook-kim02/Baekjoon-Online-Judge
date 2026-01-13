/*
백준 1074번
Z
골드 5
*/
#include <iostream>
using namespace std;

int divideAndConquer(int r, int c, long long int size, long long int k) {
	if (size == 1) {
		return k;
	}

	if (r < size / 2 && c < size / 2) { // 1사분면
		return divideAndConquer(r,c,size/2,k);
	}
	else if (r < size / 2 && c >= size / 2) { // 2사분면
		return divideAndConquer(r, c-size/2, size/2, k + size * size / 4);
	}
	else if (r >= size / 2 && c < size / 2) { // 3사분면
		return divideAndConquer(r-size/2, c, size / 2, k + size * size / 2);
	}
	else if (r >= size / 2 && c >= size / 2) { // 4사분면
		return divideAndConquer(r-size/2, c-size/2, size / 2, k + size * size * 3 / 4);
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n, r, c;
	cin >> n >> r >> c;

	long long int size = 1;
	for (int i = 0; i < n; i++) {
		size = size * 2;
	}

	cout << divideAndConquer(r,c,size,0);
}