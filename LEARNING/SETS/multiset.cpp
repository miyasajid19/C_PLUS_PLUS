#include <iostream>
#include<cstdlib>
#include<set>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
multiset<int> set1;
set1.insert(1);
set1.insert(2);
set1.insert(2);
set1.insert(3);
set1.insert(2);
for (auto x:set1)
{
    cout<<x<<" ";
}cout<<endl;
    return EXIT_SUCCESS;
}