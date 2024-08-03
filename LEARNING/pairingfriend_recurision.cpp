//how many ways person can be paired or made singled
#include<iostream>
#include<cstdlib>
using namespace std;

int pairingways(int n)
{
    if (n==0||n==1||n==2)
    {
        return n;
    }
    return pairingways(n-1)+pairingways(n-2)*(n-1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    

    cout << "Enter the no. of person : "<<endl;
    int n;
    cin >> n;

    cout<<"We can arrange (paired or singled) in "<< pairingways(n)<<"  different ways.";

    return EXIT_SUCCESS;
}
