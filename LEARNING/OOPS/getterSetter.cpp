#include <iostream>
#include <cstdlib>
#include <string>
#include<vector>
using namespace std;
class Students
{
private:
    int uid;
    float gpa;
public:
    string name;
    string address;
    Students()
    {

    }
    Students(int uid, string name, string address,float gpa)
    {
     this->address=address;
     this->gpa=gpa;
     this->name=name;     
        this->uid=uid;
    }
    void setuid(int a)
    {
        this->uid=a;
    }
    void getuid()
    {
        cout<<uid<<endl;
    }
    void setgpa(float a)
    {
        this->gpa=a;
    }
    void getgpa()
    {
        cout<<gpa<<endl;
    }
    void print()
    {
        cout<<uid<<" "<<name<<" "<<address<<" "<<gpa<<endl;
    }

};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
Students student;
student.name="sajid miya";
student.address="Hospital chowk gorkha";
student.setuid(432);
student.setgpa(9.55);
student.getgpa();
student.getuid();
student.print();
//array 
int size; 
cout<<"how many data do you have? "<<endl;
cin>>size;
int id;
float cgpa;
Students stds[size];
for (int i =0;i<size;i++){
    cout<<"enter uid ,name ,address and gpa of the studetnts"<<endl;
    cin>>id>>stds[i].name>>stds[i].address>>cgpa;
    stds[i].setuid(id);
    stds[i].setgpa(cgpa);
}
for(int i =0;i<size;i++)
{
    stds[i].print();
}
//vector
string name ,address;
vector<Students>s;
for (int i =0;i<size;i++){
    cout<<"enter uid ,name ,address and gpa of the studetnts"<<endl;
    cin>>id>>name>>address>>cgpa;
    s.push_back(Students(id,name,address,cgpa));

}
for(int i =0;i<size;i++)
{
    s[i].print();
}

return EXIT_SUCCESS;
}