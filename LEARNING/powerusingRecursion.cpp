#include<iostream>
#include<cstdlib>
using namespace std;

int power(int a,int b){
    if(b==0)
    {
        return 1;
    }
    return a*power(a,b-1);
}

int main() {
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int number , index;
    cout<<"enter the numbe and index";
    cin>>number>>index;
    cout<<number<<" raised to power "<<index<< " is "<<power(number,index);
    return EXIT_SUCCESS;
}
