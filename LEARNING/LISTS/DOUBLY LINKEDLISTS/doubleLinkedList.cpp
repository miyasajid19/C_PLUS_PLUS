#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Node
{
public:
    int value;
    Node *Previous;
    Node *Next;
    Node(int value)
    {
        this->value = value;
        this->Previous = nullptr;
        this->Next = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~DoublyLinkedList()
    {
        Erase();
    }

    void insertAtStart(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->Next = head;
        head->Previous = new_node;
        head = new_node;
    }

    void insertAtEnd(int value)
    {
        Node *new_node = new Node(value);
        if (!tail)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->Next = new_node;
        new_node->Previous = tail;
        tail = new_node;
    }

    void insertAtIndex(int value, int index)
    {
        if (index < 0)
        {
            cout << "Invalid index." << endl;
            return;
        }
        if (index == 0)
        {
            insertAtStart(value);
            return;
        }
        Node *temp = head;
        int counter = 0;

        while (temp != nullptr && counter < index - 1)
        {
            temp = temp->Next;
            counter++;
        }

        if (temp == nullptr)
        {
            insertAtEnd(value);
            return;
        }

        Node *new_node = new Node(value);
        new_node->Next = temp->Next;
        if (temp->Next != nullptr)
        {
            temp->Next->Previous = new_node;
        }
        else
        {
            tail = new_node;
        }
        temp->Next = new_node;
        new_node->Previous = temp;
    }

    void removeFromStart()
    {
        if (!head)
        {
            cout << "Doubly linked list is empty." << endl;
            return;
        }
        Node *temp = head;
        head = head->Next;
        if (head)
        {
            head->Previous = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }

    void removeFromEnd()
    {
        if (!tail)
        {
            cout << "Doubly linked list is empty." << endl;
            return;
        }
        Node *temp = tail;
        tail = tail->Previous;
        if (tail)
        {
            tail->Next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || !head)
        {
            cout << "Invalid index or list is empty." << endl;
            return;
        }
        if (index == 0)
        {
            removeFromStart();
            return;
        }

        Node *temp = head;
        int counter = 0;

        while (temp != nullptr && counter < index)
        {
            temp = temp->Next;
            counter++;
        }

        if (temp == nullptr)
        {
            cout << "Index out of bounds." << endl;
            return;
        }

        if (temp->Next != nullptr)
        {
            temp->Next->Previous = temp->Previous;
        }
        else
        {
            tail = temp->Previous;
        }
        if (temp->Previous != nullptr)
        {
            temp->Previous->Next = temp->Next;
        }
        delete temp;
    }

    void displayFromHead()
    {
        if (!head)
        {
            cout << "The list is empty. Nothing to display." << endl;
            return;
        }
        cout << "List from head to tail: ";
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->Next;
        }
        cout << endl;
    }

    void displayFromTail()
    {
        if (!tail)
        {
            cout << "The list is empty. Nothing to display." << endl;
            return;
        }
        cout << "List from tail to head: ";
        Node *temp = tail;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->Previous;
        }
        cout << endl;
    }

    void Erase()
    {
        Node *current = head;
        while (current)
        {
            Node *nextNode = current->Next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    void reverse()
    {
        Node *current = head;
        Node *temp = nullptr;

        while (current)
        {
            temp = current->Previous;
            current->Previous = current->Next;
            current->Next = temp;
            current = current->Previous;
        }

        if (temp)
        {
            temp = temp->Previous;
            head = temp;
            if (head)
            {
                tail = head;
                while (tail->Next)
                {
                    tail = tail->Next;
                }
            }
        }
    }

    bool isPalindrome()
    {
        if (!head)
        {
            return false;
        }

        Node *front = head;
        Node *back = tail;

        while (front != back && front->Previous != back)
        {
            if (front->value != back->value)
            {
                return false;
            }
            front = front->Next;
            back = back->Previous;
        }

        return true;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    cout << "Starting the doubly linked list operations..." << endl;

    DoublyLinkedList DoubleLL;

    cout << "\nInserting values at the start of the list:" << endl;
    for (int i = 1; i < 5; i++)
    {
        cout << "Inserting " << i << " at the start." << endl;
        DoubleLL.insertAtStart(i);
        DoubleLL.displayFromHead();
    }

    cout << "\nInserting values at the end of the list:" << endl;
    for (int i = 5; i < 8; i++)
    {
        cout << "Inserting " << i << " at the end." << endl;
        DoubleLL.insertAtEnd(i);
        DoubleLL.displayFromHead();
    }

    cout << "\nInserting 432 at index 2." << endl;
    DoubleLL.insertAtIndex(432, 2);
    DoubleLL.displayFromHead();

    cout << "\nRemoving the first element from the list." << endl;
    DoubleLL.removeFromStart();
    DoubleLL.displayFromHead();

    cout << "\nRemoving the last element from the list." << endl;
    DoubleLL.removeFromEnd();
    DoubleLL.displayFromHead();

    cout << "\nRemoving the last element again." << endl;
    DoubleLL.removeFromEnd();
    DoubleLL.displayFromHead();

    cout << "\nDeleting the element at index 2." << endl;
    DoubleLL.deleteAtIndex(2);
    DoubleLL.displayFromHead();

    cout << "\nDeleting the element at index 3." << endl;
    DoubleLL.deleteAtIndex(3);
    DoubleLL.displayFromHead();

    cout << "\nDeleting the element at index 1." << endl;
    DoubleLL.deleteAtIndex(1);
    DoubleLL.displayFromHead();

    cout << "\nFinal operations to empty the list:" << endl;
    while (DoubleLL.head != nullptr)
    {
        DoubleLL.removeFromEnd();
        DoubleLL.displayFromHead();
    }

    cout << "\nDoubly linked list operations completed." << endl;

    return EXIT_SUCCESS;
}
