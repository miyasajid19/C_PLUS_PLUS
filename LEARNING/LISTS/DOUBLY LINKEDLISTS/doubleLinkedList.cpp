#include <iostream>
#include <cstdlib>
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
class DoublyLinkedLists
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedLists()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void insertAtStart(int value)
    {
        Node *new_node = new Node(value);
        if (not head)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->Next = head;
        head->Previous = new_node;
        head = new_node;
    }
    void display()
    {
        if (not head)
        {
            cout << "there is nothing to display";
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
        if (not tail)
        {
            cout << "there is nothing to display";
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
};
int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("../..input.txt", "r", stdin);
//    freopen("../../output.txt", "w", stdout);
//#endif
    cout << "all i want was the love and what i get is the pain" << endl;
    cout << "the moment had passed and we remained like straingers among the sea of graduates" << endl;
    DoublyLinkedLists DoubleLL;
    for (int i = 407; i < 432; i++)
    {
        DoubleLL.insertAtStart(i);
        DoubleLL.display();
        DoubleLL.displayFromTail();
    }
    return EXIT_SUCCESS;
}