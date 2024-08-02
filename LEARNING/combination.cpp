#include<iostream>
#include<cstdlib>
using namespace std;
int factorial(int n)
{
    if (n==0){
        return 1;
    }
    else if (n==1)
    {
        return 1;
    }
    else{
        return n * factorial(n-1);
}
    
    
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<"enter n and r"<<endl;
    int n,r;
    cin>>n>>r;
    if (n>=r)
    {
        cout<<endl<<factorial(n)/(factorial(n-r)*factorial(r));
    }
    return EXIT_SUCCESS;
}