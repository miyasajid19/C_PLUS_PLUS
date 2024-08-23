#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int value;
    Node *Next;
    Node *previous;
    
    Node(int value) : value(value), Next(nullptr), previous(nullptr) {}
};

class Deque {
    Node *head;
    Node *tail;
    int capacity;
    int size;

public:
    Deque(int capacity) : head(nullptr), tail(nullptr), capacity(capacity), size(0) {}

    ~Deque() {
        Erase();
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void Push_back(int value) {
        if (isFull()) {
            cout << "Deque overflow" << endl;
            return;
        }
        Node *new_node = new Node(value);
        if (!tail) {
            head = tail = new_node;
        } else {
            tail->Next = new_node;
            new_node->previous = tail;
            tail = new_node;
        }
        ++size;
    }

    void Push_front(int value) {
        if (isFull()) {
            cout << "Deque overflow" << endl;
            return;
        }
        Node *new_node = new Node(value);
        if (!head) {
            head = tail = new_node;
        } else {
            new_node->Next = head;
            head->previous = new_node;
            head = new_node;
        }
        ++size;
    }

    void Pop_back() {
        if (isEmpty()) {
            cout << "Deque underflow" << endl;
            return;
        }
        Node *temp = tail;
        tail = tail->previous;
        if (tail) {
            tail->Next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        --size;
    }

    void Pop_front() {
        if (isEmpty()) {
            cout << "Deque underflow" << endl;
            return;
        }
        Node *temp = head;
        head = head->Next;
        if (head) {
            head->previous = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        --size;
    }

    int Front() const {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return head->value;
    }

    int Back() const {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return tail->value;
    }

    int Size() const {
        return size;
    }

    void Erase() {
        while (!isEmpty()) {
            Pop_front();
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Deque deque(5);  // Creating a Deque with a maximum capacity of 5
    cout << boolalpha;

    // Initial status of the deque
    cout << "Is the deque empty? " << deque.isEmpty() << endl;  // Expected: true
    cout << "Is the deque full? " << deque.isFull() << endl;    // Expected: false
    cout << "Front element: " << deque.Front() << endl;         // Expected: Deque is empty
    cout << "Back element: " << deque.Back() << endl;           // Expected: Deque is empty

    // Push elements at the back
    deque.Push_back(3);
    cout << "After pushing 3 to the back, Front: " << deque.Front() << " Back: " << deque.Back() << endl;

    deque.Push_back(4);
    cout << "After pushing 4 to the back, Front: " << deque.Front() << " Back: " << deque.Back() << endl;

    deque.Push_back(5);
    cout << "After pushing 5 to the back, Front: " << deque.Front() << " Back: " << deque.Back() << endl;

    // Push elements at the front
    deque.Push_front(2);
    cout << "After pushing 2 to the front, Front: " << deque.Front() << " Back: " << deque.Back() << endl;

    deque.Push_front(1);
    cout << "After pushing 1 to the front, Front: " << deque.Front() << " Back: " << deque.Back() << endl;

    // Check if the deque is full now
    cout << "Is the deque empty? " << deque.isEmpty() << endl;  // Expected: false
    cout << "Is the deque full? " << deque.isFull() << endl;    // Expected: true
    cout << "Current size of deque: " << deque.Size() << endl;  // Expected: 5

    // Trying to push when deque is full
    deque.Push_front(0);  // Should display overflow message
    deque.Push_back(6);   // Should display overflow message

    // Pop elements from the front and back
    deque.Pop_front();
    cout << "After popping front, Front: " << deque.Front() << " Back: " << deque.Back() << endl;

    deque.Pop_front();
    cout << "After popping front, Front: " << deque.Front() << " Back: " << deque.Back() << endl;

    deque.Pop_front();
    cout << "After popping front, Front: " << deque.Front() << " Back: " << deque.Back() << endl;

    deque.Pop_back();
    cout << "After popping back, Front: " << deque.Front() << " Back: " << deque.Back() << endl;

    return EXIT_SUCCESS;
}
