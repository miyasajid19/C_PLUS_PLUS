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
    void morrisTraversal(Node *temp)
    {
        Node *current = temp;

        while (current != nullptr)
        {
            if (current->left == nullptr)
            {
                cout << current->value << " "; // Print the current node's value
                current = current->right;      // Move to the right subtree
            }
            else
            {
                // Find the predecessor (rightmost node in the left subtree)
                Node *predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current)
                {
                    predecessor = predecessor->right;
                }

                // Create a temporary link to the current node
                if (predecessor->right == nullptr)
                {
                    predecessor->right = current;
                    current = current->left;
                }
                // Restore the tree structure
                else
                {
                    predecessor->right = nullptr;
                    cout << current->value << " "; // Print the current node's value
                    current = current->right;
                }
            }
        }
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

    void LevelOrderDisplay()
    {
        levelOrderTraversal(root);
    }

    void MorrisTraversal()
    {
        morrisTraversal(root);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << boolalpha;
    Tree tree;
    tree.BuildTree();
    // tree.BuildTreeFromLevel();
    cout << endl;
    tree.LevelOrderDisplay();
    cout << "Morris Traversal ::: ";
    tree.MorrisTraversal();
    return EXIT_SUCCESS;
}