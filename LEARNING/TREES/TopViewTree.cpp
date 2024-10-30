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

    // Top View
    vector<int> topview(Node *temp)
    {
        vector<int> ans;
        if (temp == nullptr)
            return ans;

        map<int, int> TopNode;
        queue<pair<Node *, int>> Queue;

        Queue.push(make_pair(temp, 0));

        while (!Queue.empty())
        {
            pair<Node *, int> temp1 = Queue.front();
            Queue.pop(); // Remove the front element after processing
            Node *FrontNode = temp1.first;
            int horizontalDistance = temp1.second;

            if (TopNode.find(horizontalDistance) == TopNode.end())
            {
                TopNode[horizontalDistance] = FrontNode->value;
            }

            if (FrontNode->left)
                Queue.push(make_pair(FrontNode->left, horizontalDistance - 1));

            if (FrontNode->right)
                Queue.push(make_pair(FrontNode->right, horizontalDistance + 1));
        }

        for (auto x : TopNode)
        {
            ans.push_back(x.second);
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

    void TopView()
    {
        vector<int> result = topview(root);
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
    cout << "Top View ::: ";
    tree.TopView();
    cout << endl;
    return EXIT_SUCCESS;
}
// 1
// 2
// 4
// -1
// -1
// 5
// -1
// -1
// 3
// 6
// -1
// -1
// 7
// -1
// -1