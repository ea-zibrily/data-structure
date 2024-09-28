#include <iostream>
#define MAX 10
using namespace std;

typedef struct
{
    int Item[MAX];
    int Front;
    int Rear;
    int Count;
} Queue;
// Inisialisasi antrian
void Inisialisasi(Queue *q)
{
    q->Front = q->Rear = -1;
    q->Count = 0;
}
// Prosedur untuk menyisipkan data pada antrian
void Tambah(Queue *q, int item)
{
    //pada enqueue sepertinya harus menambahkan beberaoa decision lagi
    if ((q->Rear == MAX - 1 && q->Front == 0) || (q->Rear + 1 == q->Front))
    {
        cout<<"\nAntrian Penuh";
        return;
    }
    if (q->Rear == MAX - 1)
        q->Rear = 0;
    else
        q->Rear++;
    q->Item[q->Rear] = item;
    q->Count++;
    if (q->Front == -1)
        q->Front = 0;
}
// Prosedur untuk menghapus data dari antrian
int Hapus(Queue *q)
{
    int data;
    //untuk pengecekan isi queue akan lebih baik jika membuat var sendiri
    if (q->Front == -1)
    {
        cout<<"\nAntrian Kosong";
        return NULL;
    }
    else
    {
        data = q->Item[q->Front];
        q->Count--;
        if (q->Front == q->Rear)
            q->Front = q->Rear = -1;
        else
        {
            if (q->Front == MAX - 1)
                q->Front = 0;
            else
                q->Front++;
        }
    }
    return data;
}
void Tampil(Queue *q)
{
    for (int i = 0; i < q->Count; i++)
        cout<<"\nData : "<<q->Item[i];
}
void main() //agar program berjalan sebaiknya menggunakan int
{
    Queue q;
    int data;
    Inisialisasi(&q);
    Tambah(&q, 11);
    Tambah(&q, 12);
    Tambah(&q, 13);
    Tambah(&q, 14);
    Tambah(&q, 15);
    Tambah(&q, 16);
    Tambah(&q, 17);
    Tambah(&q, 18);
    Tambah(&q, 19);
    Tambah(&q, 20);
    Tambah(&q, 21);
    Tampil(&q);

    data = Hapus(&q);
    cout<<"\nHapus Item = "<<data;

    data = Hapus(&q);
    cout<<"\nHapus Item = "<<data;

    data = Hapus(&q);
    cout<<"\nHapus Item = "<<data;

    Tampil(&q);
}