/*
baekjoon 1003
silver 3
memory 2020KB
time 0ms
*/
#include <iostream>
using namespace std;

int zero_count = 0;
int one_count = 0;

int fibonacci(int n) {
    if (n == 0) {
        zero_count++;
        return 0;
    }
    else if (n == 1) {
        one_count++;
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

struct mem {
    int zero_count;
    int one_count;
};

int main() {

    
    mem arr[41];
    mem mem_0;
    mem mem_1;
    mem_0.zero_count = 1;
    mem_0.one_count = 0;
    mem_1.zero_count = 0;
    mem_1.one_count = 1;

    arr[0] = mem_0;
    arr[1] = mem_1;

    for (int i = 2; i < 41; i++) {
        mem mem_n;
        mem_n.zero_count = arr[i - 2].zero_count + arr[i-1].zero_count;
        mem_n.one_count = arr[i - 2].one_count + arr[i - 1].one_count;
        // Debug
        /*cout << i << "¹øÂ° " << "zero: " << mem_n.zero_count << " one: " << mem_n.one_count << "\n";*/
        arr[i] = mem_n;
    }

    //Debug
    /*for (int i = 0; i < 41; i++) {
        cout << i << ": " << arr[i].zero_count << " " << arr[i].one_count << "\n";
    }*/
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << arr[n].zero_count << " " << arr[n].one_count << "\n";
    }



}