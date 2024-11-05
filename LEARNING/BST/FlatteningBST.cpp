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

    // Unoptimized Flatten: Using an auxiliary vector
    void FlattenUnoptimized()
    {
        vector<int> arr;
        FillInorder(root, arr);
        Node *new_root = nullptr;
        Node *current = nullptr;

        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0)
            {
                new_root = new Node(arr[i]);
                current = new_root;
            }
            else
            {
                current->right = new Node(arr[i]);
                current = current->right;
            }
        }
        arr.clear();
        delete root;
        root = new_root;
    }

    // Optimized Flatten: In-place modification of the tree
    void FlattenOptimized()
    {
        if (!root) return; // Handle empty tree

        Node *current = root;
        Node *prev = nullptr;

        stack<Node *> s;

        while (current || !s.empty())
        {
            // Go to the leftmost node
            while (current)
            {
                s.push(current);
                current = current->left;
            }

            // Process the node
            current = s.top();
            s.pop();

            // If there's a previous node, link it to the current
            if (prev)
            {
                prev->right = current; // Link previous node's right to current
                prev->left = nullptr;  // Ensure left is null
            }

            // Update the previous node to the current
            prev = current;

            // Move to the right node
            current = current->right;
        }

        // The root is now the start of a right-skewed linked list
        // Ensure the left pointer of the root is null
        root->left = nullptr;
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

    int choice;
    cout << "Choose Flatten Method: (1) Unoptimized (2) Optimized: ";
    cin >> choice;

    if (choice == 1)
    {
        bst.FlattenUnoptimized();
    }
    else if (choice == 2)
    {
        bst.FlattenOptimized();
    }
    else
    {
        cout << "Invalid choice." << endl;
        return EXIT_FAILURE;
    }

    bst.LevelOrderDisplay();
    cout << endl;
    cout << "Inorder Traversal :: ";
    bst.InorderTraversal();
    cout << endl;
    return EXIT_SUCCESS;
}
