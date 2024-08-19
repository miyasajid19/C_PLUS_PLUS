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

    void rotateByK(int k)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty\nHence, rotation of linked list is not possible" << endl;
            return;
        }

        // Count total number of nodes
        Node *temp = head;
        int counter = 1; // Start from 1 to count the head node
        while (temp->Next != nullptr)
        {
            counter++;
            temp = temp->Next;
        }

        // If k is 0 or a multiple of the list's length, no rotation is needed
        k %= counter;
        if (k == 0)
        {
            return;
        }

        // Make the linked list circular
        temp->Next = head;

        // Find the new end of the list after rotating
        int stepsToNewHead = counter - k;
        temp = head;
        for (int i = 1; i < stepsToNewHead; i++)
        {
            temp = temp->Next;
        }

        // Break the loop to finalize the rotated list
        head = temp->Next;
        temp->Next = nullptr;
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

    for (int i = 0; i < 10; i++)
    {
        list.push(i);
        list.display();
    }

    list.rotateByK(3);
    list.display();

    return EXIT_SUCCESS;
}
