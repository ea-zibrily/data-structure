#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct simpul NODE;
struct simpul
{
    int angka;
    NODE *next;
};

NODE *head;

void inisiate();
NODE *alokasi_memori(int angka);
void addAngka(int angka);
void cetakss();
void swap(int pos1, int pos2);

int main()
{
    int i, pos1, pos2;
    int angka, pilih;

    cout << "Masukkan jumlah NODE-";
    cin >> pilih;

    for (i = 0; i < pilih; i++)
    {
        cout << "Masukkan data pada NODE-" << i + 1 << " : ";
        cin >> angka;
        addAngka(angka);
    }

    cout << "Nilai dalam Linked Sebelum Dipindah: " << endl;
    cetakss();

    cout << endl;

    cout << "\nMasukkan nilai pemindah awal: ";
    cin >> pos1;
    cout << "Masukkan nilai pemindah akhir: ";
    cin >> pos2;

    if ((pos1 > 0 && pos1 <= 5) && (pos2 > 0 && pos2 <= 5))
    {
        cout << "\nAngka berhasil ditukar!" << endl;
        cout << "Angka pada NODE ke-" << pos1 << " ditukar pada node ke-" << pos2 << " : " << endl;
        swap(pos1, pos2);
        cetakss();
    }
    else
    {
        cout << "Nilai Pemindah Anda Salah!" << endl;
    }

    return 0;
}

void inisiate()
{
    head = NULL;
}

NODE *alokasi_memori(int angka)
{
    NODE *data;
    data = (NODE *)malloc(sizeof(NODE));

    data->angka = angka;
    if (data == NULL)
    {
        return NULL;
    }
    else
    {
        data->next = NULL;
        return data;
    }
}

void addAngka(int angka)
{
    NODE *data = alokasi_memori(angka);

    if (data == NULL)
    {
        head = data;
    }
    else
    {
        data->next = head;
        head = data;
    }
}

void cetakss()
{
    NODE *temp;
    temp = head;

    if (temp == NULL)
    {
        cout << "Linked List Kosong!\nTidak dapat menampilkan data." << endl;
    }
    while (temp != NULL)
    {
        cout << temp->angka << " ";
        temp = temp->next;
    }
}

void swap(int pos1, int pos2)
{
    NODE *prevNode1 = NULL, *prevNode2 = NULL, *node1 = head, *node2 = head, *temp = NULL;

    //Checks if list is empty
    if (head == NULL)
    {
        return;
    }

    //If n1 and n2 are equal, then list will remain the same
    if (pos1 == pos2)
    {
        return;
    }

    //Search for node1
    while (node1 != NULL && node1->angka != pos1)
    {
        prevNode1 = node1;
        node1 = node1->next;
    }

    //Search for node2
    while (node2 != NULL && node2->angka != pos2)
    {
        prevNode2 = node2;
        node2 = node2->next;
    }

    if (node1 != NULL && node2 != NULL)
    {

        //If previous node to node1 is not null then, it will point to node2
        if (prevNode1 != NULL)
            prevNode1->next = node2;
        else
            head = node2;

        //If previous node to node2 is not null then, it will point to node1
        if (prevNode2 != NULL)
            prevNode2->next = node1;
        else
            head = node1;

        //Swaps the next nodes of node1 and node2
        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }
    else
    {
        cout << "Swapping is not possible\n";
    }
}