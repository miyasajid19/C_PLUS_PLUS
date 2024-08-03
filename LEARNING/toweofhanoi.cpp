#include<iostream>
#include<cstdlib>
using namespace std;
void towerofhanoi(int disc,string source,string destination,string auxilliary,int* move)
{
    if (disc==0)
    {
        return;
    }
    
    towerofhanoi(disc-1,"source","auxilliary","destination",move);
    cout<< "Move "<< ++(*move)<<" ::: Move disc "<<disc<<" from "<<source<<" to "<< destination<<endl;
    towerofhanoi(disc-1,"auxilliary","destination","source",move);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
int disc;
int* move=new int();
cout<<"enter the no of disc : "<<endl;
cin>>disc;
towerofhanoi(disc,"source","destination","auxilliary" ,move);
    return EXIT_SUCCESS;
}