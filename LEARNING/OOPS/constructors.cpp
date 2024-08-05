#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Students
{

public:
    string name;
    int age;
    float gpa;
    Students(string n, int a, int g)
    {
        name = n;
        age = a;
        gpa = g;
    }
    void print()
    {
        cout << name << " " << age << " " << gpa << endl;
    }
};
void print(Students s)
{

    cout << s.name << " " << s.age << " " << s.gpa << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Students s("sajid miya", 20, 9.55);
    s.print();
    
    // class constructed via default constructor if default is not defined as if we define the constructor then default constructor is  overwritten and so we have to redeclare it
    //  Students s;
    //  s.name="sajid miya";
    //  s.age=20;
    //  s.gpa=9.51;
//however we can print it via both approaches
    print(s);
    cout<<s.name<< " "<<s.age<<" "<< s.gpa<<endl;

    return EXIT_SUCCESS;
}