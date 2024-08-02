#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
string a="21312476573";
sort(a.begin(),a.end(),greater<int>());
cout<<a<<" is the possible largest integers";

    return 0;
}