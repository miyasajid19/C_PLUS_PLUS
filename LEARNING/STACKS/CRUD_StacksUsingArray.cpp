#include <iostream>
#include <cstdlib>
using namespace std;

class Stacks
{
    int *arr;
    int size;

public:
    int capacity;
    Stacks(int capacity) : size(-1), capacity(capacity)
    {
        arr = new int[capacity]();
    }

    ~Stacks()
    {
        delete[] arr;
    }

    // Copy constructor
    Stacks(const Stacks &other) : size(other.size), capacity(other.capacity)
    {
        arr = new int[capacity];
        for (int i = 0; i <= size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }

    // Assignment operator
    Stacks &operator=(const Stacks &other)
    {
        if (this != &other)
        {
            delete[] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new int[capacity];
            for (int i = 0; i <= size; ++i)
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    void Push(int value)
    {
        if (size >= capacity - 1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        arr[++size] = value;
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        size--;
    }

    int Top() const
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        return arr[size];
    }

    bool isEmpty() const
    {
        return size == -1;
    }

    bool isFull() const
    {
        return size == capacity - 1;
    }

    int getSize() const
    {
        return size + 1;
    }

    void erase()
    {
        size = -1;
    }
};

// Copy a stack
Stacks Copy(const Stacks &stack)
{
    Stacks temp(stack.capacity);
    Stacks copy_stack(stack.capacity);

    // Transfer elements from the original stack to a temporary stack
    Stacks temp_stack = stack; // Create a copy to avoid modifying the original stack
    while (!temp_stack.isEmpty())
    {
        int current = temp_stack.Top();
        temp_stack.Pop();
        temp.Push(current);
    }

    // Transfer elements from the temporary stack to the new copy stack
    while (!temp.isEmpty())
    {
        int current = temp.Top();
        temp.Pop();
        copy_stack.Push(current);
    }

    return copy_stack;
}

// Copy by recursion
void copyByRecursion(Stacks stack, Stacks &result)
{
    if (stack.isEmpty())
    {
        return;
    }
    int current = stack.Top();
    stack.Pop();
    copyByRecursion(stack, result);
    result.Push(current);
}

// Reverse the stack
void Reverse(Stacks &stack)
{
    Stacks temp(stack.capacity);
    while (!stack.isEmpty())
    {
        int current = stack.Top();
        stack.Pop();
        temp.Push(current);
    }
    stack = temp;
}

// Insert at the bottom of the stack
void insertAtBottom(Stacks &stack, int value)
{
    if (stack.isEmpty())
    {
        stack.Push(value);
        return;
    }
    int current = stack.Top();
    stack.Pop();
    insertAtBottom(stack, value);
    stack.Push(current);
}
void removeFromButtom(Stacks &stack)
{
    int current;
    Stacks temp(stack.capacity-1);
    while(stack.getSize()>1)
    {
        current=stack.Top();
        stack.Pop();
        temp.Push(current);
    }
    stack.Pop();
    while(not temp.isEmpty())
    {
        current=temp.Top();
        stack.Push(current);
        temp.Pop();
    }

}
void remove(Stacks &stack, int index)
{
    int current;
    int length=stack.getSize()-index;
    Stacks temp(stack.capacity-1);
    while(length--)
    {
        current=stack.Top();
        stack.Pop();
        temp.Push(current);
    }
    stack.Pop();
    while(temp.getSize())
    {
        current=temp.Top();
        temp.Pop();
        stack.Push(current);
    }

}
// Reverse by recursion
void ReverseByRecursion(Stacks &stack, Stacks &result)
{
    if (stack.isEmpty())
    {
        return;
    }
    int current = stack.Top();
    stack.Pop();
    ReverseByRecursion(stack, result);
    insertAtBottom(result, current);
}

int main()
{
//     // Optional: Redirect input and output streams for testing
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cout << "Demonstrating Stack Operations and Functionalities" << endl;

    // Initialize a stack with a capacity of 5
    Stacks stack(5);

    // Push elements onto the stack
    cout << "Pushing elements onto the stack:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        stack.Push(i + 1);
    }

    // Copy the stack using the Copy function
    cout << "Copying the stack:" << endl;
    Stacks copy_stack1 = Copy(stack);
    cout << "Contents of the copied stack:" << endl;
    while (!copy_stack1.isEmpty())
    {
        cout << copy_stack1.Top() << " ";
        copy_stack1.Pop();
    }
    cout << endl;

    // Copy the stack using recursion
    cout << "Copying the stack by recursion:" << endl;
    Stacks copy_stack(5);
    copyByRecursion(stack, copy_stack);
    cout << "Contents of the recursively copied stack:" << endl;
    while (!copy_stack.isEmpty())
    {
        cout << copy_stack.Top() << " ";
        copy_stack.Pop();
    }
    cout << endl;

    // Reverse the stack
    cout << "Reversing the stack:" << endl;
    Reverse(stack);
    cout << "Contents of the reversed stack:" << endl;
    while (!stack.isEmpty())
    {
        cout << stack.Top() << " ";
        stack.Pop();
    }
    cout << endl;

    // Push elements onto the stack again
    cout << "Re-pushing elements onto the stack:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        stack.Push(i + 1);
    }

    // Reverse the stack using recursion
    cout << "Reversing the stack by recursion:" << endl;
    Stacks rev(5);
    ReverseByRecursion(stack, rev);
    cout << "Contents of the recursively reversed stack:" << endl;
    while (!rev.isEmpty())
    {
        cout << rev.Top() << " ";
        rev.Pop();
    }
    cout << endl;

    // Remove the bottom element of the stack
    cout << "Removing the bottom element of the stack:" << endl;
    removeFromButtom(stack);
    cout << "Contents of the stack after removing the bottom element:" << endl;
    while (!stack.isEmpty())
    {
        cout << stack.Top() << " ";
        stack.Pop();
    }
    cout << endl;

    // Re-push elements onto the stack
    cout << "Re-pushing elements onto the stack:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        stack.Push(i + 1);
    }

