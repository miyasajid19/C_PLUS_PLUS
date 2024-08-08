#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
    Person() {}
    Person(string name, int age, string address, int uid)
    {
        this->address = address;
        this->age = age;
        this->name = name;
        this->uid = uid;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    void setUID(int uid)
    {
        this->uid = uid;
    }
    void display()
    {
        cout << this->uid << " " << this->name << " " << this->age << " " << this->address << endl;
    }

private:
    string address;

protected:
    long uid;
};

class Footballer : public Person
{
public:
    string country;
    string club;
    Footballer() {}
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    void setContract(string contract)
    {
        this->contract = contract;
    }
    void showPlayer()
    {
        see();
    }

private:
    float salary;

protected:
    string contract;
    void see()
    {
        cout << this->uid << " " << this->name << " " << this->age << " " << this->country << " " << this->club << " " << this->contract << " " << this->salary << endl;
    }
};

class Ronaldo : public Footballer// multiple inheritance
{
public:
    void show()
    {
        display();
        showPlayer();
        cout << "I am The G.O.A.T." << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string name, address;
    int age, uid;
    cout << "Enter UID, name, address, and age of the person: " << endl;
    cin >> uid >> name >> address >> age;
    Person p(name, age, address, uid);
    p.display();
    
    // Manually setting
    Person q;
    cout << "Enter UID, name, address, and age of the person: " << endl;
    cin >> uid >> name >> address >> age;
    q.age = age;
    q.name = name;
    q.setAddress(address);
    q.setUID(uid);
    q.display();
    
    // Footballer 
    Footballer f;
    string club, country, contract;
    float salary;
    cout << "Enter UID, name, address, age, club, country, contract (in years), and salary of the player: " << endl;
    cin >> uid >> name >> address >> age >> club >> country >> contract >> salary;
    f.age = age;
    f.name = name;
    f.setAddress(address);
    f.setUID(uid);
    f.club = club;
    f.country = country;
    f.setSalary(salary);
    f.setContract(contract);
    f.showPlayer();
    
    Ronaldo cr7;
    cr7.name = "Cristiano Ronaldo";
    cr7.age = 39;
    cr7.club = "Al Nassr FC";
    cr7.country = "Portugal";
    cr7.setAddress("Abu Dhabi");
    cr7.setUID(7);
    cr7.setContract("5 years");
    cr7.setSalary(500000000);
    cr7.show();
    
    return EXIT_SUCCESS;
}
