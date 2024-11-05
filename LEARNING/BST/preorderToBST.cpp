#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
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

    void inOrderTraversal(Node *temp)
    {
        if (temp == nullptr)
            return;
        cout << temp->value << "\t";
        inOrderTraversal(temp->left);
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

    void FillInorder(Node *temp, vector<int> &arr)
    {
        if (temp == nullptr)
        {
            return;
        }
        FillInorder(temp->left, arr);
        arr.push_back(temp->value);
        FillInorder(temp->right, arr);
    }

    // Correctly balance the tree using a sorted array
    Node *balanceTree(const vector<int> &arr, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int middle = (start + end) / 2;
        Node *node = new Node(arr[middle]);
        node->left = balanceTree(arr, start, middle - 1);
        node->right = balanceTree(arr, middle + 1, end);
        return node;
    }
    Node *preorderToBST(const vector<int> &preorder, int minimum, int maximum, int &index)
    {
        if (index >= preorder.size())
            return nullptr;

        int currentValue = preorder[index];
        if (currentValue < minimum || currentValue > maximum)
            return nullptr;

        Node *node = new Node(currentValue);
        index++; // Move to the next element in preorder

        node->left = preorderToBST(preorder, minimum, currentValue, index);
        node->right = preorderToBST(preorder, currentValue, maximum, index);

        return node;
    }

public:
    BST()
    {
        root = nullptr;
    }

    void InorderTraversal()
    {
        inOrderTraversal(root);
    }

    void LevelOrderDisplay()
    {
        levelOrderTraversal(root);
    }
    void PreorderToBST(vector<int> preorder)
    {
        int index = 0;
        root = preorderToBST(preorder, INT_MIN, INT_MAX, index);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    BST bst;
    vector<int> preorder = {10, 6, 7, 13, 14};
    bst.PreorderToBST(preorder);
    cout << "Inorder Traversal :: " << endl;
    bst.InorderTraversal();
    cout << " Level wise Traversal :: " << endl;
    bst.LevelOrderDisplay();
    return EXIT_SUCCESS;
}
