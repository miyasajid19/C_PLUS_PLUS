#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
bool mycompare(pair<int ,int>p1,pair<int ,int>p2)
{
    return p1.first<p2.first;
}
int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
vector <pair<int , int>> p;
cout<<"how many data do you have ?"<<endl;
int size;
cin>>size;
int a;
for (int i =0;i<size;i++)
{
    cout<<"element "<<i+1<<endl;
    cin>>a;
    p.push_back(make_pair(a,i));// inserting value and index at same time
}
for (int i=0;i<size;i++)
{
    cout<<p[i].first<<"---->"<<p[i].second<<endl;
}
sort(p.begin(),p.end(),mycompare);
cout<<"Results : "<<endl;
for (int i=0;i<size;i++)
{
    cout<<p[i].first<<"---->"<<p[i].second<<endl;
}
    return EXIT_SUCCESS;
}
