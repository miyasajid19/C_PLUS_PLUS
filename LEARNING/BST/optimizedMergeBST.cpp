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

    void convertToLinkedList(Node *temp, Node *&head)
    {
        if (temp == nullptr)
            return;

        convertToLinkedList(temp->right, head);
        temp->right = head;
        if (head != nullptr)
        {
            head->left = temp;
        }
        head = temp;
        convertToLinkedList(temp->left, head);
    }

    Node *mergeLinkedList(Node *head1, Node *head2)
    {
        Node *head = nullptr;
        Node *tail = nullptr;

        while (head1 != nullptr && head2 != nullptr)
        {
            Node *next;
            if (head1->value < head2->value)
            {
                next = head1;
                head1 = head1->right;
            }
            else
            {
                next = head2;
                head2 = head2->right;
            }

            if (head == nullptr)
            {
                head = next;
                tail = next;
            }
            else
            {
                tail->right = next;
                next->left = tail;
                tail = next;
            }
        }

        while (head1 != nullptr)
        {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }

        while (head2 != nullptr)
        {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }

        return head;
    }

    int countNodes(Node *head)
    {
        int count = 0;
        while (head != nullptr)
        {
            count++;
            head = head->right;
        }
        return count;
    }

    Node *sortedLinkedListToBST(Node *&head, int n)
    {
        if (n <= 0 || head == nullptr)
            return nullptr;

        Node *left = sortedLinkedListToBST(head, n / 2);
        Node *root = head;
        root->left = left;
        head = head->right;
        root->right = sortedLinkedListToBST(head, n - n / 2 - 1);

        return root;
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

    void Merge(BST &bst1, BST &bst2)
    {
        Node *list1 = nullptr;
        bst1.convertToLinkedList(bst1.root, list1);
        list1->left = nullptr;  // Ensure the leftmost node's left pointer is null

        Node *list2 = nullptr;
        bst2.convertToLinkedList(bst2.root, list2);
        list2->left = nullptr;  // Ensure the leftmost node's left pointer is null

        Node *mergedList = mergeLinkedList(list1, list2);

        int nodeCount = countNodes(mergedList);
        root = sortedLinkedListToBST(mergedList, nodeCount);
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

    BST mergedBST;
    mergedBST.Merge(bst1, bst2);

    cout << "\nInorder Traversal of Merged BST: ";
    mergedBST.InorderTraversal();

    cout << "\n\nLevel Order Display of Merged BST:" << endl;
    mergedBST.LevelOrderDisplay();

    return EXIT_SUCCESS;
}
