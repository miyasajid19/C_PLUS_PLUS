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
    // boundary wise traversal
    void Traverse_Left(Node *temp, vector<int> &ans)
    {
        if ((temp == nullptr) or ((temp->left == nullptr) and (temp->right == nullptr)))
            return;

        ans.push_back(temp->value);
        if (temp->left)
        {
            Traverse_Left(temp->left, ans);
        }
        if (temp->right)
        {
            Traverse_Left(temp->right, ans);
        }
    }
    void Traverse_Leaf(Node *temp, vector<int> &ans)
    {
        if (temp == nullptr)
            return;

        if (temp->left == nullptr and temp->right == nullptr)
            ans.push_back(temp->value);

        Traverse_Leaf(temp->left, ans);
        Traverse_Leaf(temp->right, ans);
    }
    void Traverse_Right(Node *temp, vector<int> &ans)
    {
        if ((temp == nullptr) or ((temp->left == nullptr) and (temp->right == nullptr)))
        {
            return;
        }
        if (temp->right)
        {
            Traverse_Right(temp->right, ans);
        }
        else
        {
            Traverse_Right(temp->left, ans);
        }
        ans.push_back(temp->value);
    }
    vector<int> boundary_wise_traversal(Node *temp)
    {
        vector<int> ans;
        if (temp == nullptr)
            return ans;
        ans.push_back(temp->value);
        // traverse left nodes
        Traverse_Left(temp->left, ans);

        // traverse leaf node
        Traverse_Leaf(temp->left, ans);
        Traverse_Leaf(temp->right, ans);

        // traverse reverse wise right node
        Traverse_Right(temp->right, ans);

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

    void BoundaryWiseTraversal()
    {
        vector<int> result = boundary_wise_traversal(root);
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
    cout << "Boundary wise Traversal ::: ";
    tree.BoundaryWiseTraversal();
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