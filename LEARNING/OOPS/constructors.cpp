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
    // however we can print it via both approaches
    print(s);
    cout << s.name << " " << s.age << " " << s.gpa << endl;

    // array
    int size;
    float gpa;
    string name;
    int age;
    cout << "how many students do you have?" << endl;
    cin >> size;
    // you can not define the array via this process you can use vector
    // Students s[size];

    // for (int i = 0; i < size; i++)
    // {
    //     cout << "enter name, age, gpa  of student " << i + 1 << endl;
    //     cin>>name>>age>>gpa;
    //     s[i](name,age,gpa);
    // }
    vector<Students> student;
    for (int i = 0; i < size; i++)
    {
        cout << "enter name, age, gpa  of student " << i + 1 << endl;
        cin >> name >> age >> gpa;
        Students tempStudent(name, age, gpa);
        student.push_back(tempStudent);
    }
    for (int i = 0; i < size; i++)
    {
        student[i].print();
    }
    return EXIT_SUCCESS;
}