#include <iostream>
#include <stdlib.h>
#define MAX 10
using namespace std;

int Data[MAX], totalIterasi = 0, perbIterasi = 0;

// Fungsi untuk menampilkan data
void printShell()
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
// Prosedur proses pengurutan metode Shell
void ShellSort()
{
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;

    while (Jarak > 1)
    {
        Jarak = Jarak / 2;
        Sudah = false;
        while (!Sudah)
        {
            Sudah = true;
            for (j = 0; j < MAX - Jarak; j++)
            {
                i = j + Jarak;
                if (Data[j] > Data[i])
                {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                }
            }
        }
        printShell();
        totalIterasi += 1;
        perbIterasi += totalIterasi-1;
    }
    cout << endl;
}

int main()
{
    int i;
    srand(0); // pengacakan data

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
    ShellSort();

    // Total pergeseran data dan perbandingan
    cout << "Total pergeseran data: " << totalIterasi << endl;
    cout << "Dengan perbandingan pergeseran: " << perbIterasi << " : " << perbIterasi << endl;

    return 0;
}