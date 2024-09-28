#include <iostream>
#include <stdlib.h>
#define MAX 10
using namespace std;

int Data[MAX], totalIterasi = 0, perbIterasi;

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
        totalIterasi = i;
        if (Data[i] <= Data[j])
        {
            perbIterasi += i;
        }
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
    // Data setelah terurut
    cout << "\nData Setelah Terurut: " << endl;
    BubbleSort();

    // Total pergeseran data dan perbandingan
    cout << "Total pergeseran data: " << totalIterasi << endl;
    cout << "Dengan perbandingan pergeseran: " << perbIterasi << " : " << perbIterasi << endl;

    return 0;
}