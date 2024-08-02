#include<iostream>
#include<cstdlib>
using namespace std;
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

    

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<"how many terms do you want to generate ?"<<endl;
    int num;
    cin>>num;
    for (int i =0;i<num;i++)
    {
        cout<<fibonacci(i)<<"\t";
    }
    return EXIT_SUCCESS;
}