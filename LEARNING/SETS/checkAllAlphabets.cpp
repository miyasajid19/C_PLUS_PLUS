#include <iostream>
#include <set>
#include <cctype> // For std::tolower
using namespace std;

bool checkAlphabets(const string &str)
{
    if (str.size() < 26)
    {
        return false;
    }

    set<char> charSet;

    for (char c : str)
    {
        // Convert to lowercase and add to set if it is an alphabetic character
        char lowerC = tolower(static_cast<unsigned char>(c));
        if (lowerC >= 'a' && lowerC <= 'z')
        {
            charSet.insert(lowerC);
        }
    }

    // Check if we have all 26 letters
    return charSet.size() == 26;
}

int main()
{
    string str;
    cout << "Enter any string: " << endl;
    getline(cin, str);

    cout << boolalpha << checkAlphabets(str) << endl;

    return 0;
}
