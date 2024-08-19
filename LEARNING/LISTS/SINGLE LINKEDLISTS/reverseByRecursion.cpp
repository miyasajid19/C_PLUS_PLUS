#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int value)
    {
        this->value = value;
        this->Next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }


    void insert(int value)
    {
        Node *new_node = new Node(value);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }

    void display()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->value<<"->";
            temp=temp->Next;
        }
        cout<<"NULL"<<endl;
    }
};

Node* reverseRecurrsion(Node* &head)
{
    if (head==NULL  or head->Next==NULL)
    {
        return head;
    }
    Node* new_head=reverseRecurrsion(head->Next);
    head->Next->Next=head;
    head->Next=NULL;
    return new_head;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("..input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
LinkedList l1;
l1.insert(432);
l1.display();
l1.insert(1);
l1.display();
l1.insert(2);
l1.display();
l1.insert(3);
l1.display();
l1.insert(8);
l1.display();
l1.insert(7);
l1.display();
l1.insert(6);
l1.display();
l1.insert(407);
l1.display();
l1.head=reverseRecurrsion(l1.head);
l1.display();
    return EXIT_SUCCESS;
}
