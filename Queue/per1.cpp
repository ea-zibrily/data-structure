#include <iostream>
#define MAX 10
using namespace std;

typedef struct
{
    int Item[MAX];
    int Front;
    int Rear;
    int Count; //seharusnya tidak menggunakan count
} Queue;
// Inisialisasi antrian
void Inisialisasi(Queue *q)
{
    q->Front = q->Rear = -1; //nilai dari front dan rear mungkin bisa diganti 0
    q->Count = 0;
}
// Prosedur untuk menyisipkan data pada antrian
void Tambah(Queue *q, int item)
{
    //untuk pengecekan isi queue akan lebih baik jika membuat var sendiri
    if (q->Rear == MAX - 1)
    {
        cout<<"\nAntrian Penuh";
        return;
    }
    q->Rear++;
    q->Item[q->Rear] = item;
    q->Count++; //pada bagian ini, seharusnya tidak menggunakan count
    //penggunanaan decision if else juga tidak wajib dilakukan
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
    //agar lebih ringkas bisa langsung print item[front]
    //lalu menggunakan loop for untuk menggeser frontnya
    data = q->Item[q->Front];
    q->Count--;
    if (q->Front == q->Rear)
        q->Front = q->Rear = -1;
    else
        q->Front++;
    return data;
}
void Tampil(Queue *q)
{
    for (int i = 0; i < q->Count; i++)
        cout<<"\nData : "<<q->Item[i];
}
int main()
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
    return 0;
}