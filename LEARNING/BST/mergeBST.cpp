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

public:
    BST()
    {
        root = nullptr;
    }

    void BuildTree()
    {
        int value;
        cout << "Enter Element (enter -1 to stop): " << endl;
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

    // Helper to fill inorder traversal into a vector
    void FillInorder(Node *temp, vector<int> &arr)
    {
        if (temp == nullptr)
            return;
        FillInorder(temp->left, arr);
        arr.push_back(temp->value);
        FillInorder(temp->right, arr);
    }

    // Function to merge two sorted arrays
    vector<int> merge(const vector<int> &arr1, const vector<int> &arr2)
    {
        int i = 0, j = 0;
        vector<int> mergedArr;
        while (i < arr1.size() && j < arr2.size())
        {
            if (arr1[i] < arr2[j])
                mergedArr.push_back(arr1[i++]);
            else
                mergedArr.push_back(arr2[j++]);
        }
        // Append remaining elements if any
        while (i < arr1.size())
            mergedArr.push_back(arr1[i++]);
        while (j < arr2.size())
            mergedArr.push_back(arr2[j++]);
        
        return mergedArr;
    }

    // Function to build a balanced BST from a sorted array
    Node* sortedArrayToBST(const vector<int> &arr, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        Node *node = new Node(arr[mid]);

        node->left = sortedArrayToBST(arr, start, mid - 1);
        node->right = sortedArrayToBST(arr, mid + 1, end);
        return node;
    }

    // Merging two BSTs and returning a new BST as the result
    static BST MergeBST(BST &bst1, BST &bst2)
    {
        vector<int> inorder1, inorder2;
        bst1.FillInorder(bst1.root, inorder1);
        bst2.FillInorder(bst2.root, inorder2);

        // Merge the two inorder traversals
        vector<int> mergedInorder = bst1.merge(inorder1, inorder2);

        // Build a balanced BST from the merged sorted array
        BST result;
        result.root = result.sortedArrayToBST(mergedInorder, 0, mergedInorder.size() - 1);

        return result;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    BST bst1, bst2;

    cout << "Build BST 1:" << endl;
    bst1.BuildTree();

    cout << "Build BST 2:" << endl;
    bst2.BuildTree();

    // Merge the two BSTs
    BST mergedBST = BST::MergeBST(bst1, bst2);

    cout << "\nInorder Traversal of Merged BST: ";
    mergedBST.InorderTraversal();

    cout << "\n\nLevel Order Display of Merged BST:" << endl;
    mergedBST.LevelOrderDisplay();

    return EXIT_SUCCESS;
}
