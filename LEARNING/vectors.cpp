#include <iostream>
#include <cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//creating vector
    vector<int> p;
    //pu(sh_back(n) is used to assinging value to the vector at the end
    int size;
    cout<<"enter how many data do you have? "<<endl;
    cin>>size;
    for (int i =0;i<size;i++)
    {
        int a;
        cout<< "element "<<i+1<<endl;
        cin>>a;
        p.push_back(a);
    }
    for (int i =0;i<size;i++)
    {
        cout<<p[i]<<" ";
    }

    cout<<endl;
    vector <int>::iterator it;
    // for(it=p.begin();it!=p.end();it++)
    for(it=p.begin();it<p.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto value:p)// like for value in p ----> in python
    {
        cout<<value<<" ";
    }
    cout<<endl;
    //pop_back() is is used to remove the end value from the vector 
    p.pop_back();
    for(auto value:p)// like for value in p ----> in python
    {
        cout<<value<<" ";
    }
    cout<<endl;

    //definig the vector of specific size and same  value
    vector <int> vet(5,432);
    for(it=vet.begin();it!=vet.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //swapping vectors
    swap(p,vet);
    cout<<"content of vector p"<<endl;
    for(auto value:p)// like for value in p ----> in python
    {
        cout<<value<<" ";
    }
    cout<<endl;
    cout<<"content of vector vet"<<endl;
        for(it=vet.begin();it!=vet.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //sorting of vector
    sort(vet.begin(),vet.end());
    cout<<"sorted vector vet : "<<endl;;
        for(it=vet.begin();it!=vet.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return EXIT_SUCCESS;
}
