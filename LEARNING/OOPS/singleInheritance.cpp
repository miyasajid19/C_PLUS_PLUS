#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class scooty
{
public:
    int topSpeed;
    float milege;

    // Constructor
    scooty(int topSpeed, float milege) : topSpeed(topSpeed), milege(milege), bootspace(true) {}

    void display()
    {
        cout << topSpeed << " " << milege << " " << boolalpha << bootspace << endl;
    }

private:
    bool bootspace;
};

class bike : public scooty
{
public:
    int gears;

    // Constructor
    bike(int topSpeed, float milege, int gears) : scooty(topSpeed, milege), gears(gears) {}

    // Default constructor
    bike() : scooty(0, 0), gears(0) {}

    void display()
    {
        cout << topSpeed << " " << milege << " " << gears << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    scooty s(123, 22.3);
    s.display();

    bike a;
    a.gears = 7;
    a.milege = 1234;
    a.topSpeed = 70;
    a.display();

    return EXIT_SUCCESS;
}
