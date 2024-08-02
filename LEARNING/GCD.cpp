#include<iostream>
#include<cstdlib>
using namespace std;

int gcdByDifference(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a; // or return b, since a == b at this point
}

int gcdByModulus(int a, int b) {
    while (a % b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    
    // Ensure a is greater than or equal to b
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    cout << "The greatest common divisor of "<<a<<" and "<<b<<" is "<<gcdByDifference(a, b) << endl;
    cout << "The greatest common divisor of "<<a<<" and "<<b<<" is "<<gcdByModulus(a, b) << endl;

    return EXIT_SUCCESS;
}
