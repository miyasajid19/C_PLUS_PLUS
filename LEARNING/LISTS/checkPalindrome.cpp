#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int value) : value(value), Next(nullptr) {}
};

class LinkedLists
{
public:
    Node *head;
    LinkedLists() : head(nullptr) {}
    void add(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }
    void display() const
    {
        if (!head)
        {
            cout << "there is nothing to display" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "NULL" << endl;
    }
};

bool checkPalindrome(Node *head)
{
    Node *pointer1 = head;
    Node *pointer2 = head;
    while(pointer2 and pointer2->Next)
    {
        pointer1=pointer1->Next;
        pointer2=pointer2->Next->Next;
    }
    Node* currentPointer=pointer1->Next;
    Node* previousPointer=pointer1;
    pointer1->Next=nullptr;
    while(currentPointer)
    {
        Node* nextNode=currentPointer->Next;
        currentPointer->Next=previousPointer;
        previousPointer=currentPointer;
        currentPointer=nextNode;
    }
    Node* head1=head;
    Node* head2=previousPointer;
    while ((head2))
    {
        if(head1->value!=head2->value)
        {
            return false;
        }
        head1=head1->Next;
        head2=head2->Next;
    }
    return true;
}
int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LinkedLists list1, list2;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    list1.add(3);
    list1.add(2);
    list1.add(1);
    list1.display();
    cout<<boolalpha;
    cout<<checkPalindrome(list1.head);
    return EXIT_SUCCESS;
}
