#include <iostream>
#define max 100 //definisi max nilai 100
using namespace std;

typedef struct stack //membuat struct dengan inisial STACKZ
{
    int item[max];
    int index;
} STACKZ;

//membuat prototype variabel
void inisiate(STACKZ *s);
void push(STACKZ *s, int x);
int pop(STACKZ *s);
void cetak(STACKZ *s);
void toBin(STACKZ *s, int x);
void toOcta(STACKZ *s, int x);
void toHexa(STACKZ *s, int x);

int main()
{
    //deklarasi var
    int i;
    int num;
    int total = 0; //var total untuk menampung hasil
    STACKZ stekk;
    //inisiate stekk
    inisiate(&stekk);

    cout << "            Decimal Converter" << endl;
    cout << "       Zibril Yuan A | 02 | GTA-09" << endl;
    cout << "========================================" << endl;
    //input data
    cout << "Masukkan bilangan desimal: ";
    cin >> num;
    //memanggil variabel biner, octa, dan hexa
    toBin(&stekk, num);
    toOcta(&stekk, num);
    toHexa(&stekk, num);

    return 0;
}
//membuat var inisialisasi stack
void inisiate(STACKZ *s)
{
    s->index = 0;
}
//membuat var pop stack
int pop(STACKZ *s)
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
void push(STACKZ *s, int x)
{
    if (s->index == max)
    {
        cout << "Stack Penuh!\nTidak bisa memasukkan data.";
    }
    else
        s->item[s->index] = x;
    ++s->index;
}
//membuat var print stack
void cetak(STACKZ *s)
{
    while (!s->index == 0)
    {
        cout << pop(s) << " ";
    }
}
//membuat var toBin,toOcta,toHexa
void toBin(STACKZ *s, int x)
{
    int total = 0;
    //menggunakan while untuk menghitung tiap elemen stack
    while (x > 0)
    {
        total = x % 2; //take reminder
        x /= 2;
        push(s, total);
    }
    cout << "Hasil Binernya adalah ";
    cetak(s);
    cout << endl;
}

void toOcta(STACKZ *s, int x)
{
    int total = 0;
    //menggunakan while untuk menghitung tiap elemen stack
    while (x > 0)
    {
        total = x % 8; //take reminder
        x /= 8;
        push(s, total);
    }
    cout << "Hasil Octanya adalah ";
    cetak(s);
    cout << endl;
}

void toHexa(STACKZ *s, int x)
{
    int total = 0;
    //menggunakan while untuk menghitung tiap elemen stack
    while (x > 0)
    {
        total = x % 16;
        x /= 16;
        push(s, total);
    }
    cout << "Hasil Hexanya adalah ";
    cetak(s);
    cout << endl;
}