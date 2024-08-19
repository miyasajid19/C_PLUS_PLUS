#include <iostream>
#include <cstdlib>
#include <vector>
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

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~DoublyLinkedList()
    {
        Erase();
    }

    void insertAtStart(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->Next = head;
        head->Previous = new_node;
        head = new_node;
    }

    void insertAtEnd(int value)
    {
        Node *new_node = new Node(value);
        if (!tail)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->Next = new_node;
        new_node->Previous = tail;
        tail = new_node;
    }

    void insertAtIndex(int value, int index)
    {
        if (index < 0)
        {
            cout << "Invalid index." << endl;
            return;
        }
        if (index == 0)
        {
            insertAtStart(value);
            return;
        }
        Node *temp = head;
        int counter = 0;

        while (temp != nullptr && counter < index - 1)
        {
            temp = temp->Next;
            counter++;
        }

        if (temp == nullptr)
        {
            insertAtEnd(value);
            return;
        }

        Node *new_node = new Node(value);
        new_node->Next = temp->Next;
        if (temp->Next != nullptr)
        {
            temp->Next->Previous = new_node;
        }
        else
        {
            tail = new_node;
        }
        temp->Next = new_node;
        new_node->Previous = temp;
    }

    void removeFromStart()
    {
        if (!head)
        {
            cout << "Doubly linked list is empty." << endl;
            return;
        }
        Node *temp = head;
        head = head->Next;
        if (head)
        {
            head->Previous = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }

    void removeFromEnd()
    {
        if (!tail)
        {
            cout << "Doubly linked list is empty." << endl;
            return;
        }
        Node *temp = tail;
        tail = tail->Previous;
        if (tail)
        {
            tail->Next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || !head)
        {
            cout << "Invalid index or list is empty." << endl;
            return;
        }
        if (index == 0)
        {
            removeFromStart();
            return;
        }

        Node *temp = head;
        int counter = 0;

        while (temp != nullptr && counter < index)
        {
            temp = temp->Next;
            counter++;
        }

        if (temp == nullptr)
        {
            cout << "Index out of bounds." << endl;
            return;
        }

        if (temp->Next != nullptr)
        {
            temp->Next->Previous = temp->Previous;
        }
        else
        {
            tail = temp->Previous;
        }
        if (temp->Previous != nullptr)
        {
            temp->Previous->Next = temp->Next;
        }
        delete temp;
    }

    void displayFromHead()
    {
        if (!head)
        {
            cout << "There is nothing to display." << endl;
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
        if (!tail)
        {
            cout << "There is nothing to display." << endl;
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

    void Erase()
    {
        Node *current = head;
        while (current)
        {
            Node *nextNode = current->Next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
    bool isCriticalPoint(Node *&currentNode)
    {
        if (currentNode->Previous->value < currentNode->value and currentNode->Next->value < currentNode->value)
        {
            return true;
        }
        if (currentNode->Previous->value > currentNode->value and currentNode->Next->value > currentNode->value)
        {
            return true;
        }
        return false;
    }
    vector<int> distanceBetweenCriticalPoints()
    {
        vector<int> ans(2, INT_MAX);
        int firstCP = -1, lastCP = -1;
        Node *currentPointer = tail->Previous;
        if (not currentPointer)
        {
            ans[0] = ans[1] = -1;
            return ans;
        }
        int currentPosition = 0;
        while (currentPointer->Previous)
        {
            if (isCriticalPoint(currentPointer))
            {
                if (firstCP == -1)
                {
                    firstCP = lastCP = currentPosition;
                }
                else
                {
                    ans[0] = min(ans[0], currentPosition - lastCP);
                    ans[1] = currentPosition - firstCP;
                    lastCP = currentPosition;
                }
            }
            currentPosition++;
            currentPointer = currentPointer->Previous;
        }
        if (ans[0] == INT_MAX)
        {
            ans[0] = ans[1] = -1;
        }
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    DoublyLinkedList DoubleLL;

    cout << "Inserting values into the doubly linked list: 1, 5, 4, 2, 6, 3" << endl;
    DoubleLL.insertAtEnd(1);
    DoubleLL.insertAtEnd(5);
    DoubleLL.insertAtEnd(4);
    DoubleLL.insertAtEnd(2);
    DoubleLL.insertAtEnd(6);
    DoubleLL.insertAtEnd(3);

    cout << "Displaying the current list from head to tail:" << endl;
    DoubleLL.displayFromHead();

    cout << "Calculating the distances between critical points in the list:" << endl;
    vector<int> ans = DoubleLL.distanceBetweenCriticalPoints();
    if (ans[0] == -1)
    {
        cout << "No critical points found or not enough critical points to calculate distances." << endl;
    }
    else
    {
        cout << "Minimum distance between critical points: " << ans[0] << endl;
        cout << "Maximum distance between critical points: " << ans[1] << endl;
    }

    cout << "\nErasing the list to insert a new set of values." << endl;
    DoubleLL.Erase();

    cout << "Inserting values into the doubly linked list: 1, 2, 3, 4, 5" << endl;
    DoubleLL.insertAtEnd(1);
    DoubleLL.insertAtEnd(2);
    DoubleLL.insertAtEnd(3);
    DoubleLL.insertAtEnd(4);
    DoubleLL.insertAtEnd(5);

    cout << "Displaying the current list from head to tail:" << endl;
    DoubleLL.displayFromHead();

    cout << "Calculating the distances between critical points in the list:" << endl;
    ans = DoubleLL.distanceBetweenCriticalPoints();
    if (ans[0] == -1)
    {
        cout << "No critical points found or not enough critical points to calculate distances." << endl;
    }
    else
    {
        cout << "Minimum distance between critical points: " << ans[0] << endl;
        cout << "Maximum distance between critical points: " << ans[1] << endl;
    }

    cout << "\nErasing the list to complete the program." << endl;
    DoubleLL.Erase();

    return EXIT_SUCCESS;
}

