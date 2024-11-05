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

    // Perform in-order traversal and push elements onto the stack in sorted order
    void fillStackInOrder(Node *temp, stack<int> &stk)
    {
        if (temp == nullptr)
            return;

        fillStackInOrder(temp->left, stk);
        stk.push(temp->value);
        fillStackInOrder(temp->right, stk);
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

    // Stack-based approach to find predecessor and successor
    pair<int, int> PredecessorSuccessor(int k)
    {
        stack<int> stk;
        fillStackInOrder(root, stk);

        // We use two temporary variables to keep track of predecessor and successor
        int predecessor = -1;
        int successor = -1;

        stack<int> orderedStack;
        while (!stk.empty())
        {
            orderedStack.push(stk.top()); // Reverse stack to access in order
            stk.pop();
        }

        bool found = false;
        while (!orderedStack.empty())
        {
            int top = orderedStack.top();
            orderedStack.pop();

            if (top == k)
            {
                found = true;
                // Successor will be the next element in stack, if exists
                if (!orderedStack.empty())
                {
                    successor = orderedStack.top();
                }
                break;
            }
            predecessor = top; // Last element before finding `k` is the predecessor
        }

        if (!found)
        {
            cout << "Element " << k << " not found in the BST." << endl;
            return make_pair(-1, -1); // Element not found case
        }

        return make_pair(predecessor, successor);
    }
    pair<int, int> SuccessorPredecessor(int k) {
    Node* temp = root;
    int predecessor = -1;
    int successor = -1;

    // Traverse to locate the node `k` while updating predecessor and successor
    while (temp != nullptr) {
        if (temp->value == k) {
            break; // Node with value `k` found
        }
        else if (k < temp->value) {
            successor = temp->value;  // Update successor as we move left
            temp = temp->left;
        }
        else {
            predecessor = temp->value;  // Update predecessor as we move right
            temp = temp->right;
        }
    }

    // If `k` not found in the tree
    if (temp == nullptr) {
        cout << "Element " << k << " not found in the BST." << endl;
        return make_pair(-1, -1);
    }

    // Find predecessor (rightmost node in left subtree of `k`)
    if (temp->left != nullptr) {
        Node* leftTree = temp->left;
        while (leftTree->right != nullptr) {
            leftTree = leftTree->right;
        }
        predecessor = leftTree->value;
    }

    // Find successor (leftmost node in right subtree of `k`)
    if (temp->right != nullptr) {
        Node* rightTree = temp->right;
        while (rightTree->left != nullptr) {
            rightTree = rightTree->left;
        }
        successor = rightTree->value;
    }

    return make_pair(predecessor, successor);
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

    pair<int, int> ans = bst.PredecessorSuccessor(4);
    cout << "Predecessor and Successor of 4: " << ans.first << "\t" << ans.second << endl;
    ans = bst.PredecessorSuccessor(7);
    cout << "Predecessor and Successor of 7: " << ans.first << "\t" << ans.second << endl;
    ans = bst.PredecessorSuccessor(3);
    cout << "Predecessor and Successor of 3: " << ans.first << "\t" << ans.second << endl;
    cout << endl;

    ans = bst.SuccessorPredecessor(4);
    cout << "Predecessor and Successor of 4: " << ans.first << "\t" << ans.second << endl;
    ans = bst.SuccessorPredecessor(7);
    cout << "Predecessor and Successor of 7: " << ans.first << "\t" << ans.second << endl;
    ans = bst.SuccessorPredecessor(3);
    cout << "Predecessor and Successor of 3: " << ans.first << "\t" << ans.second << endl;

    return EXIT_SUCCESS;
}
