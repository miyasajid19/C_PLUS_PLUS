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

    // Function to find the lowest common ancestor (LCA) of two nodes in a binary tree
    Node *lowest_common_ancestor(Node *temp, int n1, int n2)
    {
        if (temp == nullptr)
        {
            return nullptr;
        }

        // If current node is one of the nodes we're looking for, return it
        if (temp->value == n1 || temp->value == n2)
            return temp;

        // Recur for left and right subtrees
        Node *leftAns = lowest_common_ancestor(temp->left, n1, n2);
        Node *rightAns = lowest_common_ancestor(temp->right, n1, n2);

        // If both left and right subtrees return non-null, current node is the LCA
        if (leftAns != nullptr && rightAns != nullptr)
            return temp;

        // Otherwise, return the non-null answer
        return (leftAns != nullptr) ? leftAns : rightAns;
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

    Node *LowestCommonAncestor(int n1, int n2)
    {
        return lowest_common_ancestor(root, n1, n2);
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
    cout << endl;
    tree.LevelOrderDisplay();
    cout << "The lowest common ancestor  is " << tree.LowestCommonAncestor(2, 3)->value << endl;
    cout << "The lowest common ancestor  is " << tree.LowestCommonAncestor(2, 4)->value << endl;
    cout << "The lowest common ancestor  is " << tree.LowestCommonAncestor(2, 6)->value << endl;
    cout << "The lowest common ancestor  is " << tree.LowestCommonAncestor(5, 7)->value << endl;
   return EXIT_SUCCESS;
}