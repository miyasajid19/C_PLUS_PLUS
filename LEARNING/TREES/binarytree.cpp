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
    void levelOrderTraversal(Node *temp)
    {
        queue<Node *> q;
        q.push(temp);
        q.push(nullptr);
        while (not q.empty())
        {
            Node *temp1 = q.front();
            q.pop();
            if (temp1 == nullptr)
            {
                cout << endl;
                if (not q.empty())
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
    tree.LevelOrderDisplay();
    return EXIT_SUCCESS;
}