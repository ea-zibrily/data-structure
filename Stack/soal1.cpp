#include <iostream>
#define max 40 //definisi max data 50
using namespace std;

typedef struct stack //membuat struct dengan inisial STACKZ
{
    char item[max];
    int index;
} STACKZ;

//membuat prototype variabel
void inisiate(STACKZ *s);
void push(STACKZ *s, char x);
char pop(STACKZ *s);

char y[30]; //var y[30] sebagai var penghubung pop

int main()
{
    //deklarasi var
    char data[max] = "EAS*Y*QUE***ST***IO*N***"; //kalimat diinput melalui program
    int i;
    STACKZ stekk;
    //inisiate stekk
    inisiate(&stekk);

    cout << "        Character Arterisk Stack" << endl;
    cout << "       Zibril Yuan A | 02 | GTA-09" << endl;
    cout << "========================================" << endl;
    cout << "Kalimat: " << data << endl; //mencetak var data
    //menggunakan loop for untuk push & pop
    for (i = 0; i < max; i++)
    {
        if (data[i] == '*')
        {
            y[i] = pop(&stekk);
        }
        else
            push(&stekk, data[i]);
    }
    cout << "Hasil: ";
    //menggunakan loop for untuk menampilkan pop
    for (i = 0; i < max; i++)
    {
        cout << y[i];
    }

    return 0;
}
//membuat var inisialisasi stack
void inisiate(STACKZ *s)
{
    s->index = 0;
}
//membuat var pop stack
char pop(STACKZ *s)
{
    if (s->index == 0)
    {
        cout << "Stack Kosong!\nTidak bisa mengambil data.";
    }
    else
        s->index--;
    return (s->item[s->index]);
}
//membuat var push stack
void push(STACKZ *s, char x)
{
    static int i = 0;
    if (s->index == max)
    {
        cout << "Stack Penuh!\nTidak bisa memasukkan data.";
    }
    else
        s->item[s->index] = x;
    ++s->index;
}