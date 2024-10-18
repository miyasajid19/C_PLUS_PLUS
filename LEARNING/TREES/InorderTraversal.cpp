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

class Tree
{
    Node *root;

    Node *Build(Node *temp)
    {
        int value;
        cout << "Enter value (-1 to terminate): ";
        cin >> value;

        if (value == -1)
        {
            return nullptr;
        }

        temp = new Node(value);

        cout << "Enter left node for " << value << endl;
        temp->left = Build(temp->left);

        cout << "Enter right node for " << value << endl;
        temp->right = Build(temp->right);

        return temp;
    }

    void displayinorder(Node *temp)
    {
        if (temp == nullptr)
            return;
        displayinorder(temp->left);
        cout << temp->value << " ";
        displayinorder(temp->right);
    }

public:
    Tree()
    {
        root = nullptr;
    }

    void BuildTree()
    {
        root = Build(root);
    }

    void DisplayInorder()
    {
        displayinorder(root);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Tree tree;
    tree.BuildTree();
    cout << endl;
    cout << endl
         << "Inorder :: " << endl;
    tree.DisplayInorder();
    return EXIT_SUCCESS;
}