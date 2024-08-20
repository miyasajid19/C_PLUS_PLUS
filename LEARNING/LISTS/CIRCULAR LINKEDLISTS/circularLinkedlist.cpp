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

    void insertAtIndex(int value, int index)
    {
        if (!head)
        {
            cout << "The circular linked list is empty." << endl;
            return;
        }

        if (index == 0) // Insert at head if index is 0
        {
            insertAtHead(value);
            return;
        }

        Node *new_node = new Node(value);
        Node *temp = head;
        int counter = 0;

        // Traverse the list to the node just before the given index
        while (counter < index - 1 && temp->Next != head)
        {
            temp = temp->Next;
            counter++;
        }

        // If index is beyond the length of the list, insert at the end
        if (temp->Next == head && counter < index - 1)
        {
            cout << "Index out of bounds. Inserting at the end." << endl;
            insertAtTail(value);
            return;
        }

        // Insert new_node after temp
        new_node->Next = temp->Next;
        temp->Next = new_node;
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

    // Insert at index 5 (which is out of bounds in this case)
    circularLL.insertAtIndex(5, 5);
    circularLL.display();

    return EXIT_SUCCESS;
}
