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
    void print()
    {
        cout<<name<< " "<<age<<" "<< gpa<<endl;
    }
};
void print(Students s)
{

    cout<<s.name<< " "<<s.age<<" "<< s.gpa<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
//class constructed via default constructor
    Students s;
    s.name="sajid miya";
    s.age=20;
    s.gpa=9.51;
    s.print();
    // array of class
    int size;
    cout<<"how many students do you have ? "<<endl;
    cin>>size;
    Students student[size];
    for (int i =0;i<size;i++)
    {
        cout<<"enter name, age, gpa  of student "<<i+1<<endl;
        cin>>student[i].name>>student[i].age>>student[i].gpa;
    }
    //printing via function that take argument as class
    for (int i =0;i<size;i++)
    {
        print(student[i]);
    }

    // we can print directly via below process
    cout<<s.name<< " "<<s.age<<" "<< s.gpa<<endl;
    
    return EXIT_SUCCESS;
}