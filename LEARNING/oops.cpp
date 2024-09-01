/*
Attributes and methods are basically variables and functions that belongs to the class. These are often referred to as "class members".
A class is a user-defined data type that we can use in our program, and it works as an object constructor, or a "blueprint" for creating objects.
*/
// class is blueprint for creating object
//object is created from class
// methods are the function that belongs to the class
//The constructor has the same name as the class, it is always public, and it does not have any return value.
#include<iostream>
#include <cstdlib>
using namespace std;
class first
{

public:
    int age;
    string standard;
    void printing()// this is the method
    // simply this if function associated with the first class'
    // and this is inside class defination method
    {
        cout << "your age is "<<age<<" and you are studying in the "<<standard<< " standard";    
    }
};
class second{
    public:
        int age;
        string standard;
        void toprint();
};
void second :: toprint()// this the method and this is  outside class defination method
{
    cout << "your age is "<<age<<" and you are studying in the "<<standard<< "standard";
}
class myclass
{
    public:
        myclass()
            {
                cout<<"\n\ni am constructor\a\n";
                cout<<"The constructor has the same name as the class, it is always public, and it does not have any return value.";
            }
};
class cars
{
    public:
        string brand;
        string model;
        int year;
        cars(string x, string y, int z)// this is construction inside class
        {
            brand=x;
            model=y;
            year= z;
        }
        void forprint();// this is outside method defination class
};
void cars :: forprint()
{
    cout<<"model : "<<model<<endl<<"brand : "<<brand<<endl<<"year : "<<year<<endl;
}
class Cars{
    public:// access specifier
        string brand;
        string model;
        int year;
        Cars(string x,string y, int z);// construction declaration
        void forprint()
        {
            cout<<"model : "<<model<<endl<<"brand : "<<brand<<endl<<"year : "<<year<<endl;
        }
};
Cars :: Cars(string x, string y, int z)
{
    brand=x;
    model=y;
    year=z;
}
int main1()
{
    first firstobj;
    cout << "enter age  : ";
    cin >> firstobj.age;
    cout<< "enter the class you are studying in ?";
    cin >> firstobj.standard;
    firstobj.printing();
    second secondobj;
    secondobj.age=19;
    secondobj.standard="BE/B.Tech";
    secondobj.toprint();
    myclass obj;
    
    return 0;
}
int main2()
{
    cars car1("lamborgini","x1",2022);
    car1.forprint();
    Cars car2("rolls royals","x2",2024);
    car2.forprint();
    return 0;
}
class employee
{
    private:
        float salary;
        string contact;
    
    public:
        string name;
        string address;
        int age;
    // we can't have direct access to the private access specifer but we can have access via getter and setter
    public:
        void setprivate(float x, string y)
        {
            salary=x;
            contact=y;
        }
        int getsalary()
        {
            return salary;
        }
        string getcontact()
        {
            return contact;
        }
    void printit()
    {
        cout<<"Name : "<<name<<endl<<"Age : "<<age<<"\nAddress : "<<address<<"\nsalary : "<<salary<<"\ncontact : "<<contact; 
    }
};
class vehicle{
    public:
        string model;
        void honk()
        {
            cout<<"Tut Tut!!!\n\n\n";
        }
};
class bike: public vehicle
{
    public:
        string brand;
};
void encapsulation()
{
    //access specifiers : public , private , protected
    /*
    In C++, there are three access specifiers:

public - members are accessible from outside the class
private - members cannot be accessed (or viewed) from outside the class
protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.
    */
   // if public access specifeir is not defined in class then by default all members are private 
   employee  emp1;
   emp1.name="sajid miya";
   emp1.address="gorkha";
   emp1.age=20;
   emp1.setprivate(407432,"miyasajid19@gmail.com");
   emp1.printit();
   cout<<endl<<endl;
   cout<<"salary : "<<emp1.getsalary();
   cout<<endl;
   cout<<"Contact : "<<emp1.getcontact();
   
}
void inheritance()
{
    bike bike1;
    bike1.brand="i don't know";
    bike1.model="NS 200";
    bike1.honk();
    cout<<bike1.model<< "\t\t"<<bike1.brand;

}
class one{
    public:
    void print1()
    {
        cout<<"this is the content of first class\n";
    }
};
class two
{
    public:
    void print2()
    {
        cout<< "this is the content of second class\n";
    }
};
class three{
    public:
        void print3()
        {
            cout<<"this is the content of third class";
        }
};
class all : public one, public two, public three{

};
void mutlilevel()
{
  all allinone;
  allinone.print1();
  allinone.print2();
  allinone.print3();

}
class student
{
    protected:
        float marks;
    public:
        string name;
};
class result: public student
{
    public:
        void setmarks(float a)
        {
            marks=a;
        }
        float getmarks()
        {
            return marks;
        }
};
void protected1()
{
    result res1;
    res1.name="sajid miya";
    res1.setmarks(432.407);
    cout<<"Name  : "<<res1.name<<"\nMarks : "<<res1.getmarks();
}
class animals
{
    public:
        void sound()
        {
            cout<< " if they have vocal cord then they make sound";
        }
};
class dog :public animals
{
    public:
    void sound()
    {
        cout<<"\nit barks";
    }
};

class tiger :public animals
{
    public:
    void sound()
    {
        cout<<"\nit roars";
    }
};
void poly()
{
    animals animal;
    dog dog1;
    tiger tiger1;
    animal.sound();
    dog1.sound();
    tiger1.sound();
}
int main()
{
    poly();
}