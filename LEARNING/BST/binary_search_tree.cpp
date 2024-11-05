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

public:
    BST()
    {
        root = nullptr;
    }

    void BuildTree()
    {
        int value;
        cout<<"Enter Element "<<endl;
        cin>>value;
        while (value != -1)
        {
            root = BuildBST(root, value);
            cout << "Enter Element :: " << endl;
            cin >> value;
        } 
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
    BST bst;
    bst.BuildTree();
    bst.LevelOrderDisplay();
    return EXIT_SUCCESS;
}