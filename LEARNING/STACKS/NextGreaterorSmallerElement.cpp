#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Stacks
{
    int *arr = nullptr;
    int capacity;
    int size;

public:
    Stacks(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new int[capacity]();
    }

    void Push(int a)
    {
        if (size >= capacity)
        {
            cout << "stack overflow";
            return;
        }
        arr[size++] = a;
    }

    void Pop()
    {
        if (size <= 0)
        {
            cout << "stack underflow";
            return;
        }
        size--;
    }

    int Top()
    {
        if (size > 0)
        {
            return arr[size - 1];
        }
        return -1; // Return a sentinel value if the stack is empty
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    int Size()
    {
        return size;
    }

    void erase()
    {
        this->size = 0;
    }

    ~Stacks()
    {
        delete[] arr;
    }
};

vector<int> nextGreaterElement(int arr[], int length)
{
    vector<int> result(length, -1);
    Stacks stack(length);

    for (int i = 0; i < length; i++)
    {
        while (!stack.isEmpty() && arr[i] > arr[stack.Top()])
        {
            int current = stack.Top();
            result[current] = arr[i]; // Store the next greater element
            stack.Pop();
        }
        stack.Push(i);
    }
    return result;
}
vector<int> nextSmallerElement(int arr[], int length)
{
    vector<int> result(length, -1);
    Stacks stack(length);

    for (int i = 0; i < length; i++)
    {
        while (!stack.isEmpty() && arr[i] <arr[stack.Top()])
        {
            int current = stack.Top();
            result[current] = arr[i]; // Store the next greater element
            stack.Pop();
        }
        stack.Push(i);
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int *arr = nullptr;
    int size;

    cout << "Enter the size of the array: " << endl;
    cin >> size;

    // Allocate memory for the array
    arr = new int[size];

    // Input elements into the array
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": " << endl;
        cin >> arr[i];
    }

    // Output elements of the array
    cout << "Array elements are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Next Greater Element ::::" << endl;
    vector<int> result = nextGreaterElement(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    cout << "Next Smaller Element ::::" << endl;
    vector<int> resultant = nextSmallerElement(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << resultant[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] arr;

    return EXIT_SUCCESS;
}
