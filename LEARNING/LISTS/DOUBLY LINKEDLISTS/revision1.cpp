#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node *Previous;
    Node(int value) : Next(nullptr), Previous(nullptr), value(value) {}
};
class DoublyLinkedLists
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedLists() : head(nullptr), tail(nullptr) {}
    void Push_Back(int value)
    {
        Node *new_node = new Node(value);
        if (tail == nullptr)
        {
            tail = new_node;
            head = new_node;
            return;
        }
        new_node->Previous = tail;
        tail->Next = new_node;
        tail = new_node;
    }
    void Push_Front(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->Next = head;
        head->Previous = new_node;
        head = new_node;
    }
    void Insert(int value, int index)
    {
        if (index == 0)
        {
            Push_Front(value);
            return;
        }
        Node *frontPointer = head;
        int current = 0;
        while (current < index - 1 and frontPointer != nullptr)
        {
            frontPointer = frontPointer->Next;
            current++;
        }
        if (frontPointer == nullptr)
        {
            Push_Back(value);
            return;
        }
        Node *new_node = new Node(value);
        new_node->Next = frontPointer->Next;
        if (frontPointer->Next != nullptr)
        {
            frontPointer->Next->Previous = new_node;
        }
        else
        {
            tail = new_node;
        }
        frontPointer->Next = new_node;
        new_node->Previous = frontPointer;
    }
    void Update(int value, int index)
    {
        if (head == nullptr)
        {
            return;
        }
        if (index < 0)
        {
            cout << "Invalid indexing " << endl;
            return;
        }
        int current = 0;
        Node *currentPointer = head;
        while (current < index - 1 and currentPointer != nullptr)
        {
            currentPointer = currentPointer->Next;
            current++;
        }
        if (currentPointer == nullptr)
        {
            cout << "Index out of bound" << endl;
            return;
        }
        currentPointer->value = value;
    }
    void Pop_Front()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
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
    void Pop_Back()
    {
        if (tail == nullptr)
        {
            cout << "linked list is either empty or erased";
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
    }
    void Remove(int index)
    {
        if (index < 0 || !head)
        {
            cout << "Invalid index or list is empty." << endl;
            return;
        }
        if (index == 0)
        {
            Pop_Front();
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
    void erase()
    {
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    void displayFront()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << "-->";
            temp = temp->Next;
        }
        cout << nullptr << endl;
    }
    void displayBack()
    {
        if (tail == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = tail;
        while (temp)
        {
            cout << temp->value << "-->";
            temp = temp->Previous;
        }
        cout << nullptr << endl;
    }
};
int main()
{
    DoublyLinkedLists list;
    list.Push_Back(4);
    list.displayFront();
    list.displayBack();
    list.Push_Back(5);
    list.displayFront();
    list.displayBack();
    list.Push_Back(6);
    list.displayFront();
    list.displayBack();
    list.Push_Front(2);
    list.displayFront();
    list.displayBack();
    list.Push_Front(1);
    list.displayFront();
    list.displayBack();
    list.Insert(13, 2);
    list.displayFront();
    list.displayBack();
    list.Update(3, 3);
    list.displayFront();
    list.displayBack();
    list.Insert(13, 2);
    list.displayFront();
    list.displayBack();
    list.Remove(2);
    list.displayFront();
    list.displayBack();
    for (int i = 0; i < 3; i++)
    {
        list.Pop_Front();
        list.displayFront();
        list.displayBack();
        list.Pop_Back();
        list.displayFront();
        list.displayBack();
    }
    list.Push_Back(4);
    list.displayFront();
    list.displayBack();
    list.Push_Back(5);
    list.displayFront();
    list.displayBack();
    list.Push_Back(6);
    list.displayFront();
    list.erase();
    list.displayBack();
    return EXIT_SUCCESS;
}