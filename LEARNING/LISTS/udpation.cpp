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
        Next = NULL;
    }
};

// Function to insert at the head of the list
void insertAtHead(Node *&Head, int value)
{
    Node *new_node = new Node(value);
    new_node->Next = Head;
    Head = new_node;
}

// Function to insert at the tail of the list
void insertAtTail(Node* &Head, int value)
{
    Node* new_node = new Node(value);
    if (Head == NULL)
    {
        insertAtHead(Head, value);
        return;
    }
    Node* temp = Head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = new_node;
}

// Function to insert at a specific position
void insert(Node* &Head, int value, int position)
{
    if (position < 0) // Invalid position
        return;

    if (position == 0)
    {
        insertAtHead(Head, value);
        return;
    }

    Node* new_node = new Node(value);
    int currentposition = 0;
    Node* temp = Head;

    // Traverse to the node before the insertion point
    while (temp != NULL && currentposition < position - 1)
    {
        temp = temp->Next;
        currentposition++;
    }

    if (temp == NULL) // If position is greater than the length of the list
    {
        delete new_node; // Avoid memory leak
        return;
    }

    new_node->Next = temp->Next;
    temp->Next = new_node;
}

// Function to update a node value at a specific index
void update(Node* &Head, int value, int index)
{
    if (index < 0) // Invalid index
        return;

    int currentPosition = 0;
    Node* temp = Head;

    // Traverse to the node at the given index
    while (temp != NULL && currentPosition < index)
    {
        temp = temp->Next;
        currentPosition++;
    }

    if (temp == NULL) // Index is out of bounds
        return;

    temp->value = value;
}

// Function to display the list
void display(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->value << " -> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}

// Destructor to free allocated memory
void deleteList(Node*& Head)
{
    Node* temp;
    while (Head != NULL)
    {
        temp = Head;
        Head = Head->Next;
        delete temp;
    }
}

int main()
{
#ifndef online_judge
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node *Head = NULL;
    insertAtHead(Head, 3);
    display(Head);

    insertAtHead(Head, 1);
    display(Head);

    insertAtTail(Head, 4);
    display(Head);

    insert(Head, 432, 1);
    display(Head);

    update(Head, 407, 2);
    display(Head);

    // Free allocated memory
    deleteList(Head);
    
    return EXIT_SUCCESS;
}
