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
 //default constructor
    Students()
    {


    }
//parameterized constructor
    Students(string n, int a, float g)
    {
        name = n;
        age = a;
        gpa = g;
    }
    Students(string n,int a)
    {
        name=n;
        age=a;
    }
    Students(string n,float g)
    {
        name=n;
        gpa=g;
    }
    Students( int a, float g)
    {
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
    Students s;
    s.name="sajid miya";
    s.age=20;
    s.gpa=9.55;
    s.print();
    //array can be defined normally int  this method

    Students p("sajid miya",10,9.55);
    p.print();
    //need to define the vector in order to store data in array

    Students q("sajid miya",10);//takes string and interger as parameter
    q.gpa=9.55;// takes gpa separately;
    q.print();

    Students t("sajid miya",float(9.55));//takes string and interger as parameter
    t.age=20;// takes gpa separately;
    t.print();

    Students u(20,9.55);
    u.name="sajid miya";
    print(u);
    return EXIT_SUCCESS;
}