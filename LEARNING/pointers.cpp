#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
/*
Type cast required: char* pointers to avoid treating them as strings.
No type cast required: int*, float*, double*, bool*, and other non-character pointers.
*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
bool a;
bool* ptr;
ptr=&a;
cout<<&a<<endl<<ptr<<endl<<&ptr;
    return EXIT_SUCCESS;
}
