#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    queue<int> a;
    cout << "Enqueue operations:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Enqueue(" << i << "): " << endl;
        a.push(i);
    }
    
    cout << "Size after enqueue operations: " << a.size() << endl;

    if (!a.empty()) {
        cout << "Front before pops: " << a.front() << endl;
    }

    // Safely pop elements
    while (!a.empty()) {
        cout << "Popping: " << a.front() << endl;
        a.pop();
        if (!a.empty()) {
            cout << "Front after pop: " << a.front() << endl;
        } else {
            cout << "Queue is now empty." << endl;
        }
    }
    
    return EXIT_SUCCESS;
}
