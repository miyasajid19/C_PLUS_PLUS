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

class CircularLinkedlist
{
public:
    Node *head = nullptr;

    void insertAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = new_node;
            new_node->Next = head;
            return;
        }
        Node *tail = head;
        while (tail->Next != head)
        {
            tail = tail->Next;
        }
        tail->Next = new_node;
        new_node->Next = head;
    }

    void insertAtHead(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = new_node;
            new_node->Next = head;
            return;
        }
        Node *tail = head;
        while (tail->Next != head)
        {
            tail = tail->Next;
        }
        new_node->Next = head;
        head = new_node;
        tail->Next = head;
    }

    void insertAtIndex(int value, int index)
    {
        if (index < 0)
        {
            cout << "Index cannot be negative." << endl;
            return;
        }

        if (index == 0)
        {
            insertAtHead(value);
            return;
        }

        Node *new_node = new Node(value);
        Node *temp = head;
        int counter = 0;

        while (counter < index - 1 && temp->Next != head)
        {
            temp = temp->Next;
            counter++;
        }

        if (counter < index - 1)
        {
            cout << "Index out of bounds. Inserting at the end." << endl;
            insertAtTail(value);
            return;
        }

        new_node->Next = temp->Next;
        temp->Next = new_node;
    }

    void deleteFromHead()
    {
        if (!head)
        {
            cout << "The circular linked list is empty." << endl;
            return;
        }

        if (head->Next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *tail = head;
        while (tail->Next != head)
        {
            tail = tail->Next;
        }

        Node *temp = head;
        head = head->Next;
        tail->Next = head;
        delete temp;
    }

    void deleteFromTail()
    {
        if (!head)
        {
            cout << "The circular linked list is empty." << endl;
            return;
        }

        if (head->Next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

        while (temp->Next != head)
        {
            prev = temp;
            temp = temp->Next;
        }

        prev->Next = head;
        delete temp;
    }

    void update(int value, int index)
    {
        if (!head)
        {
            cout << "The circular linked list is empty, so can't update." << endl;
            return;
        }

        Node *temp = head;
        int counter = 0;

        while (counter < index && temp->Next != head)
        {
            temp = temp->Next;
            counter++;
        }

        if (counter < index)
        {
            cout << "Index out of bounds. Cannot update." << endl;
            return;
        }

        temp->value = value;
    }

    void display()
    {
        if (!head)
        {
            cout << "The circular linked list is empty." << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->value << " ";
            temp = temp->Next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    CircularLinkedlist circularLL;
    circularLL.insertAtTail(1);
    circularLL.insertAtTail(2);
    circularLL.insertAtTail(3);
    circularLL.insertAtTail(4);
    circularLL.insertAtHead(1);
    circularLL.insertAtHead(2);
    circularLL.insertAtHead(3);
    circularLL.insertAtHead(4);
    circularLL.display();

    circularLL.insertAtIndex(5, 5);
    circularLL.display();
    circularLL.deleteFromHead();
    circularLL.display();
    circularLL.deleteFromHead();
    circularLL.display();
    circularLL.deleteFromHead();
    circularLL.display();
    circularLL.deleteFromHead();
    circularLL.display();
    circularLL.deleteFromHead();
    circularLL.display();
    circularLL.update(432, 0);
    circularLL.display();
    circularLL.update(433, 1);
    circularLL.display();
    circularLL.update(434, 2);
    circularLL.display();
    circularLL.update(435, 3);
    circularLL.display();
    circularLL.update(407, 4);
    circularLL.display();
    circularLL.update(432, 5);
    circularLL.display();
    circularLL.deleteFromTail();
    circularLL.display();
    circularLL.deleteFromTail();
    circularLL.display();
    circularLL.deleteFromTail();
    return EXIT_SUCCESS;
}
