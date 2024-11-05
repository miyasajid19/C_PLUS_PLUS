#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <map>
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

    void preOrderTraversal(Node *temp)
    {
        if (temp == nullptr)
            return;
        cout << temp->value << "\t";
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
    }

    void postOrderTraversal(Node *temp)
    {
        if (temp == nullptr)
            return;
        postOrderTraversal(temp->left);
        postOrderTraversal(temp->right);
        cout << temp->value << "\t";
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

    bool searchTree(Node *temp, int value)
    {
        if (temp == nullptr)
            return false;

        if (temp->value == value)
            return true;

        if (value < temp->value) // corrected direction for search
            return searchTree(temp->left, value);
        else
            return searchTree(temp->right, value);
    }

    bool optimumSearch(Node *temp, int value)
    {
        while (temp != nullptr)
        {
            if (temp->value == value)
                return true;

            if (value < temp->value)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }

    Node *findMin(Node *temp)
    {
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    Node *deleteNode(Node *temp, int value)
    {
        if (temp == nullptr)
            return temp;

        if (value < temp->value)
            temp->left = deleteNode(temp->left, value);
        else if (value > temp->value)
            temp->right = deleteNode(temp->right, value);
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

            // Node with two children: Get the inorder successor
            if (temp->right != nullptr and temp->left != nullptr)
            {
                Node *minNode = findMin(temp->right);
                temp->value = minNode->value;
                temp->right = deleteNode(temp->right, minNode->value);
            }

            if(temp->right and temp->left)
            {
                Node* maxNode=findMax)
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

    void PreOrderTraversal()
    {
        preOrderTraversal(root);
    }

    void PostOrderTraversal()
    {
        postOrderTraversal(root);
    }

    void LevelOrderDisplay()
    {
        levelOrderTraversal(root);
    }

    bool SearchNode(int value)
    {
        return searchTree(root, value);
    }

    bool OptimizedSearchNode(int value)
    {
        return optimumSearch(root, value);
    }

    void DeleteNode(int value)
    {
        root = deleteNode(root, value);
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
    cout << "PreOrder Traversal :: ";
    bst.PreOrderTraversal();
    cout << endl;
    cout << "PostOrder Traversal :: ";
    bst.PostOrderTraversal();
    cout << boolalpha;
    cout << endl;
    cout << "Search 10: " << bst.SearchNode(10) << endl;
    cout << "Search 432: " << bst.SearchNode(432) << endl;
    cout << endl;
    cout << "Optimized Search 10: " << bst.OptimizedSearchNode(10) << endl;
    cout << "Optimized Search 432: " << bst.OptimizedSearchNode(432) << endl;
    cout << endl;

    // Delete node example
    cout << "Deleting node 10..." << endl;
    bst.DeleteNode(10);
    cout << "Level Order After Deletion:" << endl;
    bst.LevelOrderDisplay();

    return EXIT_SUCCESS;
}
