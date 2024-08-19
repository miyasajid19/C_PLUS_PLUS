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

    void push(int value)
    {
        Node *new_node = new Node(value);
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

    void Pop()
    {
        if (head == nullptr)
        {
            cout << "There is nothing to remove" << endl;
            return;
        }
        if (head->Next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->Next->Next != nullptr)
        {
            temp = temp->Next;
        }
        delete temp->Next;
        temp->Next = nullptr;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "The linked list is empty\nHence, there is nothing to display" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }

    void GroupEvenOdd()
    {
        if (not head || not head->Next)
        {
            return;
        }

        Node *oddHead = head;
        Node *evenHead = head->Next;
        Node *oddPointer = oddHead;
        Node *evenPointer = evenHead;

        while (evenPointer && evenPointer->Next)
        {
            oddPointer->Next = evenPointer->Next;
            oddPointer = oddPointer->Next;

            evenPointer->Next = oddPointer->Next;
            evenPointer = evenPointer->Next;
        }

        oddPointer->Next = evenHead; // Connect the last odd node to the first even node
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LinkedLists list;
    list.display();

    for (int i = 15; i > 10; i--)
    {
        list.push(i);
        list.display();
    }

    list.GroupEvenOdd();
    list.display();

    return EXIT_SUCCESS;
}
