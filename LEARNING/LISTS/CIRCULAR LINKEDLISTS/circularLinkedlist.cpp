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
        if (!head) // If the list is empty
        {
            head = new_node;
            new_node->Next = head; // Point to itself
            return;
        }
        Node *tail = head;
        while (tail->Next != head) // Find the last node (tail)
        {
            tail = tail->Next;
        }
        // Insert new_node at the head
        tail->Next = new_node;
        new_node->Next = head;
        head = new_node; // Update the head to the new node
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

    return EXIT_SUCCESS;
}
