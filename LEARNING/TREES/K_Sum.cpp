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

    // k sum
    void k_sum(Node *temp, int k, int &count, vector<int> path)
    {
        if (temp == nullptr)
            return;

        path.push_back(temp->value);

        // left
        k_sum(temp->left, k, count, path);

        // right
        k_sum(temp->right, k, count, path);

        // checking K sum
        int size = path.size();
        int sum = 0;
        for (int i = size - 1; i >= 1; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }
        path.pop_back();
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
    int K_Sum(int k)
    {
        int count = 0;
        vector<int> path;
        k_sum(root, k, count, path);
        return count;
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
    cout << "There are " << tree.K_Sum(5) << " ways to get the sum 5 in the tree" << endl;
    cout << "There are " << tree.K_Sum(12) << " ways to get the sum 12 in the tree" << endl;
    cout << "There are " << tree.K_Sum(7) << " ways to get the sum 7 in the tree" << endl;
    return EXIT_SUCCESS;
}