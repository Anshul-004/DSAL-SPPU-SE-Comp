/* Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -
i. Insert new node,
ii. Find number of nodes in longest path from root,
iii. Minimum data value found in the tree,
iv. Change a tree so that the roles of the left and right pointers are swapped at every node,
v. Search a value. */

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    void getData(Node *&root);
    Node *insertNode(Node *&root, int d);
    void display(Node *&root);
    void minNode(Node *&root);
    void searchNode(Node *&root, int key);
    int longestPath(Node *&root);
    Node *swapPtr(Node *&root);
};

Node *BST ::insertNode(Node *&root, int d)
{
    if (root == NULL) // 1st case, when no tree is there, root is declared as NULL
    {
        root = new Node(d);
        return root;
    }
    else
    {
        if (d < root->data) // if input data is less than root
        {
            root->left = insertNode(root->left, d);
        }
        if (d > root->data) // if input data is more than root
        {
            root->right = insertNode(root->right, d);
        }
        return root;
    }
}

void BST ::getData(Node *&root)
{
    int ip;
    cout << "Enter Data to insert in BST " << endl;
    cin >> ip;
    insertNode(root, ip);
}

void BST ::display(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        else
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

void BST::minNode(Node *&root)
{
    int min = 100, mint;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        mint = temp->data;
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }

        if (min > mint)
        {
            min = mint;
        }
    }
    cout << "Minimum Node Value is : " << min;
}

void BST::searchNode(Node *&root, int key)
{
    int kt;
    bool flag = false;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        kt = temp->data;
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }

        if (kt == key)
        {
            flag = true;
            break; // exit loop as soon as condition is true
        }
    }

    if (flag)
        cout << "Element Found in BST" << endl;

    else
        cout << "Element Not Found in BST" << endl;
}

int BST ::longestPath(Node *&root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftPath = longestPath(root->left);
    int rightPath = longestPath(root->right);

    return max(leftPath, rightPath) + 1;
}
Node *BST::swapPtr(Node *&root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapPtr(root->left);
    swapPtr(root->right);

    return root;
}
int main()
{
    BST b;
    Node *root = NULL;
    int ch, key;
    cout << "*** DSAL PRACTICAL - 04 (B-6) ***" << endl;
    cout << "*** Prepared By - Anshul Singh ***\n"
         << endl;

    while (1)
    {
        cout << "\nMENU : \n1.Insert Node\n2.Number of nodes in longest path\n3.Minimum Data\n4.Swap Left to Right and Vice Versa\n5.Search Value\n6.Display\n7.Exit" << endl;
        cout << "\nEnter Your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.getData(root);
            break;
        case 2:
            cout << "Longest path is : ";
            cout << b.longestPath(root);
            break;
        case 3:
            b.minNode(root);
            break;
        case 4:
            b.swapPtr(root);
            cout<<"Swapped Left <-> Right "<<endl;
            break;
        case 5:
            cout << "Enter Value to Search " << endl;
            cin >> key;
            b.searchNode(root, key);
            break;
        case 6:
            b.display(root);
            break;

        default:
            cout << "\n\t***Terminated Successfully***" << endl;
            exit(0);
        }
    }
    return 0;
}