#include <iostream>
#define M 100
#define N 5
using namespace std;

int dataAngka[];
char dataNama[][MAX];

void input()
{
    int i;
    cout << "Masukkan data diri anda: ";
    for (i = 0; i < N; i++)
    {
        cout << "NIP: ";
        cin >> dataAngka[i];

        cout << "Nama: ";
        cin >> dataNama[i][M];
    }
    cout << endl;
}

void printSort()
{
    int i;
    for (i = 0; i < N; i++)
    {
        cout << dataAngka[i] << ". " << dataNama[i][M];
    }
    cout << endl;    
}

void swapbyNumber(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void swapbyChara(char *x, char *y)
{
    char temp[M];

    temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < n-1-i; j++)
        {
            if (dataNama[j], dataNama[j+1] > 0)
            {
                swapbyChara(&dataNama[j], dataNama[j=1])
            }
        }
        
    }
}

//lanjut mene