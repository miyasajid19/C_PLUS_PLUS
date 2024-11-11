#include <iostream>
#include <cstdlib>
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

class Heap; // Forward declaration

class BST
{
private:
    Node *root;

    Node *addNode(Node *temp, int value)
    {
        if (temp == nullptr)
        {
            return new Node(value);
        }
        if (temp->value > value)
        {
            temp->left = addNode(temp->left, value);
        }
        else
        {
            temp->right = addNode(temp->right, value);
        }
        return temp;
    }

    int countNodes(Node *temp)
    {
        if (temp == nullptr)
            return 0;
        return 1 + countNodes(temp->left) + countNodes(temp->right);
    }

    void display(Node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        display(temp->left);
        cout << temp->value << "\t";
        display(temp->right);
    }

    bool isCompleteBT(Node *temp, int index, int totalNodes)
    {
        if (temp == nullptr)
            return true;
        if (index >= totalNodes)
            return false;
        return isCompleteBT(temp->left, 2 * index + 1, totalNodes) && isCompleteBT(temp->right, 2 * index + 2, totalNodes);
    }

    friend Heap;

public:
    BST()
    {
        root = nullptr;
    }

    void addNode(int value)
    {
        root = addNode(root, value);
    }

    int getNodesCount()
    {
        return countNodes(root);
    }

    void display()
    {
        display(root);
        cout << endl;
    }

    bool isCompleteBinaryTree()
    {
        if (root == nullptr)
            return true; // An empty tree is a complete binary tree
        int totalNodes = getNodesCount();
        return isCompleteBT(root, 0, totalNodes);
    }

    Node* getRoot()
    {
        return root;
    }
};

class Heap
{
private:
    bool isMaxOrder(Node *temp)
    {
        if (temp == nullptr)
            return true;

        // Leaf node
        if (temp->left == nullptr && temp->right == nullptr)
            return true;

        // Check if it's greater than its children
        bool leftOrder = (temp->left == nullptr || temp->value >= temp->left->value) && isMaxOrder(temp->left);
        bool rightOrder = (temp->right == nullptr || temp->value >= temp->right->value) && isMaxOrder(temp->right);

        return leftOrder && rightOrder;
    }

public:
    bool isHeap(BST &bst)
    {
        return bst.isCompleteBinaryTree() && isMaxOrder(bst.getRoot());
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    BST bst;
    bst.addNode(1000);
    // bst.addNode(950);
    // // bst.addNode(946);
    // // bst.addNode(46);
    // // bst.addNode(38);
    bst.addNode(39);

    cout << "Tree nodes in in-order: ";
    bst.display();
    cout << "Total nodes: " << bst.getNodesCount() << endl;

    Heap heap;
    if (heap.isHeap(bst))
        cout << "The tree is a max-heap." << endl;
    else
        cout << "The tree is not a max-heap." << endl;

    return EXIT_SUCCESS;
}
