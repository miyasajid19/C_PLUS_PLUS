#include <iostream>
#include <cstdlib>
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
    void BuildTreeFromLevel()
    {
        queue<Node *> q;
        int value;
        cout<<"enter the value for root : "<<endl;
        cin>>value;
        root=new Node(value);
        q.push(root);
        while(not q.empty())
        {
            Node* temp=q.front();
            q.pop();
            int leftValue;
            cout<<"enter left value  for "<<temp->value<<endl;
            cin>>leftValue;
            if(leftValue!=-1)
            {
                temp->left=new Node(leftValue);
                q.push(temp->left);
            }
            int rightValue;
            cout<<"enter right value  for "<<temp->value<<endl;
            cin>>rightValue;
            if(rightValue!=-1)
            {
                temp->right=new Node(rightValue);
                q.push(temp->right);
            }
        }
    }
};

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    Tree tree;
    // tree.BuildTree();
    tree.BuildTreeFromLevel();
    cout << endl;
    tree.LevelOrderDisplay();
    cout << endl
         << "Inorder :: " << endl;
    tree.DisplayInorder();
    cout << endl
         << "Pre-order :: " << endl;
    tree.DisplayPreorder();
    cout << endl
         << "Post-order :: " << endl;
    tree.DisplayPostorder();
    return EXIT_SUCCESS;
}