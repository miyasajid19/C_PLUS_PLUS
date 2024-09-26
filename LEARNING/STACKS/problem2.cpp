#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

class Stacks
{
    string str;

public:
    Stacks(string str)
    {
        this->str = str;
    }

    int minRemovals()
    {
        stack<char> s;
        int removals = 0;

        for (char ch : str)
        {
            if (ch == '(')
            {
                s.push(ch);
            }
            else if (ch == ')')
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop(); // Matching pair found
                }
                else
                {
                    removals++; // Extra closing bracket
                }
            }
        }

        // Remaining opening brackets in stack are unmatched
        removals += s.size();

        return removals;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    string inputStr;
    cin >> inputStr;

    Stacks s(inputStr);
    cout << "Minimum removals to balance: " << s.minRemovals() << endl;

    return EXIT_SUCCESS;
}
