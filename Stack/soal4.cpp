#include <iostream>
#include <cstring> //menggunakan library cstring untuk memanggil strlen
#define max 7      //definisi max data 20
using namespace std;

typedef struct stack //membuat struct dengan inisial STACKZ
{
    char item[max];
    int top;
} STACKZ;
//membuat prototype variabel
void inisiate(STACKZ *s);
char pop(STACKZ *s);
void push(STACKZ *s, char x);
void cetaks(STACKZ *s);

int main()
{
    //deklarasi variabel
    int i, j, lenght;
    int flag = 0; //deklarasi flag untuk penentu polindrom
    char input[max];
    STACKZ stekk;
    //inisiate stekk
    inisiate(&stekk);

    cout << "             Polindrom Words" << endl;
    cout << "       Zibril Yuan A | 02 | GTA-09" << endl;
    cout << "========================================" << endl;
    //input data
    cout << "Masukkan kalimat: ";
    cin >> input;
    //menggunakan loop for untuk push data
    for (i = 0; i < max; i++)
    {
        push(&stekk, input[i]);
    }
    cetaks(&stekk);
    //inisialisasi lenght
    lenght = strlen(input); //strlen untuk menghitung panjang string
    //menggunakan loop for untuk cek data
    for (j = 0; j < lenght; j++)
    {
        if (input[j] != input[lenght - j - 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << " bukan kalimat polindrom!" << endl;
    }
    else
    {
        cout << " merupakan kalimat polindrom!" << endl;
    }

    return 0;
}
//membuat var inisialisasi stack
void inisiate(STACKZ *s)
{
    s->top == 0;
}
//membuat var push stack
void push(STACKZ *s, char x)
{
    if (s->top == max)
    {
        cout << "Stack Penuh!\nTidak bisa mengisi data.";
    }
    else
        s->item[s->top] = x;
    ++s->top;
}
//membuat var pop stack
char pop(STACKZ *s)
{
    char uzu;
    if (s->top == 0)
    {
        cout << "Stack Kosong!\nTidak bisa mengambil data.";
    }
    else
        s->top--;
    uzu = s->item[s->top];

    return uzu;
}
//membuat var cetak stack
void cetaks(STACKZ *s)
{
    while (!s->top == 0)
    {
        cout << pop(s);
    }
}