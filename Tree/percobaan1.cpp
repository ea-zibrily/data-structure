#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct tree *pohon; //membuat inisial struct tree

//deklarasi dari tree dengan menggunakan linked list
struct tree
{
    char info;
    pohon kiri;
    pohon kanan;
};

//fungsi untuk membuat simpul yang pertama
pohon baru(char hrf)
{
    pohon br;
    br = (pohon)malloc(sizeof(struct tree));
    br->info = hrf;
    br->kiri = NULL;
    br->kanan = NULL;
    return (br);
}

//fungsi insert node baru
void sisip(pohon ph, pohon sp)
{
    pohon P, Q;
    P = ph;
    Q = ph;
    while ((sp->info != ph->info) && (Q != NULL))
    {
        P = Q;
        if (sp->info < P->info)
        {
            Q = P->kiri;
        }
        else
        {
            Q = P->kanan;
        }
    }

    if (sp->info == P->info)
    {
        cout << "Sudah ada";
    }
    else if (sp->info < P->info)
    {
        P->kiri = sp;
    }
    else
    {
        P->kanan = sp;
    }
}

//fungsi transversal dengan rekursif
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
    //menggunakan loop while
    while (1)
    {
        cout << "Ketikkan Huruf : ";
        cin >> input;
        fflush(stdin);
        if (j == 0)
        {
            br = baru(input);
        }

        else
        {
            ssp = baru(input);
            sisip(br, ssp);
        }

        printf("Ada data lagi(y/t): ");
        scanf("%s", &jawab);
        fflush(stdin);
        if ((strcmp(jawab, "Y") == 0) || (strcmp(jawab, "y") == 0))
        {
            j++;
            continue;
        }
        else if ((strcmp(jawab, "T") == 0) || (strcmp(jawab, "t") == 0))
            break;
    }

    //mencetak fungsi transversal
    cout << "\nTranvers Proder : ";
    preorder(br);
    cout << endl;
    cout << "Tranvers Inorder : ";
    inorder(br);
    cout << endl;
    cout << "Tranvers Postorder : ";
    postorder(br);

    return 0;
}