#include <iostream>
#include <stdlib.h>
#define MAX 10
using namespace std;

int Data[MAX];

// Fungsi untuk menampilkan data
void printBubble()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        cout << "[" << Data[i] << "] ";
    }
    cout << endl;
}
// Prosedur menukar data
void Tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// Prosedur proses pengurutan metode gelembung
void BubbleSort()
{
    int i, j;

    for (i = 1; i < MAX - 1; i++)
    {
        for (j = MAX - 1; j >= i; j--)
        {
            if (Data[j - 1] > Data[j])
            {
                Tukar(&Data[j - 1], &Data[j]);
            }
        }
        printBubble();
    }
    cout << endl;
}

int main()
{
    int i;
    srand(0); // pengecakan data;

    // Membangkitkan bilangan acak
    cout << "Data Sebelum Terurut: ";
    for (i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1; // mengisi data berindeks dengan bilangan acak
        cout << "\nData ke " << i << " : " << Data[i];
    }

    cout << endl;
    // Hasil Data Setelah Terurut dan Proses Pengurutan Data
    cout << "\nHasil Data Setelah Terurut dan Proses Pengurutan Data: " << endl;
    BubbleSort();

    return 0;
}

/*
#include <iostream>
#define M 6
using namespace std;

int n, data[M];

void input()
{
    int i;
    cout << "Masukkan jumlah data yang akan diinputkan: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Masukkan data ke-" << i + 1 << " : ";
        cin >> data[i];
    }
    cout << endl;
}

void printbubble()
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "[" << data[i] << "] ";
    }

    cout << endl;
}

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort()
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j >= 1; j--)
        {
            if (data[j - 1] > data[j])
            {
                swap(&data[j - 1], &data[j]);
            }
        }
        printbubble();
    }
    cout << endl;
}

int main()
{
    cout << "PROGRAM BUBBLE SORT" << endl;
    cout << "-------------------" << endl;

    input();

    cout << "SETELAH DIUBAH" << endl;
    cout << "-------------------" << endl;
    printbubble();
    bubbleSort();

    return 0;
}
*/