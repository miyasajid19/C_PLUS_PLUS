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
            cout << "There is nothing to display." << endl;
            return;
        }
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
            cout << "There is nothing to display." << endl;
            return;
        }
        Node *temp = tail;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->Previous;
        }
        cout << endl;
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
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    DoublyLinkedList DoubleLL;

    cout << "Inserting elements at the end of the list:" << endl;
    for (int i = 0; i < 5; i++)
    {
        DoubleLL.insertAtEnd(i);
        cout << "Inserted " << i << " at the end of the list." << endl;
    }

    cout << "\nDisplaying the list from head to tail:" << endl;
    DoubleLL.displayFromHead();

    cout << "\nReversing the list:" << endl;
    DoubleLL.reverse();

    cout << "Displaying the list after reversal from head to tail:" << endl;
    DoubleLL.displayFromHead();

    cout << "\nErasing the entire list:" << endl;
    DoubleLL.Erase();

    cout << "List has been erased." << endl;

    return EXIT_SUCCESS;
}
