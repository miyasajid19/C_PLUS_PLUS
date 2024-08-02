#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
bool check(int a, int b, int c)
{
    if (((pow(a,2)+pow(b,2))==pow(c,2))||((pow(c,2)+pow(b,2))==pow(a,2))||((pow(a,2)+pow(c,2))==pow(b,2)))
    {
        return true;
    }

    return false;
}
int main()
{
    #ifndef JUDGE_ONLINE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int a,b,c;
    cout<< "enter three numbers "<<endl;
    cin>>a>>b>>c;
    if (check(a,b,c))
    {
        cout<<"Pythagorous triplet";
    }
    else{
        cout<<"not Pythagoras triplet";
    }
    return EXIT_SUCCESS;
}