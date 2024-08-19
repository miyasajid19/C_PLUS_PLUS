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


bool CheckCycle(Node* head)
{
    if(!head)
    {
        cout<<"this is the empty list"<<endl;
        return false;
    }
    Node* pointer1=head;
    Node* pointer2=head;
    while(pointer2 and pointer2->Next)
    {
        pointer1=pointer1->Next;
        pointer2=pointer2->Next->Next;
        if(pointer1==pointer2)
        {
            cout<<"cyclic at "<<pointer1->value<<endl;
            return true;
        }
    }
    return false;
}
void removeCycle(Node* &head)
{
    Node* pointer1=head;
    Node* pointer2=head;
    do {
        pointer1=pointer1->Next;
        pointer2=pointer2->Next->Next;
    }while (pointer1!=pointer2);
    
    pointer2=head;
    while(pointer1->Next != pointer2->Next)
    {
        pointer1=pointer1->Next;
        pointer2=pointer2->Next;
    }
    pointer1->Next=nullptr;
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
    list1.add(6);
    list1.add(7);
    list1.head->Next->Next->Next->Next->Next->Next->Next=list1.head->Next->Next;
    // list1.display();
    cout<<boolalpha;
    cout<<CheckCycle(list1.head)<<endl;
    removeCycle(list1.head);
    list1.display();
    cout<<CheckCycle(list1.head)<<endl;

    return EXIT_SUCCESS;
}

//----------------------------------------------CHATGPT CODE-------------------------------------------------------
/*
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
            cout << "There is nothing to display" << endl;
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

bool CheckCycle(Node* head)
{
    if (!head)
    {
        cout << "This is the empty list" << endl;
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->Next)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        if (slow == fast)
        {
            cout << "Cyclic at " << slow->value << endl;
            return true;
        }
    }
    return false;
}

void removeCycle(Node* &head)
{
    if (!head)
    {
        return;
    }

    Node* slow = head;
    Node* fast = head;
    bool hasCycle = false;

    while (fast && fast->Next)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        if (slow == fast)
        {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->Next;
            fast = fast->Next;
        }
        
        // Find the node just before the start of the cycle
        Node* cycleStart = slow;
        while (fast->Next != cycleStart)
        {
            fast = fast->Next;
        }
        fast->Next = nullptr;
    }
}

int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);        
    freopen("../output.txt", "w", stdout);
#endif
    LinkedLists list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    list1.add(5);
    list1.add(6);
    list1.add(7);
    list1.head->Next->Next->Next->Next->Next->Next->Next = list1.head->Next->Next;
    
    cout << boolalpha;
    cout << "Cycle present: " << CheckCycle(list1.head) << endl;
    removeCycle(list1.head);
    list1.display();
    cout << "Cycle present after removal: " << CheckCycle(list1.head) << endl;

    return EXIT_SUCCESS;
}

*/ 