#include <iostream>
using namespace std;

typedef struct Queue
{
    int rear;
    int front;
    //size dan *arr untuk menentukan panjang circular queue
    int size;
    int *arr;
} QUE;
//deklarasi prototype func
void inisiate(QUE *q, int s);
void enqueue(QUE *q, int x);
int dequeue(QUE *q);
void cetakss(QUE *q);
int isMt(QUE *q);

int main()
{
    QUE quezz;
    inisiate(&quezz, 5);

    cout << "\n\tCIRCULAR QUEUE PROGRAM\n";
    cout << "======================================\n";

    //memasukkan data circular queue
    enqueue(&quezz, 5);
    enqueue(&quezz, 6);
    enqueue(&quezz, 7);
    cetakss(&quezz);

    //menghapus data atau dequeue
    cout << "\nDequeue : " << dequeue(&quezz);
    cetakss(&quezz);

    enqueue(&quezz, 8);
    enqueue(&quezz, 9);
    cetakss(&quezz);
    cout << "\nDequeue : " << dequeue(&quezz);

    enqueue(&quezz, 10);
    enqueue(&quezz, 11);
    cetakss(&quezz);
    
    enqueue(&quezz, 12);

    return 0;
}
//membuat func inisialisasi
void inisiate(QUE *q, int s)
{
    q->front = -1;
    q->rear = -1;
    q->size = s;
    q->arr = new int[s];
}
//membuat func pengecekan queue
int isMt(QUE *q){
    return q->front == -1;
}

//membuat func enqueue dan dequeue untuk circular queue
void enqueue(QUE *q, int x)
{
    //menggunakan 4 decision if else untuk menentukan posisi data
    if ((q->front == 0 && q->rear == q->size - 1) || (q->rear == (q->front - 1) % (q->size - 1)))
    {
        cout << "\nQueue Penuh!\n Tidak bisa memasukkan data.";
        return;
    }

    else if (q->front == -1) // Insert First Element
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = x;
    }

    else if (q->rear == q->size - 1 && q->front != 0)
    {
        q->rear = 0;
        q->arr[q->rear] = x;
    }

    else
    {
        q->rear++;
        q->arr[q->rear] = x;
    }
}

int dequeue(QUE *q)
{
    if (isMt(q))
    {
        cout << "\nQueue Kosong!\nTidak bisa mengambil data.";
    }

    int data = q->arr[q->front];
    q->arr[q->front] = -1;
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else if (q->front == q->size - 1)
        q->front = 0;
    else
        q->front++;

    return data;
}

//membuat func untuk mencetak circular queue
void cetakss(QUE *q)
{
    if (isMt(q))
    {
        cout << "\nQueue Kosong!\nTidak bisa menampilkan data.";
        return;
    }
    cout << "\nNilai pada Circular Queue: ";
    if (q->rear >= q->front)
    {
        for (int i = q->front; i <= q->rear; i++)
            cout << q->arr[i] << " ";
    }
    else
    {
        for (int i = q->front; i < q->size; i++)
            cout << q->arr[i] << " ";

        for (int i = 0; i <= q->rear; i++)
            cout << q->arr[i] << " ";
    }
}