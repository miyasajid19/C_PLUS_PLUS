#include <iostream>
#include <cstdlib>
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
public:
    Node *head;
    LinkedLists() : head(nullptr) {}
    void add(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
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
    void display() const
    {
        if (!head)
        {
            cout << "there is nothing to display" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "NULL" << endl;
    }
};

Node *merge(Node *head1, Node *head2)
{
    Node dummy(-1);
    Node *tail = &dummy;

    while (head1 && head2)
    {
        if (head1->value < head2->value)
        {
            tail->Next = head1;
            head1 = head1->Next;
        }
        else
        {
            tail->Next = head2;
            head2 = head2->Next;
        }
        tail = tail->Next;
    }
    // Attach the remaining nodes
    if (head1)
    {
        tail->Next = head1;
    }
    else
    {
        tail->Next = head2;
    }
    
    return dummy.Next;
}

Node* findMiddleNode(Node* head)
{
    if (!head)
    {
        return nullptr;
    }
    Node* slowpointer=head;
    Node* fastpointer=head;
    while(fastpointer and fastpointer->Next)
    {
        fastpointer=fastpointer->Next->Next;
        slowpointer=slowpointer->Next;
    }
    return slowpointer;
}
int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LinkedLists list1,list2;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    list1.add(5);
    list1.display();
    Node* middlenode=findMiddleNode(list1.head);
    cout<<"middle node is "<<middlenode->value<<endl;
        list2.add(407);
    list2.add(432);
    list2.add(433);
    list2.add(434);
    LinkedLists ans;
    ans.head=findMiddleNode(list2.head);
    list2.display();
    cout<<"middle element is "<<ans.head->value;
    return EXIT_SUCCESS;
}
