#include <iostream>
#include <cstdlib>
#include <stack>
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

class BST
{
    Node *root;

    Node *BuildBST(Node *temp, int value)
    {
        if (temp == nullptr)
            return new Node(value);

        if (value > temp->value)
            temp->right = BuildBST(temp->right, value);
        else
            temp->left = BuildBST(temp->left, value);

        return temp;
    }

    void inOrderTraversal(Node *temp)
    {
        if (temp == nullptr)
            return;
        inOrderTraversal(temp->left);
        cout << temp->value << "\t";
        inOrderTraversal(temp->right);
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
    bool validate(Node *temp, int minimum, int maximum)
    {
        if (temp == nullptr)
            return true;

        bool left = validate(temp->left, minimum, temp->value);
        bool right = validate(temp->right, temp->value, maximum);
        return left and right;
    }
    void validate_Intitution1(Node *temp, stack<int> &stk)
    {
        if (temp == nullptr)
            return;

        validate_Intitution1(temp->left, stk);
        stk.push(temp->value);
        validate_Intitution1(temp->right, stk);
    }

public:
    BST()
    {
        root = nullptr;
    }

    void BuildTree()
    {
        int value;
        cout << "Enter Element " << endl;
        cin >> value;
        while (value != -1)
        {
            root = BuildBST(root, value);
            cout << "Enter Element :: " << endl;
            cin >> value;
        }
    }

    void InorderTraversal()
    {
        inOrderTraversal(root);
    }

    void LevelOrderDisplay()
    {
        levelOrderTraversal(root);
    }
    bool validateTree()
    {
        return validate(root, INT_MIN, INT_MAX);
    }
    bool validateTree1()
    {
        stack<int> stk;
        validate_Intitution1(root, stk);
        int previous = INT_MAX;
        while (not stk.empty())
        {
            int top = stk.top();
            if (top > previous)
                return false;

            stk.pop();
            previous = top;
        }
        return true;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    BST bst;
    bst.BuildTree();
    bst.LevelOrderDisplay();
    cout << endl;
    cout << "Inorder Traversal :: ";
    bst.InorderTraversal();
    cout << endl;
    cout << boolalpha;
    cout << "Is balanced? (using recursive method): " << bst.validateTree() << endl;
    cout << "Is balanced? (using iterative method): " << bst.validateTree1() << endl;
    return EXIT_SUCCESS;
}
