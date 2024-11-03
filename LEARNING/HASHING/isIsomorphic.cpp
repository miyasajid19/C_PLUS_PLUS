#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

class Solution {
    map<char, char> table;
    string str1, str2;

    bool check(string str1, string str2) {
        table.clear(); // Clear the map to ensure no residual data affects the check
        for (int i = 0; i < str1.length(); i++) {
            if (table.find(str1[i]) != table.end()) {
                if (table[str1[i]] != str2[i]) {
                    return false; // Mapping conflict
                }
            } else {
                table[str1[i]] = str2[i]; // Create a new mapping
            }
        }
        return true;
    }

public:
    Solution(string str1, string str2) : str1(str1), str2(str2) {}

    bool isIsomorphic() {
        if (str1.length() != str2.length()) {
            return false; // Strings must be of the same length to be isomorphic
        }
        return check(str1, str2) && check(str2, str1);
    }
};

int main() {
    // Example usage
    Solution sol("paper", "title");
    cout << boolalpha << sol.isIsomorphic() << endl; // Expected output: true

    Solution sol2("foo", "bar");
    cout << boolalpha << sol2.isIsomorphic() << endl; // Expected output: false

    return EXIT_SUCCESS;
}
