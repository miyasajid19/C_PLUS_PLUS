#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;
set<int> possibily(int n, int p, int q)
{
    set<int> ans;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int unattempted = n - (i + j);
            if (unattempted >= 0)
            {
                ans.insert(i * p - j * q);
            }
            else
            {
                break;
                ;
            }
        }
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, p, q;
    cout << "Total no of questions :: " << endl;
    cin >> n;
    cout << "how much do i get i  made correct :: " << endl;
    cin >> p;
    cout << "how much i get if i did wrong :: " << endl;
    cin >> q;
    set<int> ans = possibily(n, p, q);
    cout << "the possibilities are : " << endl;
    for (auto value : ans)
    {
        cout << value << " ";
    }
    cout<<endl<<"total : "<<ans.size();
    return EXIT_SUCCESS;
}