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
        this->Next = nullptr;
    }
};
class LinkedLists
{
public:
    Node *head;
    LinkedLists()
    {
        head = nullptr;
    }
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
    void display()
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
Node *merge(Node *head1, Node *head2)
{
    Node *temp = new Node(-1);
    Node *pointer1 = head1;
    Node *pointer2 = head2;
    Node* ans=temp;
    while (pointer1 and pointer2)
    {
        if (pointer1->value < pointer2->value)
        {
            ans->Next = pointer1;
            pointer1 = pointer1->Next;
        }
        else
        {
            ans->Next = pointer2;
            pointer2 = pointer2->Next;
        ans=ans->Next;
        }
        ans=ans->Next;
    }
    if (pointer1)
    {
        ans->Next = pointer1;
        pointer1 = pointer1->Next;
    }
    if (pointer2)
    {
        ans->Next = pointer2;
        pointer2 = pointer2->Next;
    }
    return temp->Next;
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
    list1.add(5);
    list1.display();
    list2.add(407);
    list2.add(432);
    list2.add(433);
    list2.add(434);
    list2.display();
    LinkedLists ans;
    ans.head = merge(list1.head, list2.head);
    ans.display();
    return EXIT_SUCCESS;
}