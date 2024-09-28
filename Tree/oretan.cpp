#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef struct tree *pohon;
/* Deklarasi dari tree dengan menggunakan linked list */
struct tree
{
    char info;
    pohon kiri;
    pohon kanan;
};
/* Fungsi untuk membuat simpul yang pertama */
pohon baru(char hrf)
{
    pohon br;
    br = (pohon)malloc(sizeof(struct tree));
    br->info = hrf;
    br->kiri = NULL;
    br->kanan = NULL;
    return (br);
}

void sisip(pohon ph, pohon sp)
{
    pohon P, Q;
    P = ph;
    Q = ph;
    while ((sp->info != ph->info) && (Q != NULL))
    {
        P = Q;
        if (sp->info < P->info)
            Q = P->kiri;
        else
            Q = P->kanan;
    }
    if (sp->info == P->info)
        printf("Sudah ada");
    else if (sp->info < P->info)
        P->kiri = sp;
    else
        P->kanan = sp;
}
/*
Fungsi-fungsi untuk metode traversal secara rekurs
*/
void preorder(pohon ph)
{
    if (ph != NULL)
    {
        printf("%c ", ph->info);
        preorder(ph->kiri);
        preorder(ph->kanan);
    }
}
void inorder(pohon ph)
{
    if (ph != NULL)
    {
        inorder(ph->kiri);
        printf("%c ", ph->info);
        inorder(ph->kanan);
    }
}
void postorder(pohon ph)
{
    if (ph != NULL)
    {
        postorder(ph->kiri);
        postorder(ph->kanan);
        printf("%c ", ph->info);
    }
}
int main()
{
    int j = 0;
    char input, jawab[2];
    pohon br, ssp;
    while (1)
    {
        printf("Ketikkan huruf :");
        scanf("%c", &input);
        fflush(stdin);
        if (j == 0)
            br = baru(input);
        else
        {
            ssp = baru(input);
            sisip(br, ssp);
        }
        printf("Ada data lagi(y/t):");
        scanf("%s", &jawab);
        fflush(stdin);
        if ((strcmp(jawab, "Y") == 0) || (strcmp(jawab, "y") == 0))
        {
            j++;
            continue;
        }
        else if ((strcmp(jawab, "T") == 0) || (strcmp(jawab, "t") == 0)) break;
    }
    preorder(br);
    printf("\n");
    inorder(br);
    printf("\n");
    postorder(br);

    return 0;
}


/*#include <iostream>
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

bool isEmpty();
void print_inorder();
void inorder(nodeTree *);
void print_preorder();
void preorder(nodeTree *);
void print_postorder();
void postorder(nodeTree *);
void insert(int);
void remove(int);


bool isEmpty()
{
    return root == NULL;
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

void remove(int d)
{
    //Locate the element
    bool found = false;
    if (isEmpty())
    {
        cout << " This Tree is empty! " << endl;
        return;
    }

    nodeTree *current;
    nodeTree *parent;
    current = root;

    while (current != NULL)
    {
        if (current->data == d)
        {
            found = true;
            break;
        }
        else
        {
            parent = current;
            if (d > current->data)
                current = current->right;
            else
                current = current->left;
        }
    }
    if (!found)
    {
        cout << " Data not found! " << endl;
        return;
    }

    // Node dengan single child
    if ((current->left == NULL && current->right != NULL) || (current->left != NULL && current->right == NULL))
    {
        if (current->left == NULL && current->right != NULL)
        {
            if (parent->left == current)
            {
                parent->left = current->right;
                delete current;
            }
            else
            {
                parent->right = current->right;
                delete current;
            }
        }
        else
        {
            if (parent->left == current)
            {
                parent->left = current->left;
                delete current;
            }
            else
            {
                parent->right = current->left;
                delete current;
            }
        }
        return;
    }

    // node tidak mempunyai child node
    if (current->left == NULL && current->right == NULL)
    {
        if (parent->left == current)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete current;
        return;
    }

    //Node dengan 2 child node
    // ganti node dengan nilai terkecil di subtree bagain kanan
    if (current->left != NULL && current->right != NULL)
    {
        nodeTree *temp;
        temp = current->right;
        if ((temp->left == NULL) && (temp->right == NULL))
        {
            current = temp;
            delete temp;
            current->right = NULL;
        }
        else
        {

            if ((current->right)->left != NULL)
            {
                nodeTree *lcurrent;
                nodeTree *lcurrp;
                lcurrp = current->right;
                lcurrent = (current->right)->left;
                while (lcurrent->left != NULL)
                {
                    lcurrp = lcurrent;
                    lcurrent = lcurrent->left;
                }
                current->data = lcurrent->data;
                delete lcurrent;
                lcurrp->left = NULL;
            }
            else
            {
                nodeTree *tmp2;
                tmp2 = current->right;
                current->data = tmp2->data;
                current->right = tmp2->right;
                delete tmp2;
            }
        }
        return;
    }
}

void print_inorder()
{
    inorder(root);
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

void print_preorder()
{
    preorder(root);
}

void preorder(nodeTree *p)
{
    if (p != NULL)
    {
        cout << " " << p->data << " ";
        if (p->left)
            preorder(p->left);
        if (p->right)
            preorder(p->right);
    }
    else
        return;
}

void print_postorder()
{
    postorder(root);
}

void postorder(nodeTree *p)
{
    if (p != NULL)
    {
        if (p->left)
            postorder(p->left);
        if (p->right)
            postorder(p->right);
        cout << " " << p->data << " ";
    }
    else
        return;
}

int main()
{
    int ch, tmp, tmp1;
    while (1)
    {
        cout << endl
             << endl;
        cout << " Binary Search Tree Operations " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Insertion/Creation " << endl;
        cout << " 2. In-Order Traversal " << endl;
        cout << " 3. Pre-Order Traversal " << endl;
        cout << " 4. Post-Order Traversal " << endl;
        cout << " 5. Removal " << endl;
        cout << " 6. Exit " << endl;
        cout << " Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << " Enter Number to be inserted : ";
            cin >> tmp;
            insert(tmp);
            break;
        case 2:
            cout << endl;
            cout << " In-Order Traversal " << endl;
            cout << " -------------------" << endl;
            print_inorder();
            break;
        case 3:
            cout << endl;
            cout << " Pre-Order Traversal " << endl;
            cout << " -------------------" << endl;
            print_preorder();
            break;
        case 4:
            cout << endl;
            cout << " Post-Order Traversal " << endl;
            cout << " --------------------" << endl;
            print_postorder();
            break;
        case 5:
            cout << " Enter data to be deleted : ";
            cin >> tmp1;
            remove(tmp1);
            break;
        case 6:
            return 0;
        }
    }
} */