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
    void kth_smallest_intution1(Node *temp, queue<int> &Queue)
    {
        if (temp == nullptr)
            return;

        kth_smallest_intution1(temp->left, Queue);
        Queue.push(temp->value);
        kth_smallest_intution1(temp->right, Queue);
    }

    int kth_smallest(Node *temp, int &i, int k)
    {
        if (temp == nullptr)
            return INT_MIN;

        int left = kth_smallest(temp->left, i, k);
        if (left != INT_MIN)
        {
            return left;
        }
        i++;
        if (i == k)
            return temp->value;

        return kth_smallest(temp->right,i,k);
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
    int Kth_smallest(int k)
    {
        queue<int> Queue;
        kth_smallest_intution1(root, Queue);
        if (Queue.empty() or Queue.size() < k)
            return INT_MIN;

        for (int i = 0; i < k - 1; i++)
            Queue.pop();

        return Queue.front();
    }
    int kth_smallest_Optimum(int k)
    {
        int i=0;
        return kth_smallest(root,i,k);
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
    cout << "3rd smallest element :::  " << bst.Kth_smallest(3) << endl;
    cout << "5th smallest element :::  " << bst.Kth_smallest(5) << endl;
    cout << "1st smallest element :::  " << bst.Kth_smallest(1) << endl;
    cout << "10th smallest element  :::  " << bst.Kth_smallest(10) << endl;
 cout<<endl;
    cout << "3rd smallest element :::  " << bst.kth_smallest_Optimum(3) << endl;
    cout << "5th smallest element :::  " << bst.kth_smallest_Optimum(5) << endl;
    cout << "1st smallest element :::  " << bst.kth_smallest_Optimum(1) << endl;
    cout << "10th smallest element  :::  " << bst.kth_smallest_Optimum(10) << endl;
    return EXIT_SUCCESS;
}
