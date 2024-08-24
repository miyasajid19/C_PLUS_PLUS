#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> v1, v2;
    int size, num;
    cout << "enter the size for vector 1 :::" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "element " << i + 1 << endl;
        cin >> num;
        v1.push_back(num);
    }
    cout << "enter the size for vector 2 :::" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "element " << i + 1 << endl;
        cin >> num;
        v2.push_back(num);
    }
    set<int> set1;
    set<int> set2;
    set<int> ans;
    while (not v1.empty())
    {
        set1.insert(v1.front());
        v1.erase(v1.begin());
    }
    while (not v2.empty())
    {
        set2.insert(v2.front());
        v2.erase(v2.begin());
    }
    set<int>::iterator itr;
    int sum=0;
    for(itr=set1.begin();itr!=set1.end();itr++)
    {
        if(set2.find(*itr)!=set2.end())
        {
            ans.insert(*itr);
            sum=sum+*itr;
        }
    }
    cout<<"common elements are :::"<<endl;
    for(auto common: ans)
    {
        cout<<common<<" ";
    }
    cout<<endl;
    cout<<"the sum of common elements in two vectors is"<<sum;
    return EXIT_SUCCESS;
}