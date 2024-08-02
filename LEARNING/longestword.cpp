#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    getline(cin, str);
    cout << str << endl;

    int length = 0, maxlength = 0;
    int start = 0, end;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            if (length > maxlength)
            {
                maxlength = length;
                start = i - length;
            }
            length = 0; // Reset length for the next word
        }
        else
        {
            length++;
        }
        i++;
    }

    // Check the last word
    if (length > maxlength)
    {
        maxlength = length;
        start = i - length;
    }

    cout << "Length of longest word: " << maxlength << endl;
    cout << "Longest word: ";
    for (int i = start; i < start + maxlength; i++)
    {
        cout << str[i];
    }

    return EXIT_SUCCESS;
}
