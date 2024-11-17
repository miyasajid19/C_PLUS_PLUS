#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList
{

public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    void add(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
            return; // Stop further execution if head is set
        }

        Node *newNode = new Node(value);
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value;
            if (temp->next != nullptr)
                cout << "->";
            temp = temp->next;
        }
        cout << "->nullptr" << endl;
    }
};
class Solution
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->value > b->value;
    }
    LinkedList merge(vector<Node *> arr)
    {
        priority_queue<Node *, vector<Node *>, Solution> minHeap;
        int size = arr.size();
        if (size == 0)
            return LinkedList();
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != nullptr)
                minHeap.push(arr[i]);
        }
        Node *head = nullptr;
        Node *tail = nullptr;
        while (not minHeap.empty())
        {
            Node *temp = minHeap.top();
            minHeap.pop();
            if (temp->next != nullptr)
            {
                minHeap.push(temp->next);
            }
            if (head == nullptr)
            {
                head = tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }
            minHeap.pop();
        }
        LinkedList ll;
        ll.head = head;
        return ll;
    }
};
int main()
{
    LinkedList ll1;
    ll1.add(1);
    ll1.add(4);
    ll1.add(7);
    ll1.print();

    LinkedList ll2;
    ll2.add(2);
    ll2.add(5);
    ll2.add(8);
    ll2.print();

    LinkedList ll3;
    ll3.add(3);
    ll3.add(6);
    ll3.add(9);
    ll3.print();

    vector<Node *> lists = {ll1.head, ll2.head, ll3.head};
    Solution solution;
    LinkedList merged = solution.merge(lists);

    merged.print(); // Should print the merged sorted linked list
    return EXIT_SUCCESS;
}