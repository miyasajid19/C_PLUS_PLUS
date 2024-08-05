#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Players {
public:
    string country;
    string name;
    int matches;
    int goals;

    Players() {}

    Players(string name, string country, int matches, int goals) {
        this->name = name;
        this->country = country;
        this->matches = matches;
        this->goals = goals;
    }

    float avg() {
        if (matches == 0) return 0;
        return static_cast<float>(goals) / matches;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // Real data for Ronaldo, Messi, and Neymar
    Players ronaldo("Cristiano Ronaldo", "Portugal", 201, 123); // Updated as of August 2023
    Players messi("Lionel Messi", "Argentina", 174, 102);      // Updated as of August 2023
    Players neymar("Neymar Jr.", "Brazil", 124, 77);           // Updated as of August 2023
    cout<<ronaldo.name<<"    "<<ronaldo.avg()<<endl;
    cout<<messi.name<<"    "<<messi.avg()<<endl;
    cout<<neymar.name<<"    "<<neymar.avg()<<endl;

    return EXIT_SUCCESS;
}
