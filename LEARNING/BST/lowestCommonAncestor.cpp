#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
    Node *root;

    Node *BuildBST(Node *temp, int value) {
        if (temp == nullptr)
            return new Node(value);

        if (value > temp->value)
            temp->right = BuildBST(temp->right, value);
        else
            temp->left = BuildBST(temp->left, value);

        return temp;
    }

    void inOrderTraversal(Node *temp) {
        if (temp == nullptr)
            return;
        inOrderTraversal(temp->left);
        cout << temp->value << "\t";
        inOrderTraversal(temp->right);
    }

    void levelOrderTraversal(Node *temp) {
        if (temp == nullptr)
            return;

        queue<Node *> q;
        q.push(temp);
        q.push(nullptr); // To mark the end of a level

        while (!q.empty()) {
            Node *temp1 = q.front();
            q.pop();

            if (temp1 == nullptr) {
                cout << endl;
                if (!q.empty())
                    q.push(nullptr);
            } else {
                cout << temp1->value << "\t";
                if (temp1->left)
                    q.push(temp1->left);
                if (temp1->right)
                    q.push(temp1->right);
            }
        }
    }

    Node* LCA(Node *temp, int leftvalue, int rightvalue) {
        if (temp == nullptr)
            return nullptr;

        // Check left subtree if both values are less than the current node value
        if (temp->value > leftvalue && temp->value > rightvalue) 
            return LCA(temp->left, leftvalue, rightvalue);

        // Check right subtree if both values are greater than the current node value
        if (temp->value < leftvalue && temp->value < rightvalue) 
            return LCA(temp->right, leftvalue, rightvalue);

        // `temp` is the LCA if it is between `leftvalue` and `rightvalue`
        return temp;
    }

public:
    BST() {
        root = nullptr;
    }

    void BuildTree() {
        int value;
        cout << "Enter Element " << endl;
        cin >> value;
        while (value != -1) {
            root = BuildBST(root, value);
            cout << "Enter Element :: " << endl;
            cin >> value;
        }
    }

    void InorderTraversal() {
        inOrderTraversal(root);
    }

    void LevelOrderDisplay() {
        levelOrderTraversal(root);
    }

    int LowestCommonAncestor(int leftvalue, int rightvalue) {
        Node *x = LCA(root, leftvalue, rightvalue);
        if (x == nullptr)
            return INT_MIN;
        else
            return x->value;
    }
};

int main() {
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
    for (int i =0;i<4;i++)
    {

    cout<<"enter left value"<<endl;
    int leftvalue;
    cin>>leftvalue;
    cout<<"enter right value"<<endl;
    int rightvalue;
    cin>>rightvalue;
    cout << "Lowest Common Ancestor of "<<leftvalue <<" and "<<rightvalue<<": " << bst.LowestCommonAncestor(leftvalue, rightvalue) << endl;
    }
    return EXIT_SUCCESS;
}
