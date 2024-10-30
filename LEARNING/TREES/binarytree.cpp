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

    void displayinorder(Node *temp)
    {
        if (temp == nullptr)
            return;
        displayinorder(temp->left);
        cout << temp->value << " ";
        displayinorder(temp->right);
    }

    void displaypreorder(Node *temp)
    {
        if (temp == nullptr)
            return;
        cout << temp->value << " ";
        displaypreorder(temp->left);
        displaypreorder(temp->right);
    }

    void displaypostorder(Node *temp)
    {
        if (temp == nullptr)
            return;
        displaypostorder(temp->left);
        displaypostorder(temp->right);
        cout << temp->value << " ";
    }
    void no_of_leafNodes(Node *temp, int &count)
    {
        if (temp == nullptr)
        {
            return;
        }
        no_of_leafNodes(temp->left, count);
        if (temp->left == nullptr and temp->right == nullptr)
            count++;
        no_of_leafNodes(temp->right, count);
    }

    // Inorder traversal using iteration
    void inorderIterative(Node *temp)
    {
        stack<Node *> s;
        Node *current = temp;

        while (current != nullptr || !s.empty())
        {
            // Traverse left subtree as deep as possible
            while (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }

            // Pop the node and process it
            current = s.top();
            s.pop();
            cout << current->value << " ";

            // Visit the right subtree
            current = current->right;
        }
    }

    // Preorder traversal using iteration
    void preorderIterative(Node *temp)
    {
        if (temp == nullptr)
            return;

        stack<Node *> s;
        s.push(temp);

        while (!s.empty())
        {
            Node *current = s.top();
            s.pop();
            cout << current->value << " ";

            // Push right child first so that left is processed first
            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);
        }
    }

    // Postorder traversal using one stack
    void postorderIterative(Node *temp)
    {
        if (temp == nullptr)
            return;

        stack<Node *> s;
        Node *current = temp;
        Node *lastVisited = nullptr;

        while (current != nullptr || !s.empty())
        {
            // Traverse to the leftmost node
            if (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }
            else
            {
                Node *peekNode = s.top();

                // If the right subtree exists and was not visited yet
                if (peekNode->right != nullptr && lastVisited != peekNode->right)
                {
                    current = peekNode->right;
                }
                else
                {
                    // Visit the node
                    cout << peekNode->value << " ";
                    lastVisited = s.top();
                    s.pop();
                }
            }
        }
    }
    int height(Node *temp)
    {
        if (temp == nullptr)
            return 0;

        return max(height(temp->left), height(temp->right)) + 1;
    }
    int diameter(Node *temp)
    {
        if (temp == nullptr)
            return 0;
        int op1 = diameter(temp->left);
        int op2 = diameter(temp->right);
        int op3 = height(temp->left) + height(temp->right) + 1;
        return max(op1, max(op2, op3));
    }
    pair<int, int> optimized_diameter(Node *temp)
    {
        if (temp == nullptr)
            return make_pair(0, 0);
        pair<int, int> left = optimized_diameter(temp->left);
        pair<int, int> right = optimized_diameter(temp->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        return make_pair(max(op1, max(op2, op3)), max(left.second, right.second) + 1);
    }
    bool is_balanced(Node *temp)
    {
        // A null tree is balanced
        if (temp == nullptr)
            return true;

        // Get the height of the left and right subtrees
        int leftHeight = height(temp->left);
        int rightHeight = height(temp->right);

        // Check if the height difference is more than 1
        if (abs(leftHeight - rightHeight) > 1)
            return false;

        // Recursively check for left and right subtrees
        bool leftBalanced = is_balanced(temp->left);
        bool rightBalanced = is_balanced(temp->right);

        // If both left and right subtrees are balanced, then the tree is balanced
        return leftBalanced && rightBalanced;
    }
    pair<bool, int> is_balanced_optimezed(Node *temp)
    {
        // A null tree is balanced with height 0
        if (temp == nullptr)
            return make_pair(true, 0);

        // Check the left and right subtrees
        pair<bool, int> left = is_balanced_optimezed(temp->left);
        pair<bool, int> right = is_balanced_optimezed(temp->right);

        // Get the balanced status and height for both subtrees
        bool leftBalanced = left.first;
        bool rightBalanced = right.first;

        // Calculate the height difference
        int diff_height = abs(left.second - right.second);

        // If the height difference is more than 1, the tree is not balanced
        bool currentBalanced = (diff_height <= 1);

        // The current tree is balanced if both subtrees are balanced and the height difference is <= 1
        bool isBalanced = leftBalanced && rightBalanced && currentBalanced;

        // Height of the current node is the maximum of the two subtree heights plus 1
        int height = max(left.second, right.second) + 1;

        return make_pair(isBalanced, height);
    }
    pair<bool, int> is_sum_tree(Node *temp)
    {
        if (temp == nullptr)
        {
            return make_pair(true, 0);
        }
        if (temp->left == nullptr and temp->right == nullptr)
        {
            return make_pair(true, temp->value);
        }
        pair<bool, int> leftAns = is_sum_tree(temp->left);
        pair<bool, int> rightAns = is_sum_tree(temp->right);
        bool isleftSumTree = leftAns.first;
        bool isrightSumTree = rightAns.first;
        bool condition = temp->value == leftAns.second + rightAns.second;
        pair<bool, int> ans;
        if (isleftSumTree and isrightSumTree and condition)
        {
            ans.first = true;
            // ans.second=2*temp->value;
            ans.second = leftAns.second + rightAns.second + temp->value;
        }
        else
        {
            ans.first = false;
        }
        return ans;
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
    void Traverse_Leaf(Node *temp, vector<int> &ans)
    {
        if (temp == nullptr)
            return;

        if (temp->left == nullptr and temp->right == nullptr)
            ans.push_back(temp->value);

        Traverse_Leaf(temp->left, ans);
        Traverse_Leaf(temp->right, ans);
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

        // traverse leaf node
        Traverse_Leaf(temp->left, ans);
        Traverse_Leaf(temp->right, ans);

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

    void DisplayInorder()
    {
        displayinorder(root);
    }

    void DisplayPreorder()
    {
        displaypreorder(root);
    }

    void DisplayPostorder()
    {
        displaypostorder(root);
    }
    void DisplayInorderIterative()
    {
        inorderIterative(root);
    }

    void DisplayPreorderIterative()
    {
        preorderIterative(root);
    }

    void DisplayPostorderIterative()
    {
        postorderIterative(root);
    }
    void BuildTreeFromLevel()
    {
        queue<Node *> q;
        int value;
        cout << "enter the value for root : " << endl;
        cin >> value;
        root = new Node(value);
        q.push(root);
        while (not q.empty())
        {
            Node *temp = q.front();
            q.pop();
            int leftValue;
            cout << "enter left value  for " << temp->value << endl;
            cin >> leftValue;
            if (leftValue != -1)
            {
                temp->left = new Node(leftValue);
                q.push(temp->left);
            }
            int rightValue;
            cout << "enter right value  for " << temp->value << endl;
            cin >> rightValue;
            if (rightValue != -1)
            {
                temp->right = new Node(rightValue);
                q.push(temp->right);
            }
        }
    }
    int NoOfLeafNodes()
    {
        int count = 0;
        no_of_leafNodes(root, count);
        return count;
    }
    int Height()
    {
        return height(root);
    }
    int Diameter()
    {
        return diameter(root);
    }
    int oprimizedDiameter()
    {
        return optimized_diameter(root).first;
    }
    bool isBalanced()
    {
        return is_balanced(root);
    }
    bool isBalanced_Optimized()
    {
        return is_balanced_optimezed(root).first;
    }
    bool isSumTree()
    {
        return is_sum_tree(root).first;
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
    void BoundaryWiseTraversal()
    {
        vector<int> result = boundary_wise_traversal(root);
        for (auto x : result)
            cout << x << " ";
    }
    void VertivalOrderTraversal()
    {
        vector<int> result = vertical_order_traversal(root);
        for (auto x : result)
            cout << x << " ";
    }
    void TopView()
    {
        vector<int> result = topview(root);
        for (auto x : result)
            cout << x << " ";
    }
    void BottomView()
    {
        vector<int> result = bottomview(root);
        for (auto x : result)
            cout << x << " ";
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
    cout << endl
         << "Inorder :: " << endl;
    tree.DisplayInorder();
    cout << endl
         << "Inorder :: " << endl;
    tree.DisplayInorderIterative();
    cout << endl
         << "Pre-order :: " << endl;
    tree.DisplayPreorder();
    cout << endl
         << "Pre-order :: " << endl;
    tree.DisplayPreorderIterative();
    cout << endl
         << "Post-order :: " << endl;
    tree.DisplayPostorder();
    cout << endl
         << "Post-order :: " << endl;
    tree.DisplayPostorderIterative();
    cout << endl;
    cout << "No. of leaf nodes :: " << tree.NoOfLeafNodes() << endl;
    cout << "Height of tree :: " << tree.Height() << endl;
    cout << "Is balanced?? :: " << tree.isBalanced() << endl;
    cout << "Is Sum tree?? :: " << tree.isSumTree() << endl;
    cout << "Is balanced (optimized)?? :: " << tree.isBalanced_Optimized() << endl;
    cout << "Diameter of tree :: " << tree.Diameter() << endl;
    cout << "Optimized Diameter of tree :: " << tree.oprimizedDiameter() << endl;
    cout << "Zig Zag Traversal ::: ";
    tree.ZigZagTraversal();
    cout << "Boundary wise Traversal ::: ";
    tree.BoundaryWiseTraversal();
    cout << endl;
    cout << "Vertical Order Traversal ::: ";
    tree.VertivalOrderTraversal();
    cout << endl;
    cout << "Top View ::: ";
    tree.TopView();
    cout << endl;
    cout << "Bottom View ::: ";
    tree.BottomView();
    cout << endl;
    return EXIT_SUCCESS;
}
// 1
// 2
// 4
// -1
// -1
// 5
// -1
// -1
// 3
// 6
// -1
// -1
// 7
// -1
// -1