/*
baekjoon 1463
memory 5928KB
time 4ms
*/

#include <iostream>
using namespace std;

int arr[1000001];

int main() {

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i < 1000001; i++) {
		
		int count = 0;
		int temp = i;


		if (temp % 2 == 0 && temp % 3 == 0) {
			count++;
			if (arr[temp / 2] < arr[temp / 3]) {
				if (arr[temp / 2] < arr[temp - 1]) {
					temp = temp / 2;
					arr[i] = count + arr[temp];
				}
				else {
					temp = temp - 1;
					arr[i] = count + arr[temp];
				}
			}
			else {
				if (arr[temp / 3] < arr[temp - 1]) {
					temp = temp / 3;
					arr[i] = count + arr[temp];
				}
				else {
					temp = temp - 1;
					arr[i] = count + arr[temp];
				}
			}
		}
		else if (temp % 2 == 0) {
			if (arr[temp / 2] < arr[temp - 1]) {
				count++;
				temp = temp / 2;
				arr[i] = count + arr[temp];
			}
			else {
				count++;
				temp = temp - 1;
				arr[i] = count + arr[temp];
			}
		}
		else if (temp % 3 == 0) {
			if (arr[temp / 3] < arr[temp - 1]) {
				count++;
				temp = temp / 3;
				arr[i] = count + arr[temp];
			}
			else {
				count++;
				temp = temp - 1;
				arr[i] = count + arr[temp];
			}
		}
		else {
			temp = temp - 1;
			count++;
			arr[i] = count + arr[temp];
		}
	}
	/* debug*/
	//for (int i = 1; i < 10; i++) {
	//	cout << arr[i] << "\n";
	//}

	int n;
	cin >> n;
	cout << arr[n];
}