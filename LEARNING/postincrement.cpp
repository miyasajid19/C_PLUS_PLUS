#include <iostream>
#include<cstdlib>
using namespace std;
class demo{
int value;
public:
demo():value(0){}
demo(int value):value(value){}
demo operator++(int)
{
    demo temp=*this;
    value++;
    return temp;
}
void display()
{
    cout<<"value -----> "<<value<<endl;
}
};
int main()
{
    demo d(432);
    d.display();
    (d++).display();
    d.display();

    return EXIT_SUCCESS;
}