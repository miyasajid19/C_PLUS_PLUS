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
    vector<int> zig_zag_traversal(Node *temp)
    {
        vector<int> result;
        if (temp == nullptr)
            return result;

        queue<Node *> Queue;
        Queue.push(temp);

        bool is_leftToRight = true;
        while (not Queue.empty())
        {
            int size = Queue.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++)
            {
                Node *FrontNode = Queue.front();
                Queue.pop();

                // insertion
                int index = is_leftToRight ? i : size - 1 - i;
                ans[index] = FrontNode->value;
                if (FrontNode->left)
                    Queue.push(FrontNode->left);
                if (FrontNode->right)
                    Queue.push(FrontNode->right);
            }
            // change the direction
            is_leftToRight = !is_leftToRight;

            for (auto i : ans)
            {
                result.push_back(i);
            }
        }
        return result;
    }
    // boundary wise traversal
    void Traverse_Left(Node *temp, vector<int> &ans)
    {
        if ((temp == nullptr) or ((temp->left == nullptr) and (temp->right == nullptr)))
            return;

        ans.push_back(temp->value);
        if (temp->left)
        {
            Traverse_Left(temp->left, ans);
        }
        if (temp->right)
        {
            Traverse_Left(temp->right, ans);
        }
    }
    void Traverse_left(Node *temp, vector<int> &ans)
    {
        if (temp == nullptr)
            return;

        if (temp->left == nullptr and temp->right == nullptr)
            ans.push_back(temp->value);

        Traverse_left(temp->left, ans);
        Traverse_left(temp->right, ans);
    }
    void Traverse_Right(Node *temp, vector<int> &ans)
    {
        if ((temp == nullptr) or ((temp->left == nullptr) and (temp->right == nullptr)))
        {
            return;
        }
        if (temp->right)
        {
            Traverse_Right(temp->right, ans);
        }
        else
        {
            Traverse_Right(temp->left, ans);
        }
        ans.push_back(temp->value);
    }
    vector<int> boundary_wise_traversal(Node *temp)
    {
        vector<int> ans;
        if (temp == nullptr)
            return ans;
        ans.push_back(temp->value);
        // traverse left nodes
        Traverse_Left(temp->left, ans);

        // traverse left node
        Traverse_left(temp->left, ans);
        Traverse_left(temp->right, ans);

        // traverse reverse wise right node
        Traverse_Right(temp->right, ans);

        return ans;
    }

    // vertical order traversal
    vector<int> vertical_order_traversal(Node *temp)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> Queue;
        vector<int> ans;
        if (temp == nullptr)
            return ans;

        Queue.push(make_pair(temp, make_pair(0, 0)));

        while (not Queue.empty())
        {
            pair<Node *, pair<int, int>> temp1 = Queue.front();
            Queue.pop();
            Node *FrontNode = temp1.first;
            int horizontalDistance = temp1.second.first;
            int level = temp1.second.second;
            nodes[horizontalDistance][level].push_back(FrontNode->value);

            if (FrontNode->left)
                Queue.push(make_pair(FrontNode->left, make_pair(horizontalDistance - 1, level + 1)));

            if (FrontNode->right)
                Queue.push(make_pair(FrontNode->right, make_pair(horizontalDistance + 1, level + 1)));
        }
        for (auto x : nodes)
        {
            for (auto y : x.second)
            {
                for (auto x : y.second)
                {
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }

    // Top View
    vector<int> topview(Node *temp)
    {
        vector<int> ans;
        if (temp == nullptr)
            return ans;

        map<int, int> TopNode;
        queue<pair<Node *, int>> Queue;

        Queue.push(make_pair(temp, 0));

        while (!Queue.empty())
        {
            pair<Node *, int> temp1 = Queue.front();
            Queue.pop(); // Remove the front element after processing
            Node *FrontNode = temp1.first;
            int horizontalDistance = temp1.second;

            if (TopNode.find(horizontalDistance) == TopNode.end())
            {
                TopNode[horizontalDistance] = FrontNode->value;
            }

            if (FrontNode->left)
                Queue.push(make_pair(FrontNode->left, horizontalDistance - 1));

            if (FrontNode->right)
                Queue.push(make_pair(FrontNode->right, horizontalDistance + 1));
        }

        for (auto x : TopNode)
        {
            ans.push_back(x.second);
        }

        return ans;
    }

    // bottom View
    vector<int> bottomview(Node *temp)
    {
        vector<int> ans;
        if (temp == nullptr)
            return ans;

        map<int, int> TopNode;
        queue<pair<Node *, int>> Queue;

        Queue.push(make_pair(temp, 0));

        while (!Queue.empty())
        {
            pair<Node *, int> temp1 = Queue.front();
            Queue.pop(); // Remove the front element after processing
            Node *FrontNode = temp1.first;
            int horizontalDistance = temp1.second;
            TopNode[horizontalDistance] = FrontNode->value;

            if (FrontNode->left)
                Queue.push(make_pair(FrontNode->left, horizontalDistance - 1));

            if (FrontNode->right)
                Queue.push(make_pair(FrontNode->right, horizontalDistance + 1));
        }

        for (auto x : TopNode)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
    // left view
    // Function to return the list of the elements of the left view of the binary tree
    void solveleft(Node *temp, vector<int> &ans, int level)
    {
        // Base case
        if (temp == nullptr)
            return;

        // If we enter a new level
        if (level == ans.size())
            ans.push_back(temp->value);

        // Recursively call for left and right subtrees
        solveleft(temp->left, ans, level + 1);
        solveleft(temp->right, ans, level + 1);
    }

    vector<int> leftview(Node *temp)
    {
        vector<int> ans;
        solveleft(temp, ans, 0);
        return ans;
    }
    // right view
    //  Function to return the list of the elements of the left view of the binary tree
    void solveright(Node *temp, vector<int> &ans, int level)
    {
        // Base case
        if (temp == nullptr)
            return;

        // If we enter a new level
        if (level == ans.size())
            ans.push_back(temp->value);

        // Recursively call for left and right subtrees
        solveright(temp->right, ans, level + 1);
        solveright(temp->left, ans, level + 1);
    }

    vector<int> rightview(Node *temp)
    {
        vector<int> ans;
        solveright(temp, ans, 0);
        return ans;
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

    void ZigZagTraversal()
    {
        vector<int> result = zig_zag_traversal(root);
        for (auto i : result)
        {

            cout << i << " ";
        }
        cout << endl;
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
    cout << endl;
    cout << "Zig Zag Traversal ::: ";
    tree.ZigZagTraversal();
    return EXIT_SUCCESS;
}