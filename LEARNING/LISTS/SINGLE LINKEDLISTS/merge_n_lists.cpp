#include <iostream>
#include <cstdlib>
#include <vector>
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

Node *mergedNLinkedLists(vector<Node *> &lists)
{
    if (lists.empty())
    {
        return nullptr;
    }

    while (lists.size() > 1)
    {
        Node *mergedLists = merge(lists[0], lists[1]);
        lists.push_back(mergedLists);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    
    return lists[0];
}

int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cout << "Enter how many linked lists do you have?" << endl;
    int size, n, num;

    // Read the size first
    cin >> size;

    // Create an array of LinkedLists
    LinkedLists *lists = new LinkedLists[size];

    // Read elements for each LinkedList
    for (int i = 0; i < size; ++i)
    {
        cout << "How many elements do you have in linked list " << i + 1 << "?" << endl;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cout << "Enter element " << j + 1 << endl;
            cin >> num;
            lists[i].add(num);
        }
    }

    // Create a vector to hold the heads of the linked lists
    vector<Node*> lists_vector;
    for (int i = 0; i < size; ++i)
    {
        lists_vector.push_back(lists[i].head);
    }

    // Display each linked list before merging
    cout << "Linked lists before merging:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "Linked list " << i + 1 << ": ";
        lists[i].display();
    }

    // Merge the linked lists
    LinkedLists mergedlist;
    mergedlist.head = mergedNLinkedLists(lists_vector);

    // Display the merged linked list
    cout << "Merged linked list: ";
    mergedlist.display();

    // Clean up dynamically allocated memory
    delete[] lists;

    return EXIT_SUCCESS;
}
