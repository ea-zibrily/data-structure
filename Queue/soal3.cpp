#include <iostream>
#include <stdlib.h>
#define MAX 20
using namespace std;
//membuat inisial struct queue
typedef struct queue
{
    int plat[MAX];
    int front;
    int rear;
    int top;
} QUE;
//membuat inisial struct stack
typedef struct stack
{
    int plat[MAX];
    int top;
} STACKZ;

void inisiateQueue(QUE *q);
void inisiateStack(STACKZ *s);
int push(STACKZ *s, int x);
int pop(STACKZ *s);
void normalisasi_queue(STACKZ *s, QUE *q, int x);
int cek_mobil(QUE *q, int x);
void enqueue(QUE *q, int x);
void dequeue(STACKZ *s, QUE *q, int y);
void cetakss(QUE *q);

int main()
{
    //deklarsi var
    int jawab;
    int plt;
    QUE q;
    STACKZ s;
    //memanggil func inisiate queue dan stack
    inisiateQueue(&q);
    inisiateStack(&s);

    cout << "\n\tPARKING AREA PROGRAM\n";
    cout << "======================================\n";
    //menggunakan loop do-while untuk mengulang pilihan
    do
    {
        cout << "Silahkan memilih pilihan yang tersedia.\n";
        cout << "=======================================\n";
        cout << "1. Masukkan kendaraan\n";
        cout << "2. Keluarkan kendaraan\n";
        cout << "3. Tampilkan isi parkiran\n";
        cout << "4. Keluar\n";

        cout << "\nPilih : ";
        cin >> jawab;
        printf("======================================\n");
        //menggunakan decision switch
        switch (jawab)
        {
        case 1:
            cout << "Masukkan nomor plat masuk : ";
            cin >> plt;
            enqueue(&q, plt);
            cetakss(&q);
            break;
        case 2:
            cout << "Masukkan plat nomor keluar: ";
            cin>>plt;
            dequeue(&s,&q,plt);
            cetakss(&q);
            break;
        case 3:
            cetakss(&q);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Pilihan yang anda masukkan salah!\n";
            break;
        }

    } while (jawab != 4);

    return 0;
}

//membuat inisialisasi que dan stackz
void inisiateQueue(QUE *q)
{
    q->front = 0;
    q->rear = 0;
    q->top = 0;
}
void inisiateStack(STACKZ *s)
{
    s->top = 0;
}
//membuat func push dan stack
int push(STACKZ *s, int x)
{
    s->top++;
    s->plat[s->top] = x;
    return x;
}
int pop(STACKZ *s)
{
    int x;
    x = s->plat[s->top];
    s->top--;
    return (x);
}
//membuat func normalisasi
void normalisasi_queue(STACKZ *s, QUE *q, int x)
{
    do
    {
        q->plat[x] = q->plat[x + 1];
        x++;
    } while (x < q->rear);
    q->rear--;
    q->top--;
    do
    {
        q->front--;
        q->plat[q->front] = pop(s);
        q->top++;
    } while (s->top != 0);
}
//membuat func cek_mobil untuk mengecek jumlah mobil
int cek_mobil(QUE *q, int x)
{
    int i, hasil;
    for (i = q->front; i <= q->rear; i++)
    {
        if (q->plat[i] == x)
        {
            hasil = i;
            break;
        }
        else if ((q->plat[i] != x) && (i == q->rear))
        {
            hasil = 0;
        }
    }
    return (hasil);
}
//membuat func en dan de queue
void enqueue(QUE *q, int x)
{
    if (q->rear == MAX)
    {
        cout << "\nParkiran Penuh!\n";
    }
    else if (q->top == 0)
    {
        q->rear++;
        q->plat[q->rear] = x;
        q->top++;
        q->front++;
    }
    else
    {
        q->rear++;
        q->plat[q->rear] = x;
        q->top++;
    }
}
void dequeue(STACKZ *s, QUE *q, int y)
{
    int i, x;
    i = q->front;
    if (q->top == 0)
    {
        cout << "\nParkiran Kosong!\n";
    }
    else if (cek_mobil(q, y) == 0)
    {
        cout << "\nPlat yang anda masukkan tidak ada dalam Parking Area!\n";
    }
    else if ((cek_mobil(q, y) == q->front) && (q->top > 1))
    {
        q->front++;
        q->top--;
        //return;
    }
    else if ((cek_mobil(q, y) == q->front) && (q->top == 1))
        inisiateQueue(q);
    else
    {
        x = cek_mobil(q, y);
        cout << "\nMobil yang keluar sementara: \n";
        for (i = q->front; i < x; i++)
        {
            cout << "-kendaraan plat nomor " << q->plat[i];
            push(s, q->plat[i]);
            q->front++;
            q->top--;
        }
        normalisasi_queue(s, q, x);
        //return;
    }
}
//membuat func cetak
void cetakss(QUE *q)
{
    int i, x;
    x = q->front;
    cout << "\nData antrian mobil yang parkir : \n";
    if (q->top == 0)
        cout << "\nTidak ada mobil yang sedang parkir\n";
    else
    {
        for (i = 1; i <= q->top; i++)
        {
            cout << i << ". Mobil plat nomor " << q->plat[x];
            cout << endl;
            x++;
        }
        cout << "\nJumlah mobil yang parkir : " << q->top;
        cout << endl;
    }
}