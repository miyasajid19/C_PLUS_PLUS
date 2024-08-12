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
        this->Next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void insertAtHead(int value)
    {
        Node *new_node = new Node(value);
        new_node->Next = head;
        head = new_node;
    }

    void insertAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }

    void insert(int value, int index)
    {
        if (index == 0)
        {
            insertAtHead(value);
            return;
        }

        Node *new_node = new Node(value);
        Node *temp = head;
        int currentIndex = 0;

        while (temp != NULL && currentIndex < index - 1)
        {
            temp = temp->Next;
            currentIndex++;
        }

        if (temp == NULL)
        {
            cout << "Index out of bounds" << endl;
            delete new_node;
            return;
        }

        new_node->Next = temp->Next;
        temp->Next = new_node;
    }

    void deleteFromHead()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->Next;
        delete temp;
    }

    void pop()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->Next == NULL)
        {
            deleteFromHead();
            return;
        }

        Node *secondLast = head;
        while (secondLast->Next->Next != NULL)
        {
            secondLast = secondLast->Next;
        }

        Node *lastNode = secondLast->Next;
        secondLast->Next = NULL;
        delete lastNode;
    }

    void deleteFrom(int index)
    {
        if (index == 0)
        {
            deleteFromHead();
            return;
        }
        if (index < 0)
        {
            cout << "Index out of bounds" << endl;
            return;
        }

        Node *previous = head;
        int currentIndex = 0;

        while (currentIndex < index - 1 && previous->Next != NULL)
        {
            currentIndex++;
            previous = previous->Next;
        }

        if (previous == NULL || previous->Next == NULL)
        {
            cout << "Index out of bounds" << endl;
            return;
        }

        Node *temp = previous->Next;
        previous->Next = previous->Next->Next;
        delete temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "NULL" << endl;
    }
};

void deleteDulpicates(Node *&head)
{
    Node *current_node = head;
    while (current_node)
    {
        while (current_node->Next and current_node->value == current_node->Next->value)
        {
            Node *temp = current_node->Next;
            current_node->Next = current_node->Next->Next;
            free(temp);
        }
        current_node = current_node->Next;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("..input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LinkedList l1;
    l1.insertAtTail(1);
    l1.display();
    l1.insertAtTail(1);
    l1.display();
    l1.insertAtTail(2);
    l1.display();
    l1.insertAtTail(3);
    l1.display();
    l1.insertAtTail(3);
    l1.display();
    l1.insertAtTail(3);
    l1.display();
    l1.insertAtTail(4);
    l1.display();
    deleteDulpicates(l1.head);
    l1.display();
    return EXIT_SUCCESS;
}
