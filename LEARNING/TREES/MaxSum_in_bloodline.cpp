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

    // sum of the longest bloodline in the tree
    void solveBloodline(Node *temp, int sum, int &MaxSum, int len, int maxlen)
    {
        if (temp == nullptr)
        {
            if (len > maxlen)
            {
                maxlen = len;
                MaxSum = sum;
            }
            else if (len == maxlen)
            {
                MaxSum = max(sum, MaxSum);
            }
            return;
        }
        sum += temp->value;
        solveBloodline(temp->left, sum, MaxSum, len + 1, maxlen);
        solveBloodline(temp->right, sum, MaxSum, len + 1, maxlen);
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
    int Sum_Bloodline()
    {
        int len = 0;
        int maxlen = 0;
        int sum = 0;
        int MaxSum = INT_MIN;
        solveBloodline(root, sum, MaxSum, len, maxlen);

        return MaxSum;
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
    cout << "The Sum Of Maximum bloodline is " << tree.Sum_Bloodline() << endl;
    return EXIT_SUCCESS;
}