    // Remove an element at a specific index (2 in this case)
    cout << "Removing the element at index 2:" << endl;
    remove(stack, 2);
    cout << "Contents of the stack after removing the element at index 2:" << endl;
    while (!stack.isEmpty())
    {
        cout << stack.Top() << " ";
        stack.Pop();
    }
    cout << endl;

    return EXIT_SUCCESS;
}

// ----------------------------CHAT GPT CODE----------
// #include <iostream>
// #include <climits> // for INT_MIN
// using namespace std;

// class Stacks
// {
//     int *arr;
//     int size;
//     int capacity;

// public:
//     Stacks(int cap) : size(-1), capacity(cap)
//     {
//         arr = new int[capacity]();
//     }

//     ~Stacks()
//     {
//         delete[] arr;
//     }

//     // Copy constructor
//     Stacks(const Stacks &other) : size(other.size), capacity(other.capacity)
//     {
//         arr = new int[capacity];
//         for (int i = 0; i <= size; ++i)
//         {
//             arr[i] = other.arr[i];
//         }
//     }

//     // Assignment operator
//     Stacks &operator=(const Stacks &other)
//     {
//         if (this != &other)
//         {
//             delete[] arr;
//             size = other.size;
//             capacity = other.capacity;
//             arr = new int[capacity];
//             for (int i = 0; i <= size; ++i)
//             {
//                 arr[i] = other.arr[i];
//             }
//         }
//         return *this;
//     }

//     void Push(int value)
//     {
//         if (size >= capacity - 1)
//         {
//             cout << "Stack overflow" << endl;
//             return;
//         }
//         arr[++size] = value;
//     }

//     void Pop()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack underflow" << endl;
//             return;
//         }
//         size--;
//     }

//     int Top() const
//     {
//         if (isEmpty())
//         {
//             cout << "Stack is empty" << endl;
//             return INT_MIN;
//         }
//         return arr[size];
//     }

//     bool isEmpty() const
//     {
//         return size == -1;
//     }

//     bool isFull() const
//     {
//         return size == capacity - 1;
//     }

//     int getSize() const
//     {
//         return size + 1;
//     }

//     void erase()
//     {
//         size = -1;
//     }

//     // Copy a stack
//     static Stacks Copy(const Stacks &stack)
//     {
//         Stacks temp(stack.capacity);
//         Stacks copy_stack(stack.capacity);

//         // Transfer elements from the original stack to a temporary stack
//         Stacks temp_stack(stack); // Create a copy to avoid modifying the original stack
//         while (!temp_stack.isEmpty())
//         {
//             int current = temp_stack.Top();
//             temp_stack.Pop();
//             temp.Push(current);
//         }

//         // Transfer elements from the temporary stack to the new copy stack
//         while (!temp.isEmpty())
//         {
//             int current = temp.Top();
//             temp.Pop();
//             copy_stack.Push(current);
//         }

//         return copy_stack;
//     }

//     // Copy by recursion
//     static void copyByRecursion(Stacks &stack, Stacks &result)
//     {
//         if (stack.isEmpty())
//         {
//             return;
//         }
//         int current = stack.Top();
//         stack.Pop();
//         copyByRecursion(stack, result);
//         result.Push(current);
//     }

//     // Reverse the stack
//     static void Reverse(Stacks &stack)
//     {
//         Stacks temp(stack.capacity);
//         while (!stack.isEmpty())
//         {
//             int current = stack.Top();
//             stack.Pop();
//             temp.Push(current);
//         }
//         stack = temp;
//     }

//     // Insert at the bottom of the stack
//     static void insertAtBottom(Stacks &stack, int value)
//     {
//         if (stack.isEmpty())
//         {
//             stack.Push(value);
//             return;
//         }
//         int current = stack.Top();
//         stack.Pop();
//         insertAtBottom(stack, value);
//         stack.Push(current);
//     }

