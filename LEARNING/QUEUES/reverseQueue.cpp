#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    queue<int> Q;
    stack<int> stk;
    int num;

    cout << "Enter 5 elements to add to the queue:" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> num;
        Q.push(num);
    }

    cout << "The front element of the queue is: " << Q.front() << endl;

    cout << "Transferring elements from queue to stack..." << endl;
    while (!Q.empty())
    {
        stk.push(Q.front());
        Q.pop();
    }

    cout << "Transferring elements back from stack to queue..." << endl;
    while (!stk.empty())
    {
        Q.push(stk.top());
        stk.pop();
    }

    cout << "After reversing and restoring, the front element of the queue is: " << Q.front() << endl;

    return EXIT_SUCCESS;
}
