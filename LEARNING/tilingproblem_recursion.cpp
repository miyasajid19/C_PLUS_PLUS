//given "2 x n" board and tiles of size "2 x 1" count the number of ways to tile the given board usig these tiles
#include<iostream>
#include<cstdlib>
using namespace std;

int ways(int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    return ways(n-1) + ways(n-2);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    

    cout << "Enter the column  of tile box: "<<endl;
    int column;
    cin >> column;

    cout<<"There are "<< ways(column)<<" we can tile the box";

    return EXIT_SUCCESS;
}
