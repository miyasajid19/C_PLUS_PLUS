#include <iostream>
#include <cstddef> // For size_t

int main() {
    int size = -10;
    int arr[size]; // Using size_t for array size

    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }

    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
