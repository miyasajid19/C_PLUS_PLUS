/*
Design a stack that supports push,
 pop, top, and retrieving the minimum element in constant time.
  Implement the MinStack class: MinStack() initializes the stack object.
  void push(int val) pushes the element val onto the stack. void pop() removes
  the element on the top of the stack. int top() gets the top element of the stack.
  int getMin() retrieves the minimum element in the stack.
   You must implement a solution with O(1) time complexity for each function.
    Assumption: Methods pop, top and getMin operations will always be
    called on non-empty stacks.
*/
#include <iostream>
#include <limits.h>

using namespace std;

class MinStack {
    int *arr;         // Stack to store actual values
    int *minArr;      // Stack to store the minimum values
    int size;         // Current size of the stack
    int capacity;     // Maximum capacity of the stack

public:
    MinStack(int capacity = 100) {
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
        minArr = new int[capacity];
    }
    
    ~MinStack() {
        delete[] arr;
        delete[] minArr;
    }

    void push(int value) {
        if (size >= capacity) {
            cout << "Stack overflow" << endl;
            return;
        }
        
        arr[size] = value;
        if (size == 0) {
            minArr[size] = value;
        } else {
            minArr[size] = min(value, minArr[size - 1]);
        }
        size++;
    }
    
    void pop() {
        if (size == 0) {
            cout << "Stack underflow" << endl;
            return;
        }
        size--;
    }
    
    int top() {
        if (size == 0) {
            return INT_MIN;
        }
        return arr[size - 1];
    }
    
    int getMin() {
        if (size == 0) {
            return INT_MIN;
        }
        return minArr[size - 1];
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity for stack: ";
    cin >> capacity;
    
    MinStack stk(capacity);
    
    cout << "Enter " << capacity << " values to push onto the stack:" << endl;
    for (int i = 0; i < capacity; i++) {
        int num;
        cin >> num;
        stk.push(num);
        cout << "Top: " << stk.top() << endl;
        cout << "Minimum: " << stk.getMin() << endl << endl;
    }
    
    cout << "Popping elements from the stack:" << endl;
    for (int i = 0; i < capacity; i++) {
        stk.pop();
        cout << "Top: " << stk.top() << endl;
        cout << "Minimum: " << stk.getMin() << endl << endl;
    }

    return 0;
}
