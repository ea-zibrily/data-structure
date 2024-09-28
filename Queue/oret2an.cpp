/*#include <iostream>
#define MAX 20 //maksimum data queue
using namespace std;

//Deklarasi struct antrian
struct Queue {
	int front, rear, data[MAX];
}Q;

//cek apakah antrian penuh
bool isFull() {
	return Q.rear == MAX;
}

//cek apakah antrian kosong
bool isEmpty() {
	return Q.rear == 0;
}

//Menampilkan Queue
void printQueue() {
	if (isEmpty()) {
    cout << "Antrian kosong"<<endl;
	}
	else {
		cout << "QUEUE : ";
		for (int i = Q.front; i < Q.rear; i++)
		//menambahkan koma jika data tidak terdapat di antrian pertama
			cout << Q.data[i] << ((Q.rear-1 == i) ? "" : ",");
		cout << endl;
  }
}

//manambahkan data ke antrian
void enqueue() {
	if (isFull())
	{
		cout << "Antrian penuh!"<<endl;
	}
	else {
		int data;
		//menambahkan data ke antrian
		cout << "Masukkan Data : ";cin >> data;
		Q.data[Q.rear] = data;
		//menempatkan tail pada elemen data terakhir yang ditambahkan
		Q.rear++;
		cout << "Data ditambahkan\n";
		printQueue();
	}
}

// mengambil data dari antrian
void dequeue() {
	if (isEmpty())
	{
		cout << "Antrian masih kosong"<<endl;
	}
	else{
		cout << "Mengambil data \"" << Q.data[Q.front] << "\"..." << endl;
		//menggeser antrian data ke head
		for (int i = Q.front; i < Q.rear; i++)
			Q.data[i] = Q.data[i + 1];
		//menempatkan tail pada data terakhir yang digeser
		Q.rear--;
		printQueue();
	}
}

int main() {
	int choose;
	do
	{
		//Tampilan menu
		cout << "-------------------\n"
			<< "   Menu Pilihan\n"
			<< "-------------------\n"
			<< " [1] Enqueue \n"
			<< " [2] Dequeue\n"
			<< " [3] Keluar \n\n"
			<< "-------------------\n"
			<< "Masukkan pilihan : "; cin >> choose;
		switch (choose)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		default:
			cout << "Pilihan tidak tersedia";
			break;
		}
	} while (choose !=3);
	return 0;
}
*/

/*Circular Queue

// C or C++ program for insertion and
// deletion in Circular Queue
#include<iostream>
using namespace std;
 
typedef struct Queue
{
    // Initialize front and rear
    int rear, front;
 
    // Circular Queue
    int size;
    int *arr;
} QUE;

void inisiate (QUE *q,int s){
    q->front = -1;
    q->rear = -1;
    q->size = s;
    q->arr = new int[s];
}

//Function to create Circular queue
void enQueue(QUE *q, int value)
{
    if ((q->front == 0 && q->rear == q->size-1) ||
            (q->rear == (q->front-1)%(q->size-1)))
    {
        printf("\nQueue is Full");
        return;
    }
 
    else if (q->front == -1) // Insert First Element
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = value;
    }
 
    else if (q->rear == q->size-1 && q->front != 0)
    {
        q->rear = 0;
        q->arr[q->rear] = value;
    }
 
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}
 
// Function to delete element from Circular Queue
int deQueue(QUE *q)
{
    if (q->front == -1)
    {
        printf("\nQueue is Empty");
        return INT_MIN;
    }
 
    int data = q->arr[q->front];
    q->arr[q->front] = -1;
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else if (q->front == q->size-1)
        q->front = 0;
    else
        q->front++;
 
    return data;
}
 
// Function displaying the elements
// of Circular Queue
void displayQueue(QUE *q)
{
    if (q->front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (q->rear >= q->front)
    {
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ",q->arr[i]);
    }
    else
    {
        for (int i = q->front; i < q->size; i++)
            printf("%d ", q->arr[i]);
 
        for (int i = 0; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    }
}
 
//Driver of the program
int main()
{
    QUE quezz;
    inisiate(&quezz, 5);
 
    // Inserting elements in Circular Queue
    enQueue(&quezz, 14);
    enQueue(&quezz, 22);
    enQueue(&quezz, 13);
    enQueue(&quezz, -6);
 
    // Display elements present in Circular Queue
    displayQueue(&quezz);
 
    // Deleting elements from Circular Queue
    cout<<"\nDeleted value = "<< deQueue(&quezz);
    cout<<"\nDeleted value = "<< deQueue(&quezz);
 
    displayQueue(&quezz);
 
    enQueue(&quezz, 9);
    enQueue(&quezz, 20);
    enQueue(&quezz, 5);
 
    displayQueue(&quezz);
 
    enQueue(&quezz, 20);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef struct
{
    int NRP;
    char nama[30];
    int nilai;
} MHS;
typedef struct
{
    MHS item[MAX];
    int front;
    int rear;
    int count;
} Queue;
int QueuePenuh(Queue *q)
{
    return (q->count == MAX);
}
int QueueKosong(Queue *q)
{
    return (q->count == 0);
}
void InisialisasiQueue(Queue *q)
{
    q->front = q->rear = q->count = 0;
}
void Enqueue(Queue *q, MHS x)
{
    if (QueuePenuh(q))
        printf("Stack Penuh\n");
    else
    {
        q->item[q->rear].NRP = x.NRP;
        strcpy(q->item[q->rear].nama, x.nama);
        q->item[q->rear].nilai = x.nilai;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
}
MHS Dequeue(Queue *q)
{
    MHS temp;
    temp.NRP = -1;
    strcpy(temp.nama, " ");
    temp.nilai = -1;
    if (QueueKosong(q))
        printf("Queue kosong\n");
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
void TampilQueue(Queue *q)
{
    int i = q->front;
    while (i != q->rear)
    {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("NRP: %d\n", q->item[i].NRP);
        printf("Nama: %s\n", q->item[i].nama);
        printf("Nilai: %d\n", q->item[i].nilai);
        i = (i + 1) % MAX;
    }
}
void UrutkanQueue(Queue *q)
{
    MHS temp;
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
int main()
{
    Queue q, cetak;
    MHS mhs;
    int i, hitung = 0;
    char lagi = 'Y';
    InisialisasiQueue(&q);
    InisialisasiQueue(&cetak);
    do
    {
        mhs.NRP = -1; //NRP dijadikan -1 untuk mengetahui apakah yang dimasukkan itu angka atau
        printf("\nMasukkan NRP mahasiswa: ");
        scanf("%d", &mhs.NRP);
        fflush(stdin);
        if (mhs.NRP == -1)
        {
            printf("\n* terdeteksi, data mahasiswa akan di-dequeue");
            Enqueue(&cetak, Dequeue(&q));
            UrutkanQueue(&cetak);
            printf("\nDaftar queue cetak saat ini: ");
            TampilQueue(&cetak);
        }
        else
        {
            printf("Masukkan nama mahasiswa: ");
            gets(mhs.nama);
            printf("Masukkan nilai mahasiswa: ");
            scanf("%d", &mhs.nilai);
            fflush(stdin);
            Enqueue(&q, mhs);
        }
        if (++hitung == MAX)
            break;
        printf("\nIngin memasukkan lagi? (Y/T)\n");
        scanf("%c", &lagi);
    } while (lagi == 'Y' || lagi == 'y');
    return 0;
}