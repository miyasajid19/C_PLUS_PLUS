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

    // vertical order traversal
    vector<int> vertical_order_traversal(Node *temp)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> Queue;
        vector<int> ans;
        if (temp == nullptr)
            return ans;

        Queue.push(make_pair(temp, make_pair(0, 0)));

        while (not Queue.empty())
        {
            pair<Node *, pair<int, int>> temp1 = Queue.front();
            Queue.pop();
            Node *FrontNode = temp1.first;
            int horizontalDistance = temp1.second.first;
            int level = temp1.second.second;
            nodes[horizontalDistance][level].push_back(FrontNode->value);

            if (FrontNode->left)
                Queue.push(make_pair(FrontNode->left, make_pair(horizontalDistance - 1, level + 1)));

            if (FrontNode->right)
                Queue.push(make_pair(FrontNode->right, make_pair(horizontalDistance + 1, level + 1)));
        }
        for (auto x : nodes)
        {
            for (auto y : x.second)
            {
                for (auto x : y.second)
                {
                    ans.push_back(x);
                }
            }
        }
        return ans;
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

    void VertivalOrderTraversal()
    {
        vector<int> result = vertical_order_traversal(root);
        for (auto x : result)
            cout << x << " ";
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
    cout << endl;
    cout << "Vertical Order Traversal ::: ";
    tree.VertivalOrderTraversal();
    cout << endl;
    return EXIT_SUCCESS;
}