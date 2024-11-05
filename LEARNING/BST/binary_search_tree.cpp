#include <iostream>
#include <cstdlib>
#include <queue>
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

    Node *findMin(Node *temp)
    {
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    Node *findMax(Node *temp)
    {
        while (temp->right != nullptr)
            temp = temp->right;
        return temp;
    }

    Node *deleteNode(Node *temp, int value, bool replaceWithMaxFromLeft = false)
    {
        if (temp == nullptr)
            return temp;

        if (value < temp->value)
            temp->left = deleteNode(temp->left, value, replaceWithMaxFromLeft);
        else if (value > temp->value)
            temp->right = deleteNode(temp->right, value, replaceWithMaxFromLeft);
        else
        {
            // Node with only one child or no child
            if (temp->left == nullptr and temp->right == nullptr)
            {
                delete temp;
                return nullptr;
            }
            if (temp->left != nullptr and temp->right == nullptr)
            {
                Node *leftchild = temp->left;
                delete temp;
                return leftchild;
            }
            if (temp->right != nullptr and temp->left == nullptr)
            {
                Node *rightchild = temp->right;
                delete temp;
                return rightchild;
            }

            // Node with two children: Replace with min from right or max from left based on flag
            if (replaceWithMaxFromLeft)
            {
                Node *maxNode = findMax(temp->left);
                temp->value = maxNode->value;
                temp->left = deleteNode(temp->left, maxNode->value, replaceWithMaxFromLeft);
            }
            else
            {
                Node *minNode = findMin(temp->right);
                temp->value = minNode->value;
                temp->right = deleteNode(temp->right, minNode->value, replaceWithMaxFromLeft);
            }
        }
        return temp;
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

    void DeleteNode(int value, bool replaceWithMaxFromLeft = false)
    {
        root = deleteNode(root, value, replaceWithMaxFromLeft);
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

    // Delete node example
    cout << "Deleting node 10, replacing with max from left..." << endl;
    bst.DeleteNode(10, true); // Replace with max from left
    cout << "Level Order After Deletion:" << endl;
    bst.LevelOrderDisplay();

    cout << endl;
    cout << "Deleting node 20, replacing with min from right..." << endl;
    bst.DeleteNode(20, false); // Replace with min from right
    cout << "Level Order After Deletion:" << endl;
    bst.LevelOrderDisplay();

    return EXIT_SUCCESS;
}
