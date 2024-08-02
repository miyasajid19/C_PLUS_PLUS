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
    string a = "hello", b = "world!";
    cout << a << endl;
    cout << a.size() << endl;
    cout << b << endl;
    cout << b.length() << endl;
    // to concatenate
    string c = a + " " + b;
    cout << c << endl
         << c.length() << endl;
    // to append in the same string
    a.append(" sajid");
    cout << a << endl
         << a.length() << endl;
    // inserting in the string
    b.insert(0, "hello ");
    cout << b << endl
         << b.length() << endl;
    a.insert(a.size(), " miya");
    cout << a << endl
         << a.length() << endl;
    // sorting the string
    sort(a.begin(), a.end());
    cout << "sorted string : " << a << endl;
    string i = "430";
    cout << stoi(i) + 2 << endl;
    // intger to string
    int x = 43;
    cout << "021NEB" << to_string(x) + "2" << endl;
    // getting substring
    cout << b.substr(6, 11) << endl;
    cout << b.find("rld") << endl;
    // erase
    b.erase(2, 5);
    cout << b << endl;
    // empty the string
    b.clear();
    if (b.empty())
    {
        cout << "this is empty string";
    }
    cout << b << endl
         << b.size() << endl;
    string k = "sajid";
    string l = "miya";
    int z = k.compare(l);
    if (z == 1)
    {
        cout << k << " is greater than " << l << endl;
    }
    else if (z == -1)
    {
        cout << k << " is smaller than " << l << endl;
    }
    else
    {
        cout << k << l << "are equal" << endl;
    }
    // lowercasig the string manually
    string s = "ALL I WANT WAS THE LOVE AND WHAT I GET WAS THE PAIN";
    int j = 0;
    while ((s[j] != '\0'))
    {
        if (s[j] != ' ')
        {
            s[j] += 32;
        }
        cout << s[j++];
    }
    cout<<endl;
 // Uppercase the string manually
    string str2 = "all i want was the love and what i get was the pain";
    for (int j = 0; str2[j] != '\0'; j++)
    {
        if (str2[j] != ' ')
        {
            str2[j] -=32;
        }
        cout << str2[j];
    }
    cout << endl;

    // using build in functions
    transform(str2.begin(),str2.end(),str2.begin(), ::tolower);
    cout<<str2<<endl;
    transform(str2.begin(),str2.end(),str2.begin(), ::toupper);
    cout<<str2<<endl;
    return 0;
}