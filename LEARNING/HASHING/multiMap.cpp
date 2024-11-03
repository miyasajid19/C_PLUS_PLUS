#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

int main()
{
    multimap<string, int> directory;
    directory.insert(make_pair("Uchiha Obito", 432));
    directory.insert(make_pair("Uchiha Obito", 1234)); // Inserts duplicate key with a different value
    directory.insert(make_pair("Nohara Rin", 407));
    directory.insert(make_pair("Hatake Kakashi", 407432));
    directory.insert(make_pair("Uzumaki Naruto", 1));
    directory.insert(make_pair("Huguya Hinata", 2));
    directory.insert(make_pair("Uchiha Sasuke", 3));
    directory.insert(make_pair("Tsunade Senju", 4));
    directory.insert(make_pair("Namekaze Minato", 7));

    // Displaying the directory
    cout << "Original iteration:" << endl;
    for (multimap<string, int>::iterator it = directory.begin(); it != directory.end(); ++it)
    {
        cout << "Name : " << it->first << " Contact No. : " << it->second << endl;
    }
    cout << endl;
    // Checking if a key is present
    cout << boolalpha;
    int found = directory.count("Hatake Kakashi");
    cout << "Kakashi ??? " << found << endl;
    found = directory.count("Uchiha Obito");
    cout << "Obito ??? " << found << endl;

    // Deleting an element by key (removes all matching keys)
    directory.erase("Nohara Rin");
    cout << "After deleting 'Nohara Rin':" << endl;
    for (multimap<string, int>::iterator it = directory.begin(); it != directory.end(); ++it)
    {
        cout << "Name : " << it->first << " Contact No. : " << it->second << endl;
    }
    cout << endl;

    // Deleting the third element from the start
    multimap<string, int>::iterator itr = directory.begin();
    advance(itr, 3);
    if (itr != directory.end())
    {
        directory.erase(itr);
    }
    cout << "After deleting the third element:" << endl;
    for (multimap<string, int>::iterator it = directory.begin(); it != directory.end(); ++it)
    {
        cout << "Name : " << it->first << " Contact No. : " << it->second << endl;
    }
    cout << endl;

    // Erasing a range
    multimap<string, int>::iterator itr1 = directory.begin();
    multimap<string, int>::iterator itr2 = directory.begin();
    advance(itr1, 1);
    advance(itr2, directory.size() - 1);
    if (itr1 != directory.end() && itr2 != directory.end())
    {
        directory.erase(itr1, itr2);
    }
    cout << "After erasing a range:" << endl;
    for (multimap<string, int>::iterator it = directory.begin(); it != directory.end(); ++it)
    {
        cout << "Name : " << it->first << " Contact No. : " << it->second << endl;
    }
    cout << endl;

    // Finding values
    itr = directory.find("Uchiha Obito");
    if (itr != directory.end())
    {
        cout << "Found :: " << itr->second << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    itr = directory.find("Huguya Hinata");
    if (itr != directory.end())
    {
        cout << "Found :: " << itr->second << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    // Checking if a key is present
    cout << boolalpha;
    found = directory.count("Hatake Kakashi");
    cout << "Kakashi ??? " << found << endl;
    found = directory.count("Uchiha Obito");
    cout << "Obito ??? " << found << endl;

    // Reverse iteration
    cout << "Reverse iteration:" << endl;
    for (multimap<string, int>::reverse_iterator rit = directory.rbegin(); rit != directory.rend(); ++rit)
    {
        cout << "Name : " << rit->first << " Contact No. : " << rit->second << endl;
    }

    return EXIT_SUCCESS;
}
