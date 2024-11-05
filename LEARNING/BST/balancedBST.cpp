#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
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

    Node *BuildBST(Node *temp, int value)
    {
        if (temp == nullptr)
            return new Node(value);

        if (value > temp->value)
            temp->right = BuildBST(temp->right, value);
        else
            temp->left = BuildBST(temp->left, value);

        return temp;
    }

    void inOrderTraversal(Node *temp)
    {
        if (temp == nullptr)
            return;
        inOrderTraversal(temp->left);
        cout << temp->value << "\t";
        inOrderTraversal(temp->right);
    }

    void levelOrderTraversal(Node *temp)
    {
        if (temp == nullptr)
            return;

        queue<Node *> q;
        q.push(temp);
        q.push(nullptr); // To mark the end of a level

        while (!q.empty())
        {
            Node *temp1 = q.front();
            q.pop();

            if (temp1 == nullptr)
            {
                cout << endl;
                if (!q.empty())
                    q.push(nullptr);
            }
            else
            {
                cout << temp1->value << "\t";
                if (temp1->left)
                    q.push(temp1->left);
                if (temp1->right)
                    q.push(temp1->right);
            }
        }
    }

    void FillInorder(Node *temp, vector<int> &arr)
    {
        if (temp == nullptr)
        {
            return;
        }
        FillInorder(temp->left, arr);
        arr.push_back(temp->value);
        FillInorder(temp->right, arr);
    }

    // Correctly balance the tree using a sorted array
    Node *balanceTree(const vector<int> &arr, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int middle = (start + end) / 2;
        Node *node = new Node(arr[middle]);
        node->left = balanceTree(arr, start, middle - 1);
        node->right = balanceTree(arr, middle + 1, end);
        return node;
    }

public:
    BST()
    {
        root = nullptr;
    }

    void BuildTree()
    {
        int value;
        cout << "Enter Element (enter -1 to stop): " << endl;
        cin >> value;
        while (value != -1)
        {
            root = BuildBST(root, value);
            cout << "Enter Element :: " << endl;
            cin >> value;
        }
    }

    void InorderTraversal()
    {
        inOrderTraversal(root);
    }

    void LevelOrderDisplay()
    {
        levelOrderTraversal(root);
    }

    void balance()
    {
        vector<int> arr;
        FillInorder(root, arr);
        delete root; // Clear the original tree
        root = balanceTree(arr, 0, arr.size() - 1);
    }

    // Destructor to free allocated memory
    ~BST()
    {
        // You could implement a method to delete all nodes here for cleanup
        // This is left for implementation to avoid memory leaks.
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    BST bst;
    bst.BuildTree();
    cout << "Level Order Display of Original Tree:" << endl;
    bst.LevelOrderDisplay();
    cout << endl;

    cout << "Inorder Traversal of Original Tree:: ";
    bst.InorderTraversal();
    cout << endl;

    bst.balance();
    
    cout << "Level Order Display of Balanced Tree:" << endl;
    bst.LevelOrderDisplay();
    cout << endl;

    cout << "Inorder Traversal of Balanced Tree:: ";
    bst.InorderTraversal();
    cout << endl;

    return EXIT_SUCCESS;
}
