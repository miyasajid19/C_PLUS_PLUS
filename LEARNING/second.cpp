#include<iostream>
using namespace std;
int main(){
    int sum=0, i=50;
    while(i<=500)
    {
        sum+=i;
        ++i;
    }
    cout<<"the sum is : "<<sum<<endl;
    return 0;
}