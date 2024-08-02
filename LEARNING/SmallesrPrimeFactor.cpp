#include <iostream>
#include <cstdlib>
using namespace std;

void primefactor(int n) {
    
    int* arr = new int[n + 1]();
    for (int i = 2; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 2; i * i <= n; i++) {
        if (arr[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (arr[j] == j) {
                    arr[j] = i;
                }
            }
        }
    }


    while (n != 1) {
        cout << arr[n] << " ";
        n /= arr[n];
    }
    cout << endl;

    delete[] arr;
}

int main() {
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "Enter any number to find prime factors: "<<endl;
    int n;
    cin >> n; 
    primefactor(n);
    return EXIT_SUCCESS;
}
