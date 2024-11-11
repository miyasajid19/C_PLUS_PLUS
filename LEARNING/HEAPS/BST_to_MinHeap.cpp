#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST
{
    Node *root;

    Node *add(Node *temp, int value)
    {
        if (temp == nullptr)
            return new Node(value);

        if (value > temp->value)
            temp->right = add(temp->right, value);
        else
            temp->left = add(temp->left, value);

        return temp;
    }

    void Display(Node *temp)
    {
        if (temp == nullptr)
            return;

        Display(temp->left);
        cout << temp->value << '\t';
        Display(temp->right);
    }

    void inorder(Node* temp, vector<int>& Inorder)
    {
        if (temp == nullptr)
            return;
        inorder(temp->left, Inorder);
        Inorder.push_back(temp->value);
        inorder(temp->right, Inorder);
    }

public:
    BST()
    {
        this->root = nullptr;
    }

    void insert(int value)
    {
        root = add(root, value);
    }

    void display()
    {
        Display(root);
        cout << endl;
    }

    void getInorder(vector<int>& Inorder)
    {
        inorder(root, Inorder);
    }
};

class Heap
{
    vector<int> arr;

    void heapify(int size, int index)
    {
        int parentIndex = index;
        int LeftIndex = 2 * index + 1;
        int RightIndex = 2 * index + 2;

        if (LeftIndex < size && arr[LeftIndex] > arr[parentIndex])
            parentIndex = LeftIndex;
        if (RightIndex < size && arr[RightIndex] > arr[parentIndex])
            parentIndex = RightIndex;

        if (parentIndex != index)
        {
            swap(arr[parentIndex], arr[index]);
            heapify(size, parentIndex);
        }
    }

public:
    Heap() {}

    // Constructor to create a heap from a vector of elements
    Heap(vector<int> temp)
    {
        arr = temp;
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
            heapify(arr.size(), i);
    }

    // Constructor to create a heap from a BST
    Heap(BST bst)
    {
        vector<int> inorder;
        bst.getInorder(inorder);

        // Insert all elements from the inorder traversal into the heap array
        arr = inorder;

        // Build the heap
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
            heapify(arr.size(), i);
    }

    void display()
    {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << '\t';
        cout << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    BST bst;
    bst.insert(1);
    bst.insert(11);
    bst.insert(10);
    bst.insert(-1);
    cout << "BST Inorder Display: ";
    bst.display();

    Heap heap(bst);
    cout << "Heap Display: ";
    heap.display();

    return EXIT_SUCCESS;
}
