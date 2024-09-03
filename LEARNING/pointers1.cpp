#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << "All I want was the love and what I get is the pain" << endl;

    /*
    There are four types of pointers:
    1) Wild Pointer
       - Points to a random address in memory.
       - Dereferencing it gives a random value.
       - Not widely used due to its risks.

    2) Null Pointer
       - Points to address 0x0 (null).
       - Preferred for initializing pointers to indicate they are not yet assigned.

    3) Dangling Pointer
       - Points to a memory location that has been deallocated or is no longer valid.
       - Accessing it can cause undefined behavior.

    4) Void Pointer
       - A generic pointer that can point to any data type.
       - Must be type-cast to another pointer type before dereferencing.
    */

    // Wild Pointer
    int* ptr1;
    // cout << ptr1 << " " << *ptr1 << endl; // This would cause undefined behavior (segmentation fault)

    // Null Pointer
    int* ptr2 = nullptr;
    // cout << ptr2 << " " << *ptr2 << endl; // This would cause undefined behavior (segmentation fault)

    // Dangling Pointer
    int* ptr3;
    for (int i = 0; i < 2; i++)
    {
        ptr3 = &i;
        cout << ptr3 << " " << *ptr3 << endl;
    }
    cout << ptr3 << " " << *ptr3 << endl; // This still points to the last value of `i`

    // Void Pointer
    int x = 432;
    float y = 407.432;
    char a = 'x';
    string str = "All I want was the love and what I get is the pain";

    void* ptr = &x;
    cout << ptr << " " << *(int*)ptr << endl;
    ptr = &y;
    cout << ptr << " " << *(float*)ptr << endl;
    ptr = &a;
    cout << ptr << " " << *(char*)ptr << endl;
    ptr = &str;
    cout << ptr << " " << *(string*)ptr << endl;

    return EXIT_SUCCESS;
}
