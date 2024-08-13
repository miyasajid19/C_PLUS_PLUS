#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Node
{
private:
    static int counter; // Static variable declaration

public:
    int id;
    string task;
    int priority;
    Node *Next;

    Node(string task, int priority) : task(task), priority(priority), Next(nullptr)
    {
        this->id = ++counter; // Increment and assign unique id
    }

    static int getTotalTasks()
    { // Method to get the total number of tasks
        return counter;
    }
};

int Node::counter = 0;

class LinkedLists
{
public:
    Node *head;
    LinkedLists() : head(nullptr) {}

    ~LinkedLists()
    {
        while (head)
        {
            Node *temp = head;
            head = head->Next;
            delete temp;
        }
    }

    void addToHead(string task, int priority)
    {
        Node *new_node = new Node(task, priority);
        new_node->Next = head;
        head = new_node;
    }

    void insertAtTail(string task, int priority)
    {
        Node *new_node = new Node(task, priority);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }

    void insert(string task, int priority, int position)
    {
        Node *new_node = new Node(task, priority);
        if (position < 0)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Invalid index! Index out of bounds." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            delete new_node;
            return;
        }
        if (head == nullptr && position == 0)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        int currentPosition = 0;
        while (temp && currentPosition < position - 1)
        {
            temp = temp->Next;
            currentPosition++;
        }
        if (temp == nullptr)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Index out of bounds." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            delete new_node;
            return;
        }
        new_node->Next = temp->Next;
        temp->Next = new_node;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout << "The list is empty." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << "Id: " << temp->id << endl;
            cout << "Priority: " << temp->priority << endl;
            cout << "Task: " << temp->task << endl;
            temp = temp->Next;
            cout << "--------------------------------------------------------------------" << endl;
        }
    }

    void deleteTask(int id)
    {
        if (head == nullptr)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Nothing to delete." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return;
        }
        Node *temp = head;
        Node *previous = nullptr;
        if (head->id == id)
        {
            head = head->Next;
            delete temp;
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Head node deleted." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return;
        }
        while (temp && temp->id != id)
        {
            previous = temp;
            temp = temp->Next;
        }
        if (temp == nullptr)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout << "No task found with ID: " << id << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return;
        }
        previous->Next = temp->Next;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Task with ID: " << temp->id << " deleted." << endl;
        cout << "--------------------------------------------------------------------" << endl;
        delete temp;
    }

    void update(string task, int id)
    {
        if (head == nullptr)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout << "The list is empty. Nothing to update." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return;
        }
        Node *temp = head;
        while (temp && temp->id != id)
        {
            temp = temp->Next;
        }
        if (temp == nullptr)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout << "No task found with ID: " << id << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return;
        }
        temp->task = task;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Task with ID: " << id << " updated." << endl;
        cout << "--------------------------------------------------------------------" << endl;
    }

    void search(int id)
    {
        if (head == nullptr)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout << "The list is empty." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return;
        }
        Node *temp = head;
        while (temp && temp->id != id)
        {
            temp = temp->Next;
        }
        if (temp == nullptr)
        {
            cout << "Task not found with ID: " << id << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return;
        }
        cout << "Task found!" << endl;
        cout << "Id: " << temp->id << endl;
        cout << "Priority: " << temp->priority << endl;
        cout << "Task: " << temp->task << endl;
        cout << "--------------------------------------------------------------------" << endl;
    }

    int getTotalTasks()
    {
        return Node::getTotalTasks();
    }
};

int main()
{
    LinkedLists lists;
    while (true)
    {
        cout << "1. Add a new task\n2. Update a task\n3. Delete a task\n4. Search for a task by ID\n5. Display all tasks\n6. Get the total number of tasks\n7. Exit\n";
        cout << "--------------------------------------------------------------------" << endl;
        int choice;
        string task;
        int priority;
        int id;
        cin >> choice;
        cout << "--------------------------------------------------------------------" << endl;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice)
        {
        case 1:
            cout << "Enter task: ";
            getline(cin, task);
            cout << "Enter priority: ";
            cin >> priority;
            lists.insertAtTail(task, priority);
            cout << "Task inserted." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            cin.get(); // Wait for user to press Enter
            break;
        case 2:
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(); // Clear the newline character from the input buffer
            cout << "Enter task to update: ";
            getline(cin, task);
            lists.update(task, id);
            cout << "--------------------------------------------------------------------" << endl;
            cin.get(); // Wait for user to press Enter
            break;
        case 3:
            cout << "Enter ID to delete: ";
            cin >> id;
            lists.deleteTask(id);
            cout << "--------------------------------------------------------------------" << endl;
            cin.get(); // Wait for user to press Enter
            break;
        case 4:
            cout << "Enter ID to search: ";
            cin >> id;
            lists.search(id);
            cout << "--------------------------------------------------------------------" << endl;
            cin.get(); // Wait for user to press Enter
            break;
        case 5:
            lists.display();
            cout << "--------------------------------------------------------------------" << endl;
            cin.get(); // Wait for user to press Enter
            break;
        case 6:
            cout << "Total tasks present: " << lists.getTotalTasks() << endl;
            cout << "--------------------------------------------------------------------" << endl;
            cin.get(); // Wait for user to press Enter
            break;
        case 7:
            cout << "Exitting..............." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return EXIT_SUCCESS;
        default:
            cout << "Invalid input." << endl;
            cout << "--------------------------------------------------------------------" << endl;
            break;
        }
    }
    return EXIT_SUCCESS;
}
