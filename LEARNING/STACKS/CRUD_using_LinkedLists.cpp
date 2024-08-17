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

class Stacks
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
    Stacks(int capacity) : head(nullptr), size(0), capacity(capacity) {}

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
            cout << "linked stack is empty !!! ::: there is nothing to delete" << endl;
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
    void copystack(const Stacks &other)
    {
        // Clear current stack
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

    Stacks Copy() const
    {
        Stacks copiedstack(capacity);
        Node *current = head;
        Node *previous = nullptr;

        while (current)
        {
            Node *newNode = new Node(current->value);
            if (!copiedstack.head)
            {
                copiedstack.head = newNode;
            }
            else
            {
                previous->Next = newNode;
            }
            previous = newNode;
            current = current->Next;
        }
        copiedstack.size = size;
        return copiedstack;
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

    // Create a linked stack with a capacity of 5
    Stacks stack(5);

    // Display the initial state of the stack (should be empty)
    cout << "Initial stack state (should be empty):" << endl;
    stack.display();

    // Push elements to the stack
    cout << "\nPushing elements 1, 2, and 3 to the stack:" << endl;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.display();

    // Show the top element after pushes
    cout << "Top element after pushes: " << stack.getTop() << endl;

    // Pop the top element
    cout << "\nPopping the top element:" << endl;
    stack.Pop();
    stack.display();

    // Copy the stack to another stack
    cout << "\nCopying the current stack to another stack:" << endl;
    Stacks copiedstack(stack.Size());
    copiedstack.copystack(stack);
    copiedstack.display();

    // Reverse the copied stack
    cout << "\nReversing the copied stack:" << endl;
    copiedstack.ReverseByRecursion();
    copiedstack.display();

    // Erase the contents of the original stack
    cout << "\nErasing the original stack:" << endl;
    stack.erase();
    stack.display();

    // Display the size of the stacks
    cout << "\nSize of the original stack after erasing: " << stack.Size() << endl;
    cout << "Size of the copied stack: " << copiedstack.Size() << endl;

    return EXIT_SUCCESS;
}
