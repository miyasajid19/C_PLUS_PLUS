#include <iostream>
#include <cstdlib>
using namespace std;
class demo
{
private:
    int a;

protected:
    int b;

public:
    int c;
    demo()
    {
        this->a=432;
        this->b=407;
        this->c=a+b;
    }
};
class Child:public demo{

};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
Child A();
cout<<A.c;
    return EXIT_SUCCESS;
}