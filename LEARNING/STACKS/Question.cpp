//given a series of N daily price quotes for a stock, we need to calculate the span  of the stokes's price  for all Ndays. the span of stoks price is one day is the maximum number of consecutive days     for which the price of stoke is less than or equeal to the price of that day
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
vector<int> getSpan(int arr[], int length)
{
    vector<int> result(length, -1);
    Stacks stack(length);

    for (int i = 0; i < length; i++)
    {
        while (!stack.isEmpty() && arr[i] > arr[stack.Top()])
        {
            int current = stack.Top();
            result[current] = i; // Store the next greater element
            stack.Pop();
        }
        stack.Push(i);
    }
    return result;
}
vector<int> span(int arr[], int size)
{
    // for (int i = 0; i < size / 2; i++)
    // {
    //     swap(arr[i], arr[size - i - 1]);
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }?
    return getSpan(arr, size);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int size;
    cout << "how many data do you have??" << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "enter element " << i + 1;
        cin >> arr[i];
    }
    cout << "the given data is : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    vector<int> result = span(arr, size);
    cout << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return EXIT_SUCCESS;
}