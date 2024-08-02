#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    #ifndef JUDGE_ONLINE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the element "<<i+1<<endl;
        cin>>arr[i];
    }

    int sum;
    // sum of subarrays
    for(int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            cout << "Sum of subarray from index " << i << " to " << j << " is: " << sum << endl;
        }
    }

    return EXIT_SUCCESS;
}
