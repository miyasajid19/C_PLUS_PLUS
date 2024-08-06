#include <iostream>
using namespace std;

class Vector {
public:
    int size;
    int capacity;
    int* arr;

    Vector() {
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }

    ~Vector() {
        delete[] arr;
    }

    void add(int n) {
        if (size == capacity) {
            capacity *= 2;
            int* arr2 = new int[capacity];
            for (int i = 0; i < size; i++) {
                arr2[i] = arr[i];
            }
            delete[] arr;  // free old memory
            arr = arr2;
        }
        arr[size++] = n;
    }

    void pop() {
        if (size == 0) return; // No element to pop

        size--;
        if (size == 0) {
            delete[] arr; // free old memory
            capacity = 1;
            arr = new int[capacity];
        } else {
            int* arr2 = new int[size];
            for (int i = 0; i < size; i++) {
                arr2[i] = arr[i];
            }
            delete[] arr; // free old memory
            arr = arr2;
        }
    }

    void remove(int a) {
        if (size == 0) return; // No element to remove

        int* arr2 = new int[size];
        bool removed = false;
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (!removed && arr[i] == a) {
                removed = true;
                continue;
            }
            arr2[count++] = arr[i];
        }
        delete[] arr; // free old memory
        size = count;
        arr = arr2;
    }

    void removeall(int a) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] != a) {
                count++;
            }
        }

        int* arr2 = new int[count];
        count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] != a) {
                arr2[count++] = arr[i];
            }
        }
        delete[] arr;
        size = count;
        arr = arr2;
    }

    void Delete() {
        delete[] arr; // free old memory
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    Vector vec;

    // Test adding elements
    vec.add(10);
    vec.add(20);
    vec.add(30);
    vec.add(40);
    vec.add(50);
    vec.print(); // Expected: 10 20 30 40 50 

    // Test removing the first occurrence of an element
    vec.remove(30);
    vec.print(); // Expected: 10 20 40 50

    // Test removing all occurrences of an element
    vec.add(20);
    vec.add(20);
    vec.print(); // Expected: 10 20 40 50 20 20
    vec.removeall(20);
    vec.print(); // Expected: 10 40 50

    // Test popping elements
    vec.pop();
    vec.print(); // Expected: 10 40
    vec.pop();
    vec.print(); // Expected: 10
    vec.pop();
    vec.print(); // Expected: 

    // Test popping when empty
    vec.pop();
    vec.print(); // Expected: 

    // Test adding elements again after popping all
    vec.add(60);
    vec.add(70);
    vec.print(); // Expected: 60 70

    // Test deleting all elements
    vec.Delete();
    vec.print(); // Expected: 

    return 0;
}
