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
            return;

        FillInorder(temp->left, arr);
        arr.push_back(temp->value);
        FillInorder(temp->right, arr);
    }

public:
    BST()
    {
        root = nullptr;
    }

    void BuildTree()
    {
        int value;
        cout << "Enter Element " << endl;
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

    void Flatten()
    {
        vector<int> arr;
        FillInorder(root, arr);  // Fill arr with in-order traversal of the BST

        // Start building the right-skewed "linked list" structure
        Node *new_root = new Node(arr[0]);
        Node *current = new_root;

        for (size_t i = 1; i < arr.size(); i++)
        {
            current->right = new Node(arr[i]);
            current = current->right;
        }

        // Delete the original tree to prevent memory leaks
        delete root;

        // Update the root to point to the new flattened structure
        root = new_root;
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
    bst.LevelOrderDisplay();
    cout << endl;
    cout << "Inorder Traversal :: ";
    bst.InorderTraversal();
    cout << endl;

    bst.Flatten();

    bst.LevelOrderDisplay();
    cout << endl;
    cout << "Inorder Traversal :: ";
    bst.InorderTraversal();
    cout << endl;
    return EXIT_SUCCESS;
}
