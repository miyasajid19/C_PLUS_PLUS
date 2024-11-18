#include <iostream>
#include <queue>
#include <vector>
#include <climits>

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
            return;
        }

        Node *newNode = new Node(value);
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node *getHead()
    {
        return head;
    }

    void print()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

class Solution
{
public:
    struct HeapNode
    {
        int value;
        int listIndex;
        Node *node;
        HeapNode(int value, int listIndex, Node *node) : value(value), listIndex(listIndex), node(node) {}

        // Comparator for priority queue (min-heap)
        bool operator>(const HeapNode &other) const
        {
            return value > other.value;
        }
    };

    pair<int, int> findSmallestRange(vector<LinkedList> &lists)
    {
        // Min-heap to store the current elements from each list
        priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> minHeap;

        int currentMax = INT_MIN;
        
        // Initialize the heap with the first element of each list
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i].getHead() != nullptr)
            {
                minHeap.push(HeapNode(lists[i].getHead()->value, i, lists[i].getHead()));
                currentMax = max(currentMax, lists[i].getHead()->value);
            }
        }

        int rangeStart = -1;
        int rangeEnd = -1;
        int smallestRange = INT_MAX;

        // Process the heap until we exhaust one of the lists
        while (true)
        {
            // Get the smallest element (top of the min-heap)
            HeapNode minNode = minHeap.top();
            minHeap.pop();

            // Update the range if the current range is smaller
            if (currentMax - minNode.value < smallestRange)
            {
                smallestRange = currentMax - minNode.value;
                rangeStart = minNode.value;
                rangeEnd = currentMax;
            }

            // Move to the next node in the list of the popped element
            if (minNode.node->next != nullptr)
            {
                // Move the pointer to the next node in the same list
                minNode.node = minNode.node->next;
                // Push the new node to the heap
                minHeap.push(HeapNode(minNode.node->value, minNode.listIndex, minNode.node));
                // Update the current max value
                currentMax = max(currentMax, minNode.node->value);
            }
            else
            {
                // If we reach the end of any list, we can't proceed further
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};

int main()
{
    LinkedList l1, l2, l3;
    l1.add(4);
    l1.add(10);
    l1.add(15);
    l1.print();
    l2.add(1);
    l2.add(5);
    l2.add(20);
    l2.print();
    l3.add(7);
    l3.add(12);
    l3.add(18);
    l3.print();
    vector<LinkedList> lists = {l1, l2, l3};

    Solution solution;
    pair<int, int> result = solution.findSmallestRange(lists);
    cout << "Smallest Range: [" << result.first << ", " << result.second << "]" << endl;

    return 0;
}
