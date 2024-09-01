#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

int useofflush() {
    cout << "This is a message that will be immediately flushed to the console." << flush;
    // Simulate a delay
    this_thread::sleep_for(chrono::seconds(2));
    
    cout << "\nThis message appears after a 2 second delay." << endl;
    
    cout << "This is a message that will be immediately flushed to the console." << flush;
    cout << "This is another message that will be immediately flushed to the console." << flush;
    return 0;
}

void format() {
    struct Student {
        string name;
        int age;
        string address;
        string contact;
    };

    cout << "How many students do you have? ";
    int size;
    cin >> size;
    
    vector<Student> students(size);
    for (int i = 0; i < size; ++i) {
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Age: ";
        cin >> students[i].age;
        cout << "Address: ";
        cin >> students[i].address;
        cout << "Contact: ";
        cin >> students[i].contact;
    }  
    
    cout << left << setw(20) << "Name" 
         << setw(10) << "Age" 
         << setw(20) << "Address" 
         << setw(20) << "Contact" << endl;
    
    for (const auto& student : students) {
        cout << left << setw(20) << student.name 
             << setw(10) << student.age 
             << setw(20) << student.address 
             << setw(20) << student.contact << endl;
    }
}
void convert()
{
    cout<<endl<<dec<<showbase<<407432;
    cout<<endl<<hex<<showbase<<407432;
    cout<<endl<<oct<<showbase<<407432;
    cout<<endl<<hex<<showbase<<uppercase<<1717117;// to display the hexadexcimal digits into uppercase
    //it is applicable for only integers not floatinng  point integers

    //scientfic notations
}

int main() {
    //format();
    cout<<boolalpha<<(5==34);
    cout<<noboolalpha<<(5==34);
/*
    // to show the sign of the enterred integers
    int num;
    cout<<endl<<endl<<"enter any integers : ";
    cin>> num;
    cout<<endl<<endl<<showpos<<num;
    cout<<endl<<endl<<noshowpos<<55;// this is not necessary to define
    
*/
convert();
float val=299792458;// valid for float and double not for intgers
    cout<<endl<<scientific<<val;
    cout<<fixed;// to revert back scientific
    cout<<endl<<setprecision(100)<<(double)22/7;
    cout<<endl<<setprecision(2)<<(float)22/7;
    cout<<endl<<setprecision(5)<<(float)22/7;
    cout<<endl<<setprecision(10)<<(float)22/7;
    return 0;
}
