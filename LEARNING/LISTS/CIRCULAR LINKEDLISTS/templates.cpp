#include <iostream>
#include<cstdlib>
#include<string>
using namespace std;
template<typename T>
class Node{
    public:
    T value;
    Node* Next;
    Node(T value)
    {
        this->value=value;
        this->Next=nullptr;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../..input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
Node<int>* node1=new Node<int>(1);
cout<<node1->value<<endl;

Node<char>* node2=new Node<char>(97+18);
cout<<node2->value<<endl;

Node<string>* node3=new Node<string>("all i want was the love and what i get is the pain");
cout<<node3->value<<endl;

Node<bool>* node4=new Node<bool>(true);
cout<<boolalpha<<node4->value<<endl;

    return EXIT_SUCCESS;
}