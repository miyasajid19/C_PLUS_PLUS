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
        {
            return;
        }
        inOrderTraversal(temp->left);
        cout << temp->value << "\t";
        inOrderTraversal(temp->right);
    }
    void preOrderTraversal(Node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        cout << temp->value << "\t";
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
    }
    void postOrderTraversal(Node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
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
    Node *searchTree(Node *temp, int value)
    {
        if (temp == nullptr)
            return nullptr;

        if (temp->value == value)
            return temp;

        if (value > temp->value)
            return searchTree(temp->left, value);
        else
            return searchTree(temp->right, value);
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
        } // O(log n)
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
        return searchTree(root,value);
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
 cout<<boolalpha;
 cout<<endl;
 cout<<"10??"<<bst.SearchNode(10)<<endl;
 cout<<"432??"<<bst.SearchNode(432)<<endl;
    return EXIT_SUCCESS;
}