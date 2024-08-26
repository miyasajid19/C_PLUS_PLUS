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
    ~Node() {}
};
class LinkedLists
{
public:
    Node *head = nullptr;
    void Push(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
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
    void insertAtHead(int value)
    {
        Node *new_node = new Node(value);
        if (not head)
        {
            head = new_node;
            return;
        }
        new_node->Next = head;
        head = new_node;
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
        int current = 0;
        while (temp and current != index)
        {
            temp = temp->Next;
            current++;
        }
        if (temp == nullptr)
        {
            cout << "index out of bound" << endl;
            delete new_node;
            return;
        }
        new_node->Next = temp->Next;
        temp->Next = new_node;
    }
    void display()
    {
        if (not head)
        {
            cout << "the linked list is either empty or not creatd yet" << endl;
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
    void Update(int value, int index)
    {
        if (not head)
        {
            cout << "the  linked list is either empty or not created yet" << endl;
            return;
        }
        int current = 0;
        Node *temp = head;
        while (temp and current < index)
        {
            temp = temp->Next;
            current++;
        }
        if (temp)
        {

            temp->value = value;
            cout << "updated" << endl;
        }
        else
        {
            cout << "index out of bound" << endl;
        }
    }
    void Pop()
    {
        if (!head)
        {
            cout << "The linked list is empty" << endl;
            return;
        }

        if (!head->Next) // If there's only one node
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *secondLast = head;
        while (secondLast->Next->Next)
        {
            secondLast = secondLast->Next;
        }

        Node *last = secondLast->Next; // The last node
        secondLast->Next = nullptr;
        delete last;
    }
    void deleteAtHead()
    {
        if (not head)
        {
            return;
        }
        Node *temp = head;
        head = head->Next;
        delete temp;
    }
    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            deleteAtHead();
            return;
        }

        Node *temp = head;
        int current = 0;

        while (temp && current < index - 1)
        {
            current++;
            temp = temp->Next;
        }

        if (!temp || !temp->Next)
        {
            cout << "Index out of bounds" << endl;
            return;
        }

        Node *nodeToDelete = temp->Next;
        temp->Next = temp->Next->Next;
        delete nodeToDelete;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cout << "all i want was the love and what i get is the pain" << endl;
    LinkedLists list;
    list.insert(1, 0);
    list.display();
    list.insert(1, 0);
    list.display();
    list.insert(432, 0);
    list.display();
    list.Push(432);
    list.display();
    list.Update(407, 5);
    list.display();
    list.insert(407, 1);
    list.display();
    list.Pop();
    list.display();
    list.Pop();
    list.display();
    list.deleteAtHead();
    list.display();
    list.deleteAtHead();
    list.display();
    list.deleteAtHead();
    list.display();
    list.Push(1);
    list.Push(2);
    list.Push(3);
    list.display();
    list.deleteAtIndex(1);
    list.display();
    return EXIT_SUCCESS;
}