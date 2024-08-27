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
class CircularLinkedLists
{
private:
    Node *head;

public:
    CircularLinkedLists() : head(nullptr) {}
    ~CircularLinkedLists()
    {
        delete head;
    }
    void Push_Back(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            new_node->Next = head;
            return;
        }
        Node *temp = head;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        new_node->Next = head;
        head = new_node;
        temp->Next = head;
    }
    void Push_Front(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = new_node;
            new_node->Next = head;
            return;
        }
        Node *temp = head;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
        new_node->Next = head;
    }
    void Insert(int value, int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (index == 0)
        {
            Push_Front(value);
            return;
        }
        Node *temp = head;
        int counter = 0;
        while (counter < index - 1 and temp->Next != head)
        {
            counter++;
            temp = temp->Next;
        }
        if (counter < index - 1)
        {
            cout << "index out of bound do inserting at tail" << endl;
            Push_Back(value);
            return;
        }
        Node *new_node = new Node(value);
        new_node->Next = temp->Next;
        temp->Next = new_node;
    }
    void Pop_Back()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->Next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->Next->Next != head)
        {
            temp = temp->Next;
        }
        Node *deletingNode = temp->Next;
        temp->Next = temp->Next->Next;
        delete deletingNode;
    }
    void Pop_Front()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->Next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        Node *deletingNode = head;
        head = head->Next;
        temp->Next = head;
        delete deletingNode;
    }
    void Remove(int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (index == 0)
        {
            Pop_Front();
            return;
        }
        Node *temp = head;
        int current = 0;
        while (current < index - 1 and temp->Next != head)
        {
            temp = temp->Next;
            current++;
        }
        if (temp->Next == head)
        {
            Pop_Back();
            return;
        }
        if (current == index - 1)
        {
            Node *deletingNode = temp->Next;
            temp->Next = temp->Next->Next;
            delete deletingNode;
        }
    }
    void Display()
    {
        if (head == nullptr)
        {
            cout << "the linked list is either empty or not erased" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->value << "-->";
            temp = temp->Next;
        } while (temp != head);
        cout << "loop begins\n";
    }
};
int main()
{
    CircularLinkedLists list;
    list.Push_Back(1);
    list.Display();
    list.Push_Back(2);
    list.Display();
    list.Push_Back(3);
    list.Display();
    list.Push_Front(3);
    list.Display();
    list.Insert(432, 2);
    list.Display();
    list.Pop_Back();
    list.Display();
    list.Pop_Back();
    list.Display();
    list.Pop_Front();
    list.Display();
    list.Push_Back(22);
    list.Display();
    list.Remove(1);
    list.Display();
    for (int i = 0; i < 5; i++)
    {
        list.Insert(13 + i, 1);
    }
    for (int i = 0; i < 7; i++)
    {
        list.Remove(1);
        list.Display();
    }
    return EXIT_SUCCESS;
}