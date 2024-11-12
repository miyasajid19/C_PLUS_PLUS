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
        while (!head)
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
            cout << "there is nothing to show" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }
    void deleteFromEnd(int index)
    {
        Node *pointer1 = head;
        Node *pointer2 = head;
        while (index--)
        {
            pointer2 = pointer2->Next;
        }
        if (!pointer2)
        {
            Node* temp=head;
            head=head->Next;
            delete[] temp;
            return;
        }
        while (pointer2->Next)
        {
            pointer2 = pointer2->Next;
            pointer1 = pointer1->Next;
        }
        Node *temp = pointer1->Next;
        pointer1->Next = pointer1->Next->Next;
        delete temp;
    }
};

int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LinkedLists list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    list1.add(5);
    list1.display();
    list1.deleteFromEnd(2);
    list1.display();
    list1.deleteFromEnd(2);
    list1.display();
    list1.deleteFromEnd(3);
    list1.display();
    return EXIT_SUCCESS;
}
// this program assumes that index is always less than or equal to total length
