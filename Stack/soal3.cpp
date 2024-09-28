#include <iostream>
#define max 20 //definisi max data 20
using namespace std;

typedef struct stack//membuat struct dengan inisial STACKZ
{
    char item[max];
    int top;
} STACKZ;
//membuat prototype variabel
void inisiate(STACKZ *s);
char push(STACKZ *s, int a);
char pop(STACKZ *s);
void cetaks(STACKZ *s);

int main()
{
    //deklarasi variabel
    int i;
    char input[max] = "Struktur Data"; //kalimat diinput lewat program
    STACKZ stekk;
    //inisiate stekk
    inisiate(&stekk);

    cout << "             Pembalik Kalimat" << endl;
    cout << "       Zibril Yuan A | 02 | GTA-09" << endl;
    cout << "========================================" << endl;
    cout << "Kalimat\t\t\t: " << input; //mencetak var input
    //menggunakan loop for untuk push data
    for (i = 0; i < max; i++)
    {
        push(&stekk, input[i]);
    }
    cout << endl;
    cout << "Hasil setelah dibalik\t: ";
    cetaks(&stekk);

    return 0;
}
//membuat var inisialisasi stack
void inisiate(STACKZ *s)
{
    s->top == 0;
}
//membuat var push stack
char push(STACKZ *s, int a)
{
    static int i = 0;
    if (s->top == max)
    {
        cout << "Stack Penuh!\nTidak bisa memasukkan data." << endl;
    }
    else
        s->item[s->top] = a;
    ++s->top;
    return a;
}
//membuat var pop stack
char pop(STACKZ *s)
{
    char nezuko;

    if (s->top == 0)
    {
        cout << "Stack Kosong!\nTidak bisa mengambil data." << endl;
    }
    else
        s->top--;
    nezuko = s->item[s->top];
    return nezuko;
}
//membuat var cetak stack
void cetaks(STACKZ *s)
{
    while (!s->top == 0)
    {
        cout << pop(s);
    }
}