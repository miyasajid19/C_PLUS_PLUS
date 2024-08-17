#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int value) : value(value), Next(nullptr) {}
};

class LinkedLists
{
    Node *head;
    int size;
    int capacity;

    void deleteFrom(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "index out of bound" << endl;
            return;
        }
        if (index == 0)
        {
            deleteFromTail();
            return;
        }
        Node *previous = head;
        for (int counter = 0; counter < index - 1 && previous; ++counter)
        {
            previous = previous->Next;
        }
        if (!previous || !previous->Next)
        {
            cout << "index out of bound ::: can't delete" << endl;
            return;
        }
        size--;
        Node *temp = previous->Next;
        previous->Next = previous->Next->Next;
        delete temp;
    }

    void insertAtTail(int value)
    {
        size++;
        Node *new_node = new Node(value);
        if (isEmpty())
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }

    void insert(int value, int index)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        if (index < 0 || index > size)
        {
            cout << "index out of bound ::: can't make insertion" << endl;
            return;
        }
        size++;
        if (index == 0)
        {
            Push(value);
            return;
        }
        Node *new_node = new Node(value);
        Node *temp = head;
        for (int counter = 0; counter < index - 1 && temp; ++counter)
        {
            temp = temp->Next;
        }
        if (!temp)
        {
            cout << "index out of bound ::: can't make insertion" << endl;
            delete new_node;
            return;
        }
        new_node->Next = temp->Next;
        temp->Next = new_node;
    }

    void deleteFromTail()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        if (head->Next == nullptr)
        {
            Pop();
            return;
        }
        size--;
        Node *secondlast = head;
        while (secondlast->Next->Next)
        {
            secondlast = secondlast->Next;
        }
        Node *temp = secondlast->Next;
        secondlast->Next = nullptr;
        delete temp;
    }

public:
    LinkedLists(int capacity) : head(nullptr), size(0), capacity(capacity) {}

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == capacity;
    }

    void Push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        size++;
        Node *new_node = new Node(value);
        new_node->Next = head;
        head = new_node;
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            cout << "linked list is empty !!! ::: there is nothing to delete" << endl;
            return;
        }
        size--;
        Node *temp = head;
        head = head->Next;
        delete temp;
    }

    int getTop() const
    {
        if (isEmpty())
        {
            cout << "there is nothing to show" << endl;
            return INT_MIN;
        }
        return head->value;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "there is nothing to show" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }
    int Size()
    {
        if (not head)
        {
            return 0;
        }
        int counter = 0;
        Node *temp = head;
        while (temp)
        {
            counter++;
            temp = temp->Next;
        }
        return counter;
    }
    void copyList(const LinkedLists &other)
    {
        // Clear current list
        while (!isEmpty())
        {
            Pop();
        }

        Node *current = other.head;
        Node *previous = nullptr;
        while (current)
        {
            Node *newNode = new Node(current->value);
            if (!head)
            {
                head = newNode;
            }
            else
            {
                previous->Next = newNode;
            }
            previous = newNode;
            current = current->Next;
        }
        size = other.size;
        capacity = other.capacity;
    }

    LinkedLists Copy() const
    {
        LinkedLists copiedList(capacity);
        Node *current = head;
        Node *previous = nullptr;

        while (current)
        {
            Node *newNode = new Node(current->value);
            if (!copiedList.head)
            {
                copiedList.head = newNode;
            }
            else
            {
                previous->Next = newNode;
            }
            previous = newNode;
            current = current->Next;
        }
        copiedList.size = size;
        return copiedList;
    }
    void erase()
    {
        size = 0;
    }
    void reverse()
    {
        if (isEmpty())
        {
            cout << "stack is empty hence can't be reversed" << endl;
            return;
        }

        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current)
        {
            next = current->Next; // Save the next node
            current->Next = prev; // Reverse the current node's pointer
            prev = current;       // Move prev and current one step forward
            current = next;
        }

        head = prev; // Update head to the new first element
    }
    void ReverseByRecursionHelper(Node *current)
    {
        if (current == nullptr || current->Next == nullptr)
        {
            head = current;
            return;
        }
        ReverseByRecursionHelper(current->Next);
        current->Next->Next = current;
        current->Next = nullptr;
    }

    void ReverseByRecursion()
    {
        ReverseByRecursionHelper(head);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("..input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // Create a linked list with a capacity of 5
    LinkedLists list(5);

    // Display the initial state of the list (should be empty)
    cout << "Initial list state (should be empty):" << endl;
    list.display();

    // Push elements to the list
    cout << "\nPushing elements 1, 2, and 3 to the list:" << endl;
    list.Push(1);
    list.Push(2);
    list.Push(3);
    list.display();

    // Show the top element after pushes
    cout << "Top element after pushes: " << list.getTop() << endl;

    // Pop the top element
    cout << "\nPopping the top element:" << endl;
    list.Pop();
    list.display();

    // Copy the list to another list
    cout << "\nCopying the current list to another list:" << endl;
    LinkedLists copiedList(list.Size());
    copiedList.copyList(list);
    copiedList.display();

    // Reverse the copied list
    cout << "\nReversing the copied list:" << endl;
    copiedList.ReverseByRecursion();
    copiedList.display();

    // Erase the contents of the original list
    cout << "\nErasing the original list:" << endl;
    list.erase();
    list.display();

    // Display the size of the lists
    cout << "\nSize of the original list after erasing: " << list.Size() << endl;
    cout << "Size of the copied list: " << copiedList.Size() << endl;

    return EXIT_SUCCESS;
}