//     // Remove from the bottom of the stack
//     static void removeFromBottom(Stacks &stack)
//     {
//         if (stack.isEmpty())
//         {
//             return;
//         }
//         Stacks temp(stack.capacity);
//         while (stack.getSize() > 1)
//         {
//             int current = stack.Top();
//             stack.Pop();
//             temp.Push(current);
//         }
//         stack.Pop(); // Remove the bottom element
//         while (!temp.isEmpty())
//         {
//             int current = temp.Top();
//             temp.Pop();
//             stack.Push(current);
//         }
//     }

//     // Remove element at a given index (0-based)
//     static void remove(Stacks &stack, int index)
//     {
//         if (index < 0 || index >= stack.getSize())
//         {
//             cout << "Index out of bounds" << endl;
//             return;
//         }
//         int length = stack.getSize() - index - 1;
//         Stacks temp(stack.capacity);
//         while (length--)
//         {
//             int current = stack.Top();
//             stack.Pop();
//             temp.Push(current);
//         }
//         stack.Pop(); // Remove the element at index
//         while (!temp.isEmpty())
//         {
//             int current = temp.Top();
//             temp.Pop();
//             stack.Push(current);
//         }
//     }

//     // Reverse by recursion
//     static void ReverseByRecursion(Stacks &stack, Stacks &result)
//     {
//         if (stack.isEmpty())
//         {
//             return;
//         }
//         int current = stack.Top();
//         stack.Pop();
//         ReverseByRecursion(stack, result);
//         insertAtBottom(result, current);
//     }
// };

// int main()
// {
//     // Optional: Redirect input and output streams for testing
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif

//     cout << "Demonstrating Stack Operations and Functionalities" << endl;

//     // Initialize a stack with a capacity of 5
//     Stacks stack(5);

//     // Push elements onto the stack
//     cout << "Pushing elements onto the stack:" << endl;
//     for (int i = 0; i < 5; ++i)
//     {
//         stack.Push(i + 1);
//     }

//     // Copy the stack using the Copy function
//     cout << "Copying the stack:" << endl;
//     Stacks copy_stack1 = Stacks::Copy(stack);
//     cout << "Contents of the copied stack:" << endl;
//     while (!copy_stack1.isEmpty())
//     {
//         cout << copy_stack1.Top() << " ";
//         copy_stack1.Pop();
//     }
//     cout << endl;

//     // Copy the stack using recursion
//     cout << "Copying the stack by recursion:" << endl;
//     Stacks copy_stack(5);
//     Stacks::copyByRecursion(stack, copy_stack);
//     cout << "Contents of the recursively copied stack:" << endl;
//     while (!copy_stack.isEmpty())
//     {
//         cout << copy_stack.Top() << " ";
//         copy_stack.Pop();
//     }
//     cout << endl;

//     // Reverse the stack
//     cout << "Reversing the stack:" << endl;
//     Stacks::Reverse(stack);
//     cout << "Contents of the reversed stack:" << endl;
//     while (!stack.isEmpty())
//     {
//         cout << stack.Top() << " ";
//         stack.Pop();
//     }
//     cout << endl;

//     // Push elements onto the stack again
//     cout << "Re-pushing elements onto the stack:" << endl;
//     for (int i = 0; i < 5; ++i)
//     {
//         stack.Push(i + 1);
//     }

//     // Reverse the stack using recursion
//     cout << "Reversing the stack by recursion:" << endl;
//     Stacks rev(5);
//     Stacks::ReverseByRecursion(stack, rev);
//     cout << "Contents of the recursively reversed stack:" << endl;
//     while (!rev.isEmpty())
//     {
//         cout << rev.Top() << " ";
//         rev.Pop();
//     }
//     cout << endl;

//     // Remove the bottom element of the stack
//     cout << "Removing the bottom element of the stack:" << endl;
//     Stacks::removeFromBottom(stack);
//     cout << "Contents of the stack after removing the bottom element:" << endl;
//     while (!stack.isEmpty())
//     {
//         cout << stack.Top() << " ";
//         stack.Pop();
//     }
//     cout << endl;

//     // Re-push elements onto the stack
//     cout << "Re-pushing elements onto the stack:" << endl;
//     for (int i = 0; i < 5; ++i)
//     {
//         stack.Push(i + 1);
//     }

//     // Remove an element at a specific index (2 in this case)
//     cout << "Removing the element at index 2:" << endl;
//     Stacks::remove(stack, 2);
//     cout << "Contents of the stack after removing the element at index 2:" << endl;
//     while (!stack.isEmpty())
//     {
//         cout << stack.Top() << " ";
//         stack.Pop();
//     }
//     cout << endl;

//     return EXIT_SUCCESS;
// }
