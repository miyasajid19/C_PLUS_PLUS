#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    string name;
    Node* Next;
    Node(string name)
    {
        this->name=name;
        this->Next=NULL;
    }
    
};
class LinkedLists{
    public:
    Node* head;
    LinkedLists() {
        head = NULL; // Initialize head to NULL
    }

    void add(string value)
    {
        Node* new_node=new Node(value);
        if (head==NULL)
        {
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=new_node;
    }
    void display()
    {
        if (head==NULL)
        {
            return;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->name<<"->";
            temp=temp->Next;
        }
        cout<<"NULL"<<endl;
    }
};
    void reversePrint(Node* head)
    {
        if (head==NULL)
        {
            cout<<"NULL";
            return;
        }
        reversePrint(head->Next);
        cout<<"<-"<<head->name;
    }
int main()
{
    #ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LinkedLists lists;
    string name;
    for (int i=0;i<3;i++)
    {
        cin>>name;
        lists.add(name);
        lists.display();
    }
        reversePrint(lists.head);
    return 0;
}