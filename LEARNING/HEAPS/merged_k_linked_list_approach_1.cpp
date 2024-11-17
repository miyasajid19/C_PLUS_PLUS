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

    Node *getHead()
    {
        return head;
    }
};

class Solution
{
public:
    LinkedList merge(vector<Node *> arr)
    {
        // Min-heap to get the smallest element at the top
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 1: Put all values in the min-heap
        for (Node *temp : arr)
        {
            while (temp != nullptr)
            {
                minHeap.push(temp->value);
                temp = temp->next;
            }
        }

        // Step 2: Build the merged linked list
        LinkedList mergedList;
        Node *newHead = nullptr;
        Node *current = nullptr;

        // Extract the smallest element and add to the new linked list
        while (!minHeap.empty())
        {
            int value = minHeap.top();
            minHeap.pop();

            Node *newNode = new Node(value);
            if (newHead == nullptr)
            {
                newHead = newNode;
                current = newHead; // Initialize the head and current pointer
            }
            else
            {
                current->next = newNode; // Link the new node to the current node
                current = current->next; // Move current to the new node
            }
        }

        // Set the merged list's head
        mergedList = LinkedList();
        mergedList.head = newHead;

        return mergedList;
    }
};

int main()
{
    LinkedList ll1;
    ll1.add(1);
    ll1.add(4);
    ll1.add(7);

    LinkedList ll2;
    ll2.add(2);
    ll2.add(5);
    ll2.add(8);

    LinkedList ll3;
    ll3.add(3);
    ll3.add(6);
    ll3.add(9);

    vector<Node *> lists = {ll1.getHead(), ll2.getHead(), ll3.getHead()};
    Solution solution;
    LinkedList merged = solution.merge(lists);

    merged.print(); // Should print the merged sorted linked list

    return EXIT_SUCCESS;
}
