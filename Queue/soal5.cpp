#include <iostream>
//menggunakan library stdlib.h dan string.h
#include <stdlib.h>
#include <string.h>
#define MAX 5
using namespace std;
//membuat struct dengan inisal Mahaszz dan QUE
typedef struct mhs
{
    int NRP;
    char nama[30];
    int nilai;
} Mahaszz;

typedef struct que
{
    Mahaszz item[MAX];
    int front;
    int rear;
    int count;
} QUE;
//membuat prototype func
void InisialisasiQueue(QUE *q);
int isFull(QUE *q);
int isEmpty(QUE *q);
void InisialisasiQueue(QUE *q);
void Enqueue(QUE *q, Mahaszz x);
Mahaszz Dequeue(QUE *q);
void TampilQueue(QUE *q);
void UrutkanQueue(QUE *q);

int main()
{
    QUE q, cetak;
    Mahaszz mhs;
    int i, hitung = 0;
    char lagi = 'Y';

    InisialisasiQueue(&q);
    InisialisasiQueue(&cetak);
    //menggunakan loop do-while
    cout << "\n\tPRIORITY QUEUE PROGRAM\n";
    cout << "======================================\n";
    do
    {
        //NRP dijadikan -1 untuk mengetahui apakah yang dimasukkan itu angka atau character
        mhs.NRP = -1;
        cout << "\nMasukkan NRP mahasiswa: ";
        cin >> mhs.NRP;
        fflush(stdin);
        if (mhs.NRP == -1)
        {
            cout << "\n* terdeteksi, data mahasiswa akan di-dequeue";
            Enqueue(&cetak, Dequeue(&q));
            UrutkanQueue(&cetak);
            cout << "\nDaftar queue cetak saat ini: ";
            TampilQueue(&cetak);
        }
        else
        {
            cout << "Masukkan nama mahasiswa: ";
            gets(mhs.nama);
            cout << "Masukkan nilai mahasiswa: ";
            cin >> mhs.nilai;
            fflush(stdin);
            Enqueue(&q, mhs);
        }
        if (++hitung == MAX)
            break;
        cout << "\nIngin memasukkan lagi? (Y/T) : ";
        cin >> lagi;

    } while (lagi == 'Y' || lagi == 'y');
    return 0;
}

//membuat func inisialisasi
void InisialisasiQueue(QUE *q)
{
    q->front = q->rear = q->count = 0;
}
//membuat func pengecekan QUE
int isFull(QUE *q)
{
    return (q->count == MAX);
}
//membuat func pengecekan QUE
int isEmpty(QUE *q)
{
    return (q->count == 0);
}
//membuat func enqueue dan dequeue
void Enqueue(QUE *q, Mahaszz x)
{
    if (isFull(q))
        cout << "Stack Penuh!\nTidak bisa memasukkan data.";
    else
    {
        q->item[q->rear].NRP = x.NRP;
        strcpy(q->item[q->rear].nama, x.nama);
        q->item[q->rear].nilai = x.nilai;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
}

Mahaszz Dequeue(QUE *q)
{
    Mahaszz temp;
    temp.NRP = -1;
    strcpy(temp.nama, " ");
    temp.nilai = -1;
    if (isEmpty(q))
        cout << "Queue Kosong!\nTidak bisa memasukkan data.";
    else
    {
        temp.NRP = q->item[q->front].NRP;
        strcpy(temp.nama, q->item[q->front].nama);
        temp.nilai = q->item[q->front].nilai;
        q->front = (q->front + 1) % MAX;
        q->count--;
    }
    return temp;
}
//membuat func tampilqueue untuk mencetak hasil queue
void TampilQueue(QUE *q)
{
    int i = q->front;
    while (i != q->rear)
    {
        cout << "Mahasiswa ke- " << i + 1 << endl;
        cout << "NRP: " << q->item[i].NRP << endl;
        cout << "Nama: " << q->item[i].nama << endl;
        cout << "Nilai: " << q->item[i].nilai << endl;
        i = (i + 1) % MAX;
    }
}
//membuat func urutan untuk mengurutkan queue
void UrutkanQueue(QUE *q)
{
    Mahaszz temp;
    temp.NRP = -1;
    strcpy(temp.nama, " ");
    temp.nilai = -1;
    int i, j, n = q->count;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (q->item[i].nilai < q->item[j].nilai)
            {
                temp.NRP = q->item[i].NRP;
                strcpy(temp.nama, q->item[i].nama);
                temp.nilai = q->item[i].nilai;
                q->item[i].NRP = q->item[j].NRP;
                strcpy(q->item[i].nama, q->item[j].nama);
                q->item[i].nilai = q->item[j].nilai;
                q->item[j].NRP = temp.NRP;
                strcpy(q->item[j].nama, temp.nama);
                q->item[j].nilai = temp.nilai;
            }
        }
    }
}