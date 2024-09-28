#include <iostream>
#define max 5
using namespace std;

typedef struct queue
{
    int item[max];
    int front;
    int rear;
} QUE;

void inisiate(QUE *q)
{
    q->front = 0;
    q->rear = 0;
}

int isFull(QUE *q){
    return (q->rear == max);
}

int isMt(QUE *q){
    return (q->rear == 0);
}

void cetaks(QUE *q)
{
    int i;
    for (i = q->front; i < q->rear; i++)
    {
        cout << q->item[i]; //<< ((q->rear - 1 == i) ? " " : ",");
        cout << endl;
    }
}

int enqueue(QUE *q, int x){
    if (isFull(q))
    {
        cout<<"Queue Penuh!\nTidak bisa memasukkan data."<<endl;
    }
    else
        q->item[q->rear]=x;
        q->rear++;

    return x;
}

void dequeue(QUE *q){
    if (isMt(q))
    {
        cout<<"Queue Penuh!\nTidak bisa memasukkan data."<<endl;
    }
    else
        cout<<"Mengambil data: "<<q->item[q->front]<<endl;

        for (int i = q->front; i < q->rear; i++)
        {
            q->item[i] = q->item[i+1];
        }
		//menempatkan tail pada data terakhir yang digeser
		q->rear--;
        if (q->rear==0)
        {
            q->front==0;
        }
    
}

int main()
{
    int i;
    QUE quezz;

    inisiate(&quezz);
    cout<<"Queue Test!"<<endl;

    enqueue(&quezz, 11);
    enqueue(&quezz, 12);
    enqueue(&quezz, 13);
    enqueue(&quezz, 14);
    enqueue(&quezz, 15);
    cetaks(&quezz);
    

    dequeue(&quezz);
    dequeue(&quezz);

    cetaks(&quezz);
    return 0;
}
