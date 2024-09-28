#include <iostream>
#include <stdlib.h>
#define max 30
using namespace std;

//inisialisasi struct
typedef struct pohon TREE;
typedef struct stack1 operat;
typedef struct stack2 operan;

struct pohon
{
    int data;
    TREE *left;
    TREE *right;
};

TREE *root;

struct stack1
{
    int data_opr[max];
    int count1;
};

struct stack2
{
    int data_opd[max];
    int count2;
};

//fungsi stack operator
void inisiateopr(operat *z)
{
    z->count1 = 0;
}

bool isMt1(operat *z)
{
    if (z->count1 == 0)
    {
        return 1;
    }
    else
        return 0;
}

void pushopr(operat *z, int x)
{
    if (z->count1 == max)
    {
        cout << "Stack Penuh!\nTidak dapat memasukkan data.\n";
        exit(1);
    }
    else
    {
        z->data_opr[z->count1] = x;
    }
    z->count1++;
}

int popopr(operat *z)
{
    int uzu;
    if (isMt1(z))
    {
        cout << "Stack masih kosong!";
    }
    else
    {
        --(z->count1);
    }
    uzu = z->data_opr[z->count1];
    return uzu;
}

void cetakopr(operat *z)
{
    while (z->count1 != 0)
    {
        cout << popopr(z);
    }
}

//fungsi stack operand
void inisiateopd(operan *y)
{
    y->count2 = 0;
}

bool isMt2(operan *y)
{
    if (y->count2 == 0)
    {
        return 1;
    }
    else
        return 0;
}

void pushopd(operan *y, int x)
{
    if (y->count2 == max)
    {
        cout << "Stack Penuh!\nTidak dapat memasukkan data.\n";
        exit(1);
    }
    else
    {
        y->data_opd[y->count2] = x;
    }
    y->count2++;
}

int popopd(operan *y)
{
    int uzu;
    if (isMt2(y))
    {
        cout << "Stack masih kosong!";
    }
    else
    {
        --(y->count2);
    }
    uzu = y->data_opd[y->count2];
    return uzu;
}

void cetakopd(operan *y)
{
    while (y->count2 != 0)
    {
        cout << popopd(y);
    }
}

//fungsi tree
bool isEmpty()
{
    return root == NULL;
}

TREE *alokasi_memori(int gas)
{
    TREE *pohonz;
    pohonz = (TREE *)malloc(sizeof(TREE));

    pohonz->data = gas;
    pohonz->left = NULL;
    pohonz->right = NULL;

    return pohonz;
}

void insert(int gas)
{
    TREE *pohon = alokasi_memori(gas);
    TREE *parent;
    parent = NULL;

    if (isEmpty())
    {
        root = pohon;
    }
    else
    {
        TREE *current;
        current = root;

        while (current)
        {
            parent = current;
            if (pohon->data > current->data)
                current = current->right;
            else
                current = current->left;
        }

        if (pohon->data < parent->data)
            parent->left = pohon;
        else
            parent->right = pohon;
    }
}

void inorder(TREE *p)
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

void preorder(TREE *p)
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

void print_inorder()
{
    inorder(root);
}

void print_preorder()
{
    preorder(root);
}

int main()
{
    cout << "Pohon Biner Persamaan Matematika" << endl;
    insert(2);
    insert(5);
    insert(1);
    insert(6);
    insert(3);


    print_inorder();
    cout << endl;
    print_preorder();

    return 0;
}
