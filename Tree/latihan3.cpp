#include <iostream>
#include <cstdlib>
using namespace std;

struct nodeTree
{
    nodeTree *left;
    nodeTree *right;
    int data;
};
nodeTree *root;

void BinarySearchTree()
{
    root = NULL;
}

bool isEmpty()
{
    if (root == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void insert(int d)
{
    nodeTree *t = new nodeTree;
    nodeTree *parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;

    if (isEmpty())
        root = t;
    else
    {

        nodeTree *current;
        current = root;

        while (current)
        {
            parent = current;
            if (t->data > current->data)
                current = current->right;
            else
                current = current->left;
        }

        if (t->data < parent->data)
            parent->left = t;
        else
            parent->right = t;
    }
}

int maxDepth(nodeTree *node)
{
    if (node == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void inorder(nodeTree *p)
{
    if (p != NULL)
    {
        if (p->left)
            inorder(p->left);
        cout << " " << p->data << " ";
        if (p->right)
            inorder(p->right);
    }
    else
        return;
}

void print_inorder()
{
    inorder(root);
}

int main()
{
    nodeTree *pohong;
  
    insert(5);
    insert(9);
    insert(3);
    insert(4);
    insert(2);
    insert(4);

    cout << "Hasil Inorder Tree adalah ";
    print_inorder();
    cout << endl;

    cout << "Kedalaman Tree adalah ";
    maxDepth(pohong);
    cout << endl;

    return 0;
}