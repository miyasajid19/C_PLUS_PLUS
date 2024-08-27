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
class LinkedLists
{
private:
    Node *head;

public:
    LinkedLists() : head(nullptr) {}
    ~LinkedLists()
    {
        delete head;
    }
    void Push_Back(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }
    void Push_Front(int value)
    {
        Node *new_node = new Node(value);
        new_node->Next = head;
        head = new_node;
    }
    void Insert(int value, int index)
    {
        if (index < 0)
        {
            cout << "index out of bound" << endl;
            return;
        }
        if (index == 0)
        {
            Push_Front(value);
            return;
        }
        Node *temp = head;
        int currentIndex = 0;
        while (currentIndex < index - 1 and temp->Next != nullptr)
        {
            temp = temp->Next;
            currentIndex++;
        }
        if (currentIndex == index - 1)
        {
            Node *new_node = new Node(value);
            new_node->Next = temp->Next;
            temp->Next = new_node;
        }
        else
        {
            cout << "index out of bound" << endl;
        }
    }
    void Update(int value, int index)
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        int current = 0;
        while (current < index and temp != nullptr)
        {
            temp = temp->Next;
            current++;
        }
        if (temp == nullptr)
        {
            cout << "index out of bound" << endl;
            return;
        }
        temp->value = value;
    }
    void Pop_Front()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *temp = head;
        head = head->Next;
        delete temp;
    }
    void Pop_Back()
    {
        if (head == nullptr or head->Next == nullptr)
        {
            Pop_Front();
            return;
        }
        Node *secondlastNode = head;
        while (secondlastNode->Next->Next != nullptr)
        {
            secondlastNode = secondlastNode->Next;
        }
        Node *lastNode = secondlastNode->Next;
        secondlastNode->Next = nullptr;
        delete lastNode;
    }
    void Delete(int index)
    {
        if (head == nullptr)
        {
            return;
        }
        if (index == 0)
        {
            Pop_Front();
            return;
        }
        Node *indexer = head;
        int current = 0;
        while (indexer != nullptr and current < index - 1)
        {
            current++;
            indexer = indexer->Next;
        }
        if (indexer == nullptr)
        {
            return;
        }
        if (indexer->Next == nullptr)
        {
            Pop_Back();
        }
        Node *ThatNode = indexer->Next;
        indexer->Next = indexer->Next->Next;
        delete ThatNode;
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }
};
int main()
{
    LinkedLists ll;
    ll.Push_Back(1);
    ll.Push_Back(2);
    ll.Push_Back(3);
    ll.Push_Back(4);
    ll.display();
    ll.Push_Front(0);
    ll.display();
    ll.Insert(434, 3);
    ll.display();
    ll.Insert(420, 0);
    ll.display();
    ll.Insert(433, 233);
    ll.display();
    ll.Insert(432, 2);
    ll.display();
    ll.Update(407, 1);
    ll.display();
    ll.Update(13, 4);
    ll.display();
    ll.Pop_Front();
    ll.display();
    ll.Pop_Front();
    ll.display();
    ll.Pop_Front();
    ll.display();
    ll.Pop_Back();
    ll.display();
    ll.Pop_Back();
    ll.display();
    ll.Delete(1);
    ll.display();
    ll.Delete(1);
    ll.display();
    ll.Delete(0);
    ll.display();
    return EXIT_SUCCESS;
}