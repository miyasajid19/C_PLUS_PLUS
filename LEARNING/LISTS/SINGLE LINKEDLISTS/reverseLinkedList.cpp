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
    void add(int value)
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
    void display()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "NULL" << endl;
    }
};
Node* reverse(Node* &head)
{
Node* previuousPtr=NULL;
Node* currentPointer=head;
while (currentPointer)
{
    Node* nextPointer=currentPointer->Next;
    currentPointer->Next=previuousPtr;
    previuousPtr=currentPointer;
    currentPointer=nextPointer;
    
}
Node* new_head=previuousPtr;
return new_head;

}
int main()
{
#ifndef JUDGE_ONLINE
        freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LinkedList lists;
    int n,size;
    cout<<"How many data do you have?";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        lists.add(n);
        lists.display();
    }
    lists.head=reverse(lists.head);
    lists.display();
    return 0;
}