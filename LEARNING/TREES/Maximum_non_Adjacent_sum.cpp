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

    // sum of non adjacent nodes
    pair<int, int> sum_nonAdjacent(Node *temp)
    {
        if (temp == nullptr)
        {
            return make_pair(0, 0);
        }
        pair<int, int> leftAns = sum_nonAdjacent(temp->left);
        pair<int, int> rightAns = sum_nonAdjacent(temp->right);

        pair<int, int> result;
        result.first = temp->value + leftAns.second + rightAns.second;
        result.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
        return result;
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

    int Non_Adjacent_sum()
    {
        pair<int, int> ans = sum_nonAdjacent(root);
        return max(ans.first, ans.second);
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
    cout << endl;
    cout << "the Maximum non-adjacent sum of the tree is " << tree.Non_Adjacent_sum() << endl;
    return EXIT_SUCCESS;
}