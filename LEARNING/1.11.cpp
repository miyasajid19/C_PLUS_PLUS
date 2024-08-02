#include<iostream>
using namespace std;
int main(){
    int upperlmt, lowerlmt;
    cout<< "enter the upper limit :";
    cin>>upperlmt;
    cout<<"enter the lower limit : ";
    cin>>lowerlmt;
    if (upperlmt>lowerlmt)
    {
        while(upperlmt>lowerlmt)
        {
            cout<<upperlmt--<<endl;
        }
    }
    else{
        while(upperlmt<lowerlmt)
        {
        cout<<upperlmt++<<endl;
        }
    }
    return 0;
}