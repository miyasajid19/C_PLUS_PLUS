#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map> // Header for unordered_multimap
using namespace std;

int main() {
    // unordered_multimap allows duplicate keys and does not maintain any specific order
    unordered_multimap<string, int> directory;
    
    // Inserting elements
    directory.insert(make_pair("Uchiha Obito", 432));
    directory.insert(make_pair("Uchiha Obito", 1234)); // Duplicate key allowed
    directory.insert(make_pair("Nohara Rin", 407));
    directory.insert(make_pair("Hatake Kakashi", 407432));
    directory.insert(make_pair("Uzumaki Naruto", 1));
    directory.insert(make_pair("Huguya Hinata", 2));
    directory.insert(make_pair("Uchiha Sasuke", 3));
    directory.insert(make_pair("Tsunade Senju", 4));
    directory.insert(make_pair("Namekaze Minato", 7));
    // directory["Uzumaki Naruto"]=7;//not allowed
    // Displaying the directory (order is not guaranteed)
    cout << "Original iteration:" << endl;
    for (unordered_multimap<string, int>::iterator it = directory.begin(); it != directory.end(); ++it) {
        cout << "Name : " << it->first << " Contact No. : " << it->second << endl;
    }
    cout << endl;

    // Deleting an element by key (removes all elements with the matching key)
    directory.erase("Nohara Rin");
    cout << "After deleting 'Nohara Rin':" << endl;
    for (unordered_multimap<string, int>::iterator it = directory.begin(); it != directory.end(); ++it) {
        cout << "Name : " << it->first << " Contact No. : " << it->second << endl;
    }
    cout << endl;

    // Deleting the third element from the start
    unordered_multimap<string, int>::iterator itr = directory.begin();
    advance(itr, 3);
    if (itr != directory.end()) {
        directory.erase(itr);
    }
    cout << "After deleting the third element:" << endl;
    for (unordered_multimap<string, int>::iterator it = directory.begin(); it != directory.end(); ++it) {
        cout << "Name : " << it->first << " Contact No. : " << it->second << endl;
    }
    cout << endl;

    // Erasing a range
    unordered_multimap<string, int>::iterator itr1 = directory.begin();
    unordered_multimap<string, int>::iterator itr2 = directory.begin();
    advance(itr1, 1);
    advance(itr2, directory.size() - 1);
    if (itr1 != directory.end() && itr2 != directory.end()) {
        directory.erase(itr1, itr2);
    }
    cout << "After erasing a range:" << endl;
    for (unordered_multimap<string, int>::iterator it = directory.begin(); it != directory.end(); ++it) {
        cout << "Name : " << it->first << " Contact No. : " << it->second << endl;
    }
    cout << endl;

    // Finding values
    itr = directory.find("Uchiha Obito");
    if (itr != directory.end()) {
        cout << "Found :: " << itr->second << endl;
    } else {
        cout << "Not Found" << endl;
    }

    itr = directory.find("Huguya Hinata");
    if (itr != directory.end()) {
        cout << "Found :: " << itr->second << endl;
    } else {
        cout << "Not Found" << endl;
    }

    // Checking if a key is present
    cout << boolalpha;
    bool found = directory.count("Hatake Kakashi");
    cout << "Kakashi ??? " << found << endl;
    found = directory.count("Uchiha Obito");
    cout << "Obito ??? " << found << endl;

    // Reverse iteration is not directly supported in unordered_multimap
    // Alternative: use a vector to store keys and iterate in reverse
    cout << "Reverse iteration using vector:" << endl;
    vector<pair<string, int>> entries(directory.begin(), directory.end());
    for (auto rit = entries.rbegin(); rit != entries.rend(); ++rit) {
        cout << "Name : " << rit->first << " Contact No. : " << rit->second << endl;
    }

    return EXIT_SUCCESS;
}
