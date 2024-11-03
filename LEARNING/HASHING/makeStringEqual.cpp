#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    map<char, int> table; // Map to store the count of each character

public:
    Solution(vector<string> str)
    {
        // Populate the map with character frequencies from the input strings
        for (string x: str)
        {
            for (char i: x)
            {
                table[i]++;
            }
        }
    }

    bool check()
    {
        // If the map is empty or has only one element, it is trivially balanced
        if (table.empty() || table.size() == 1)
        {
            return true;
        }

        // Get the frequency of the first character in the map
        int firstFreq = table.begin()->second;

        // Iterate through the map and compare all values to the first frequency
        for (auto it = table.begin(); it != table.end(); ++it)
        {
            if (it->second != firstFreq)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    vector<string> str;
    cout << "how many string do you want to store??";
    int size;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        string a;
        cout << "enter string " << i + 1 << " :: ";
        cin >> a;
        str.push_back(a);
    }
    // Create a Solution object with three input strings
    Solution soln(str);

    // Print the result of the check function
    cout << boolalpha << soln.check() << endl;

    return EXIT_SUCCESS;
}
