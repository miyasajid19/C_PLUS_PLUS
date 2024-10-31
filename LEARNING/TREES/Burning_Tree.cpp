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

    Node *createParentMapping(Node *temp, int target, map<Node *, Node *> &NodeToParent)
    {
        Node *result = nullptr;
        queue<Node *> Queue;
        Queue.push(temp);
        NodeToParent[temp] = nullptr;
        while (!Queue.empty())
        {
            Node *frontNode = Queue.front();
            Queue.pop();

            if (frontNode->value == target)
            {
                result = frontNode;
            }

            if (frontNode->left)
            {
                NodeToParent[frontNode->left] = frontNode;
                Queue.push(frontNode->left);
            }

            if (frontNode->right)
            {
                NodeToParent[frontNode->right] = frontNode;
                Queue.push(frontNode->right);
            }
        }
        return result;
    }

    int BurnTree(Node *temp, map<Node *, Node *> NodeToParent)
    {
        map<Node *, bool> hasBurnt;
        queue<Node *> Queue;
        Queue.push(temp);
        hasBurnt[temp] = true;
        int MinimumTime = 0;
        while (!Queue.empty())
        {
            bool flag = false; // to check if nodes are added in this iteration
            int size = Queue.size();
            for (int i = 0; i < size; i++)
            {
                Node *frontNode = Queue.front();
                Queue.pop();

                if (frontNode->left && !hasBurnt[frontNode->left])
                {
                    flag = true;
                    Queue.push(frontNode->left);
                    hasBurnt[frontNode->left] = true;
                }

                if (frontNode->right && !hasBurnt[frontNode->right])
                {
                    flag = true;
                    Queue.push(frontNode->right);
                    hasBurnt[frontNode->right] = true;
                }

                if (NodeToParent[frontNode] && !hasBurnt[NodeToParent[frontNode]])
                {
                    flag = true;
                    Queue.push(NodeToParent[frontNode]);
                    hasBurnt[NodeToParent[frontNode]] = true;
                }
            }
            if (flag)
            {
                MinimumTime++;
            }
        }
        return MinimumTime;
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

    int Burn_tree(int target)
    {
        map<Node *, Node *> NodeToParent;
        Node *targetNode = createParentMapping(root, target, NodeToParent);
        if (targetNode)
        {
            return BurnTree(targetNode, NodeToParent);
        }
        return -1; // If target node is not found
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

    int target =7;
    cout<<"The minimum time to burn tree is "<<tree.Burn_tree(target)<<" s when set fire for "<<target<<" node."<<endl;

    return EXIT_SUCCESS;
}