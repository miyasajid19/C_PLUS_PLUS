#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
using namespace std;
set<int> convertToSet(vector<int> arr)
{
    set<int> answerSet;
    int size = 0;
    while (size != arr.size())
    {
        cout << arr[size] << endl;
        answerSet.insert(arr[size++]);
    }
    return answerSet;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> arr;

    cout << "how many values do you have?" << endl;
    int size, num;
    cin >> size;
    while (size--)
    {
        cin >> num;
        arr.push_back(num);
    }
    set<int> ans = convertToSet(arr);
    if (ans.size() == 1)
    {
        cout << "there is only one unique integers\n";
    }
    else
    {
        set<int>::iterator itr;
        itr = ans.begin();
        advance(itr, 1);
        cout <<"The second smallest integer is "<< *itr;
    }
    return EXIT_SUCCESS;
}