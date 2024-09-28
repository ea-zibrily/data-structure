#include <iostream>
#include <stdlib.h>
#define MAX 10
using namespace std;

int Data[MAX];

// Prosedur menukar data
void Tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// Prosedur pengurutan metode Shell
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
    }
}

int main()
{
    int i;
    srand(0); // pengacakan data

    // Membangkitkan bilangan acak
    cout << "Data Sebelum Terurut: ";
    for (i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1; //mengisi data berindeks dengan bilangan acak
        cout << "\nData ke " << i << " : " << Data[i];
    }
    ShellSort();

    cout << endl;
    // Data setelah terurut
    cout << "\nData Setelah Terurut: ";
    for (i = 0; i < MAX; i++)
    {
        cout << "\nData ke " << i << " : " << Data[i];
    }

    return 0;
}