#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Students
{

public:
    string name;
    int age;
    float gpa;
    // default constructor
    Students()
    {
    }
    // parameterized constructor
    Students(string name, int age, float gpa)
    {
        //  this will give the garbage value
        // name = name;
        // age = age;
        // gpa=gpa;
        this->name = name;
        this->age = age;
        this->gpa = gpa;

    }
    void print()
    {
        cout << name << " " << age << " " << gpa << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
Students s("sajid miya",20,9);
s.print();
   return EXIT_SUCCESS;
}