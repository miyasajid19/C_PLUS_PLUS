#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Employee
{
public:
    string name;
    int uid;
    float salary;
    long long phoneno;
    Employee()
    {

    }
    Employee(string name, int uid, float salary,long long phoneno)
    {
        this->name=name;
        this->salary=salary;
        this->uid=uid;
        this->phoneno=phoneno;
    }
    void display()
    {
        cout<<name<<" "<<salary<<" "<<uid<<" "<<phoneno<<endl;
    }
};
void change(Employee* emp)
{
    string name;
    float salary;
    int uid;
    long long phoneno;
    cout<<"enter name uid salary and phoneno. of employee"<<endl;
    cin>>emp->name>>emp->uid>>emp->salary>>emp->phoneno;
}
void change1(Employee& emp)
{
    string name;
    float salary;
    int uid;
    long long phoneno;
    cout<<"enter name uid salary and phoneno. of employee"<<endl;
    cin>>emp.name>>emp.uid>>emp.salary>>emp.phoneno;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Employee e("sajid miya",432,250000,9808748490);
    e.display();
    Employee* ptr=&e;//pointer object
    change(ptr);
    e.display();
    // it can be change via this method too
    change1(e);
    e.display();
    return EXIT_SUCCESS;
}
