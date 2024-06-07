#include <iostream>
#include <queue>
using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;

    TNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode *addNode(TNode *root, int value)
{
    if (root == NULL)
    {
        return new TNode(value);
    }
    queue<TNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TNode *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = new TNode(value);
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = new TNode(value);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
}

TNode *findNode(TNode *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->data == value)
        return root;
    TNode *left = findNode(root->left, value);
    if (left != NULL)
        return left;
    return findNode(root->right, value);
}

void displayChild(TNode *node)
{
    if (node == NULL)
    {
        cout << "Node not found" << endl;
        return;
    }
    cout << "Left Child: " << (node->left ? to_string(node->left->data) : "NULL") << endl;
    cout << "Right Child: " << (node->right ? to_string(node->right->data) : "NULL") << endl;
}

void displayDescendants(TNode *node)
{
    if (node == NULL)
    {
        cout << "Node not found" << endl;
        return;
    }
    cout << "Descendants: ";
    queue<TNode *> q;
    q.push(node);
    while (!q.empty())
    {
        TNode *temp = q.front();
        q.pop();
        if (temp != node)
        {
            cout << temp->data << " ";
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    cout << endl;
}

int main()
{
    TNode *root = NULL;
    int choice, value, nodeValue;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Add Node" << endl;
        cout << "2. Pre-Order Traversal" << endl;
        cout << "3. In-Order Traversal" << endl;
        cout << "4. Post-Order Traversal" << endl;
        cout << "5. Display Child Nodes" << endl;
        cout << "6. Display Descendant Nodes" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            root = addNode(root, value);
            break;
        case 2:
            preOrder(root);
            cout << endl;
            break;
        case 3:
            inOrder(root);
            cout << endl;
            break;
        case 4:
            postOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Enter node value to display children: ";
            cin >> nodeValue;
            displayChild(findNode(root, nodeValue));
            break;
        case 6:
            cout << "Enter node value to display descendants: ";
            cin >> nodeValue;
            displayDescendants(findNode(root, nodeValue));
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}