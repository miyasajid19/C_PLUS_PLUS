#include <iostream>
#include <cstdlib>
using namespace std;
class A
{
public:
    int a;
    void set(int a)
    {
        this->a = a;
    }
    int get()
    {
        return this->a;
    }
};
class B : public virtual A
{
    int b;
};
class C : public virtual A
{
    int c;
};
class D : public B, public C
{
    int d;
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
cout<<"all i want was the loe and what i get is the  pain"<<endl;
D d;
// without using the virtual keyword accessing the attribute of class D will result ambiguiopus
d.set(432);
cout<<d.get()<<endl;
    return EXIT_SUCCESS;
}