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

// Function to insert at the head of the list
void insertAtHead(Node *&Head, int value)
{
    Node *new_node = new Node(value);
    new_node->Next = Head;
    Head = new_node;
}

// Function to insert at the tail of the list
void insertAtTail(Node *&Head, int value)
{
    Node *new_node = new Node(value);
    if (Head == nullptr)
    {
        insertAtHead(Head, value);
        return;
    }
    Node *temp = Head;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
    }
    temp->Next = new_node;
}

// Function to insert at a specific position
void insert(Node *&Head, int value, int position)
{
    if (position < 0) // Invalid position
        return;

    if (position == 0)
    {
        insertAtHead(Head, value);
        return;
    }

    Node *new_node = new Node(value);
    int currentposition = 0;
    Node *temp = Head;

    // Traverse to the node before the insertion point
    while (temp != nullptr && currentposition < position - 1)
    {
        temp = temp->Next;
        currentposition++;
    }

    if (temp == nullptr) // If position is greater than the length of the list
    {
        delete new_node; // Avoid memory leak
        return;
    }

    new_node->Next = temp->Next;
    temp->Next = new_node;
}

void deleteAtHead(Node *&Head)
{
    if (Head == nullptr) // Empty list
        return;

    Node *temp = Head;
    Head = Head->Next;
    delete temp;
}

void pop(Node *&Head)
{
    if (Head == nullptr || Head->Next == nullptr) // Empty or single-element list
    {
        deleteAtHead(Head);
        return;
    }

    Node *secondLast = Head;
    while (secondLast->Next->Next != nullptr)
    {
        secondLast = secondLast->Next;
    }
    Node *temp = secondLast->Next;
    secondLast->Next = nullptr;
    delete temp;
}

void DeleteFrom(Node *&Head, int index)
{
    if (index < 0) // Invalid index
        return;

    if (index == 0)
    {
        deleteAtHead(Head);
        return;
    }

    int currentIndex = 0;
    Node *previous = Head;
    while (previous != nullptr && currentIndex < index - 1)
    {
        previous = previous->Next;
        currentIndex++;
    }

    if (previous == nullptr || previous->Next == nullptr) // Out of bounds
        return;

    Node *temp = previous->Next;
    previous->Next = previous->Next->Next;
    delete temp;
}

// Function to display the list
void display(Node *Head)
{
    Node *temp = Head;
    while (temp != nullptr)
    {
        cout << temp->value << " -> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}

int main()
{
#ifndef online_judge
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node *Head = nullptr;

    insertAtHead(Head, 3);
    display(Head);

    insertAtHead(Head, 1);
    display(Head);

    insertAtTail(Head, 4);
    display(Head);

    insert(Head, 432, 1);
    display(Head);

    deleteAtHead(Head);
    display(Head);

    pop(Head);
    display(Head);

    insertAtTail(Head, 123);
    display(Head);

    insert(Head, 407, 1);
    display(Head);

    DeleteFrom(Head, 2);
    display(Head);

    return EXIT_SUCCESS;
}
