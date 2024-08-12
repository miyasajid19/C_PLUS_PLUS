#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int value;
    Node *Next;
    
    Node(int value) {
        this->value = value;
        Next = NULL;
    }
};

void insertAtHead(Node *&Head, int value) {
    Node* new_node = new Node(value);
    new_node->Next = Head;
    Head = new_node;
}

void insertAtTail(Node* &Head, int value) {
    Node* new_node = new Node(value);
    if (Head == NULL) {
        // If the list is empty, make new_node the head
        Head = new_node;
        return;
    }
    Node* temp = Head;
    while (temp->Next != NULL) {
        temp = temp->Next;
    }
    temp->Next = new_node;
}

void insert(Node* &Head, int value, int position) {
    if (position == 0) {
        insertAtHead(Head, value);
        return;
    }
    Node* new_node = new Node(value);
    int currentPosition = 0;
    Node* temp = Head;
    while (temp != NULL && currentPosition != position - 1) {
        temp = temp->Next;
        currentPosition++;
    }
    if (temp == NULL) {
        // Position is out of bounds
        cout << "Position out of bounds" << endl;
        delete new_node;
        return;
    }
    new_node->Next = temp->Next;
    temp->Next = new_node;
}

void display(Node* Head) {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}

int main() {
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Node* Head = NULL;  // Initialize Head to NULL
    insertAtHead(Head, 3);
    display(Head);
    insertAtHead(Head, 2);
    display(Head);
    insertAtHead(Head, 1);
    display(Head);
    insertAtTail(Head, 4);
    display(Head);
    insertAtTail(Head, 5);
    display(Head);
    insertAtTail(Head, 6);
    display(Head);
    insert(Head, 432, 3);
    display(Head);
    insert(Head, 407, 4);
    display(Head);
    
    // Clean up memory to avoid memory leaks
    while (Head != NULL) {
        Node* temp = Head;
        Head = Head->Next;
        delete temp;
    }

    return EXIT_SUCCESS;
}
