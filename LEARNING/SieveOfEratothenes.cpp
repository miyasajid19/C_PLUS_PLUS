#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "Enter the upper bound for prime numbers: " << endl;
    int n;
    cin >> n;
    // int* arr= new int[n]; --------------> this will give the garbage value to the array elements
    int *arr = new int[n]();
    for (int i = 2; i * i <n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j=i*i;j<n;j+=i)
            {
                arr[j]=1;
            }
        }
    }
    cout<<"the prime numbers are : "<<endl;
    for (int i=2;i<n;i++)
    {
        if (arr[i]==0)
        {
            cout<<i<<" ";
        }
    }
    delete[] arr;
    return EXIT_SUCCESS;
}
