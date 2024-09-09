#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int coefficient;
    int index;
    Node *Next;
    Node(int coefficient, int index)
    {
        this->coefficient = coefficient;
        this->index = index;
        this->Next = nullptr;
    }
};
class LinkedList
{
    Node *head;
    LinkedList()
    {
        this->head = nullptr;
    }
    void InsertAtHead(int coefficient, int index)
    {
        Node *new_node = new Node(coefficient, index);
        new_node->Next = head;
        head = new_node;
    }
    void InsertAtTail(int coefficient, int index)
    {
        Node *new_node = new Node(coefficient, index);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }
    void Insert(int coefficient, int power, int index)
    {
        if (index == 0)
        {
            InsertAtHead(coefficient, power);
            return;
        }
        Node *temp = head;
        int counter = 0;
        Node *new_node = new Node(coefficient, power);
        while (temp != nullptr and counter < index)
        {
            temp = temp->Next;
            counter++;
        }
        if (temp = nullptr)
        {
            cout << "Index out of bound" << endl;
            delete new_node;
            return;
        }
        new_node->Next = temp->Next;
        temp->Next = new_node;
    }
    void DeleteFromHead()
    {
        if (head == nullptr)
        {
            cout << "list is alsready empty" << endl;
            return;
        }
        Node *temp = head;
        head=head->Next;
        delete temp;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    cout << "all i want was the love and what i get is the pain" << endl;
    return EXIT_SUCCESS;
}