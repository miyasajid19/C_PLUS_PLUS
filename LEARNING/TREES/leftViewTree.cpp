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
    // left view
    // Function to return the list of the elements of the left view of the binary tree
    void solveleft(Node *temp, vector<int> &ans, int level)
    {
        // Base case
        if (temp == nullptr)
            return;

        // If we enter a new level
        if (level == ans.size())
            ans.push_back(temp->value);

        // Recursively call for left and right subtrees
        solveleft(temp->left, ans, level + 1);
        solveleft(temp->right, ans, level + 1);
    }

    vector<int> leftview(Node *temp)
    {
        vector<int> ans;
        solveleft(temp, ans, 0);
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
void LeftView()
    {
        vector<int> result = leftview(root);
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
    cout << "Left View ::: ";
    tree.LeftView();
    cout << endl;
    return EXIT_SUCCESS;
}