#include<iostream>
#include<cstdlib>
using namespace std;
class Node{
public:
int value;
Node* Next;
Node(int value)
{
    this->value=value;
    Next=NULL;
}

};
int main()
{
    #ifndef JUDGE_ONLINE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    Node* n1=new Node(432);
    cout<<n1->value<<" "<<n1->Next;
    return EXIT_SUCCESS;
}