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
    Students(string n, int a, float g)
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
void change(Students s)
{
    s.name="miya sajid";
    cout << s.name << " " << s.age << " " << s.gpa << endl;
}
void Change(Students& s)
{
    s.name="ALL I WANT WAS THE LOVE AND WHAT I GET IS THE PAIN";
}
void Change1(Students* s)
{
cout<<"enter the new name, age and gpa"<<endl;
int age;
float cga;
string name;
cin>>name>>age>>cga;
s->age=age;
s->name=name;
s->gpa=cga;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    //this is sallow copy change in s2 object doesnot affect thes1 object
    Students s1("sajid miya", 20, 9.55);
    s1.print();
    Students s2;
    s2=s1;
    s2.name="SAJID MIYA";
    s2.print();
    change(s1);
    s1.print();
   
    //this is HARD copy change in s2 object doesnot affect thes1 object
    s1.print();
    Change(s1);
    s1.print();
    
    Students s3("i don't know",1,2);
    s3.print();
    Change1(&s3);
    s3.print();

    Students s4(s1);// this is soft copy
    s4.print();
    Change1(&s4);
    s4.print();
    s1.print();
    return EXIT_SUCCESS;
}