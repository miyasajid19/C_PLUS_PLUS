#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
vector<int> Intersection(vector<int> A, vector<int> B)
{
    vector<int> result;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            if (A[i] == B[j])
            {
                result.push_back(A[i]);
                B.erase(B.begin() + j);
                break;
            }
        }
    }
    return result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> A = {1,1,1,1,1,1,1,1,1,1,2,3,3,3};
    vector<int> B = {1, 1, 6,6};
    vector<int>result=Intersection(A,B);
    for (auto x: result)
    {
        cout<<x<<" ";
    }
    return EXIT_SUCCESS;
}