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
    Employee(string name, int uid, float salary, long long phoneno)
    {
        this->name = name;
        this->salary = salary;
        this->uid = uid;
        this->phoneno = phoneno;
    }
    void display()
    {
        cout << name << " " << salary << " " << uid << " " << phoneno << endl;
    }
};
void change(Employee *emp)
{
    string name;
    float salary;
    int uid;
    long long phoneno;
    cout << "enter name uid salary and phoneno. of employee" << endl;
    cin >> emp->name >> emp->uid >> emp->salary >> emp->phoneno;
}
void change1(Employee &emp)
{
    string name;
    float salary;
    int uid;
    long long phoneno;
    cout << "enter name uid salary and phoneno. of employee" << endl;
    cin >> emp.name >> emp.uid >> emp.salary >> emp.phoneno;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Employee e1("itachi uchiha", 1, 123123, 23231213123);
    Employee *e2 = new Employee("Obito Uchiha", 3, float(324423.234), 234);
    e1.display();
    e2->display();
    // creating array
    int size;
    cout << "how many data do you have?" << endl;
    cin >> size;
    Employee employee[size];
    for (int i = 0; i < size; i++)
    {
        cout << "enter the details of employee " << i + 1 << endl;
        cin >> employee[i].name >> employee[i].uid >> employee[i].salary >> employee[i].phoneno;
    }

    for (int i = 0; i < size; i++)
    {
        employee[i].display();
    }

    Employee *emp = new Employee[size];

    for (int i = 0; i < size; i++)
    {
        cout << "enter the details of employee " << i + 1 << endl;
        cin >> employee[i].name >> employee[i].uid >> employee[i].salary >> employee[i].phoneno;
    }

    for (int i = 0; i < size; i++)
    {
        employee[i].display();
    }
    // via vector method
    vector<Employee> emps;
    string name;
    float salary;
    int uid;
    long long phoneno;

    for (int i = 0; i < size; i++)
    {
        cout << "enter the details of employee " << i + 1 << endl;
        cin >> name >> uid >> salary >> phoneno;
        emps.push_back(Employee(name,uid,salary,phoneno));
        // without createign the class we can use .emplace_back function to create vectors
        // emps.emplace_back(name, uid, salary, phoneno);
    }

    for (int i = 0; i < size; i++)
    {
        emps[i].display();
    }
    return EXIT_SUCCESS;
}
