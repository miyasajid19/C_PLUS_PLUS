#include <iostream>
#include <cstdlib>
using namespace std;
class demo
{
    int value;

public:
    demo()
    {
        value = 0;
    }
    demo(int a) : value(a) {}
    demo operator++()
    {
        return demo(this->value++);
    }
    void display()
    {
        cout<<"value -------> "<<this->value<<endl;
    }
};
int main()
{
demo d;
d.display();
(++d).display();//preincremented
d.display();
    return EXIT_SUCCESS;
}