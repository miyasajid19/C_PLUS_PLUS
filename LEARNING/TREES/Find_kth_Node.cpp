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

    // Kth nearest neighbour
    Node *find_kth_node(Node *temp, int &k, int nodeValue)
    {
        // base case
        if (temp == nullptr)
        {
            return nullptr;
        }
        if (temp->value == nodeValue)
        {
            return temp;
        }
        Node *leftAns = find_kth_node(temp->left, k, nodeValue);
        Node *rightAns = find_kth_node(temp->right, k, nodeValue);

        if (leftAns != nullptr and rightAns == nullptr)
        {
            k--;
            if (k <= 0)
            {
                k = INT_MAX;
                return temp;
            }
            return leftAns;
        }

        if (leftAns == nullptr and rightAns != nullptr)
        {
            k--;
            if (k <= 0)
            {
                k = INT_MAX;
                return temp;
            }
            return rightAns;
        }
        return nullptr;
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
    int Kth_Node(int k, int nodeValue)
    {
        Node *ans = find_kth_node(root, k, nodeValue);
        if (ans == nullptr)
            return -1;
        else
            return ans->value;
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
   cout << "the 2nd  neighbour of the node 3 is " << tree.Kth_Node(2, 3) << endl;
    return EXIT_SUCCESS;
}