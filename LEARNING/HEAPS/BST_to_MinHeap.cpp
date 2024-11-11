#include <iostream>
#include <vector>
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

    Node *add(Node *temp, int value)
    {
        if (temp == nullptr)
            return new Node(value);

        if (value > temp->value)
            temp->right = add(temp->right, value);
        else
            temp->left = add(temp->left, value);

        return temp;
    }

    void inorderTraversal(Node *temp, vector<int> &inorderValues)
    {
        if (temp == nullptr)
            return;
        inorderTraversal(temp->left, inorderValues);
        inorderValues.push_back(temp->value);
        inorderTraversal(temp->right, inorderValues);
    }

    void fillTreePreorder(Node *temp, vector<int> &inorderValues, int &index)
    {
        if (temp == nullptr)
            return;

        // Assign the next value in sorted order to the current node
        temp->value = inorderValues[index++];
        
        // Traverse left and right subtree in preorder fashion
        fillTreePreorder(temp->left, inorderValues, index);
        fillTreePreorder(temp->right, inorderValues, index);
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
        this->root = nullptr;
    }

    void insert(int value)
    {
        root = add(root, value);
    }

    void convertToMinHeap()
    {
        vector<int> inorderValues;
        inorderTraversal(root, inorderValues); // Get sorted values in inorder
        int index = 0;
        fillTreePreorder(root, inorderValues, index); // Fill tree in preorder with sorted values
    }

    void displayInorder()
    {
        vector<int> inorderValues;
        inorderTraversal(root, inorderValues);
        for (int value : inorderValues)
            cout << value << '\t';
        cout << endl;
    }

    void displayPreorder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->value << '\t';
        displayPreorder(node->left);
        displayPreorder(node->right);
    }

    void displayPreorder()
    {
        displayPreorder(root);
        cout << endl;
    }
    void display_level()
    {
        levelOrderTraversal(root);
    }
};

int main()
{
    BST bst;
    bst.insert(5);

    bst.insert(3);
    bst.insert(8);
    
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(9);

    cout << "BST Inorder before conversion (sorted): \n";
    bst.display_level();

    bst.convertToMinHeap();

    cout << "BST Inorder after conversion to min-heap structure: \n";
    bst.display_level();

    cout << "BST Preorder after conversion to min-heap structure: \n";
    bst.display_level();

    return EXIT_SUCCESS;
}
