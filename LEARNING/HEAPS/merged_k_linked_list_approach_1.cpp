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
    LinkedList merge(vector<Node *> arr)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (Node *temp : arr)
        {
            if (temp == nullptr)
                continue;
            while (temp != nullptr)
            {
                minHeap.push(temp->value);
                temp = temp->next;
            }
        }
        Node *temp = arr[0];
        Node *lastNode = arr[0];
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp1 = arr[i];
            lastNode->next = temp1;//joining the last node to the next linked list
            while (lastNode->next != nullptr)
                lastNode = lastNode->next;//making the last node to move to new last node
        }
        lastNode->next = nullptr;
        Node *temp2 = temp;
        while (temp2 != nullptr)
        {
            temp2->value = minHeap.top();
            temp2 = temp2->next;
            minHeap.pop();
        }
        LinkedList ll;

        ll.head = temp;
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