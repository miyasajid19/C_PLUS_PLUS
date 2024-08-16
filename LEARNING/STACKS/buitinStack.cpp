// ---------------------------CHATGPT CODE---------------------------------------

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("..input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // Create two stacks of strings
    stack<string> stack1;
    stack<string> stack2;

    // Add elements to stack1 using emplace
    stack1.emplace("First element");
    stack1.emplace("Second element");

    // Add elements to stack2 using emplace
    stack2.emplace("Third element");
    stack2.emplace("Fourth element");

    // Display size and top element of stack1
    cout << "Stack1 size: " << stack1.size() << endl;
    cout << "Stack1 top element: " << stack1.top() << endl;

    // Display size and top element of stack2
    cout << "Stack2 size: " << stack2.size() << endl;
    cout << "Stack2 top element: " << stack2.top() << endl;

    // Swap the contents of stack1 and stack2
    stack1.swap(stack2);

    // Display size and top element of stack1 after swap
    cout << "After swap - Stack1 size: " << stack1.size() << endl;
    cout << "After swap - Stack1 top element: " << stack1.top() << endl;

    // Display size and top element of stack2 after swap
    cout << "After swap - Stack2 size: " << stack2.size() << endl;
    cout << "After swap - Stack2 top element: " << stack2.top() << endl;

    // Pop all elements from stack1 and check if it's empty
    while (!stack1.empty())
    {
        cout << "Popping from stack1: " << stack1.top() << endl;
        stack1.pop();
    }

    // Check if stack1 is empty
    if (stack1.empty())
    {
        cout << "Stack1 is now empty." << endl;
    }

    return 0;
}
