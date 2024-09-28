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
// Prosedur pengurutan metode gelembung
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
    }
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
    BubbleSort();

    cout << endl;
    // Data setelah terurut
    cout << "\nData Setelah Terurut: ";
    for (i = 0; i < MAX; i++)
    {
        cout << "\nData ke " << i << " : " << Data[i];
    }

    return 0;
}