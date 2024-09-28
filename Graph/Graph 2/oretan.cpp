#include <iostream>
#include <queue>
#define N 5
#define M 1000
using namespace std;

void inisialisasi(int a, int Q[])
{
    for (int i = 0; i < N; i++)
        if ((i + 1) == a)
            Q[i] = 0;
        else
            Q[i] = M;
}
void Tampil(int data[N], char *judul)
{
    printf("%s = ", judul);
    for (int i = 0; i < N; i++)
        if (data[i] >= M)
            printf("M ");
        else
            printf("%d ", data[i]);
    printf("\n");
}

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

void Route(int data[5][5], int from, int to)
{
    queue<int> list; // beban
    list.push(0);
    queue<int> fix; // rute
    fix.push(from);
    int curr = from - 1;
    int test = 0;

    if (to != 3)
    {
        data[2][0] = M;
    }

    while (curr != (to - 1))
    {
        // apabila curr tidak sama dengan tujuan
        int check = M;
        for (int i = 0; i < 5; i++)
        { // mencari rute yang bisa
            if (data[curr][i] < check)
            {                              // dilalui
                check = i;                 // mencek mana beban kecil
                list.push(data[curr][i]); // list beban
            }
        }

        curr = check;
        fix.push((curr + 1));
    }
    cout << "Rute" << endl;
    showq(fix);
    cout << "Beban" << endl;
    showq(list);
}
int main()
{
    int input[N][N] = {
        M, 1, 3, M, M,
        M, M, 1, M, 5,
        3, M, M, 2, M,
        M, M, M, M, 1,
        M, M, M, M, M};

    int Beban[N], Rute[N] = {0, 0, 0, 0, 0};
    int asal, tujuan;
    printf("Masukkan node asal : ");
    scanf("%d", &asal);
    printf("Masukkan node tujuan : ");
    scanf("%d", &tujuan);
    inisialisasi(asal, Beban);
    printf("Beban dan Rute awal\n");
    Tampil(Beban, "Beban");
    Tampil(Rute, "Rute");
    cout << "setelah algoritma djiksrat" << endl;
    Route(input, asal, tujuan);
}

/*#include <iostream>
#define N 5
#define M 1000
using namespace std;

typedef struct queue Queue;
struct queue
{
    int item[N];
    int front;
    int rear;
    int count;
};

void inisialisasi_queue(Queue *q)
{
    q->front = q->rear = q->count = 0;
}
int Kosong(Queue *q)
{
    return q->count == 0;
}
int Penuh(Queue *q)
{
    return q->count == N;
}
void Enqueue(Queue *q, int x)
{
    if (Penuh(q))
    {
        printf("Queue Penuh !\n");
        exit(1);
    }
    else
    {
        q->item[q->rear] = x;
        q->rear = (q->rear + 1) % N;
        q->count++;
    }
}
int Dequeue(Queue *q)
{
    int temp;
    if (Kosong(q))
    {
        printf("Queue kosong !\n");
        temp = -1;
    }
    else
    {
        temp = q->item[q->front];
        q->front = (q->front + 1) % N;
        q->count--;
    }
    return temp;
}

void inisialisasi(int a, int Q[])
{
    for (int i = 0; i < N; i++)
        if ((i + 1) == a)
            Q[i] = 0;
        else
            Q[i] = M;
}

void Tampil(int data[N], string judul)
{
    cout << judul << " = ";
    for (int i = 0; i < N; i++)
        if (data[i] >= M)
            cout << "M ";
        else
            cout << data[i] << " ";
    cout << endl;
}

void djikstra(int data[N][N], int vertice, int start)
{
    Queue quee;
    int i, j, count, mindist, nextver;
    int weight[N][N], dist[N], visit[N], pred[N];

    for (i = 0; i < vertice; i++)
    {
        for (j = 0; j < vertice; j++)
        {
            if (data[i][j] == 0)
            {
                weight[i][j] = M;
            }
            else
            {
                weight[i][j] = data[i][j];
            }
        }
    }

    for (i = 0; i < vertice; i++)
    {
        dist[i] = weight[start][i];
        pred[i] = start;
        visit[i] = 0;
    }

    dist[start] = 0;
    visit[start] = 1;
    count = 1;

    while (count < vertice - 1)
    {
        mindist = M;

        for (i = 0; i < vertice; i++)
        {
            if (dist[i] < mindist && !visit[i])
            {
                mindist = dist[i];
                nextver = i;
            }
        }

        visit[nextver] = 1;

        for (i = 0; i < vertice; i++)
        {
            if (!visit[i])
            {
                if (mindist + weight[nextver][i] < dist[i])
                {
                    dist[i] = mindist + weight[nextver][i];
                    pred[i] = nextver;
                }
            }
        }

        count++;
    }

    for (i = 0; i < vertice; i++)
    {
        if (i != start)
        {
            cout << endl;
            cout << "Jarak menuju Vertex " << i+1 << " = " << dist[i];
            cout << endl;
            cout << "Rute = " << i;

            j = i;
            do
            {
                j = pred[j];
                cout << ", " << j;
            } while (j != start);
        }
    }

}

int main()
{
    int input[N][N] = {M, 1, 3, M, M,
                       M, M, 1, M, 5,
                       3, M, M, 2, M,
                       M, M, M, M, 1,
                       M, M, M, M, M};

    int Beban[N], Rute[N] = {0, 0, 0, 0, 0};
    int asal, tujuan;
    int vertice = 5;

    cout << "Masukkan node asal : ";
    cin >> asal;
    cout << "Masukkan node tujuan : ";
    cin >> tujuan;

    inisialisasi(asal, Beban);

    cout << "Beban dan Rute Awal : " << endl;
    Tampil(Beban, "Beban");
    Tampil(Rute, "Rute");

    cout << "Beban dan Rute Algoritma Djikstra : " << endl;
    djikstra(input, vertice, asal);

    return 0;
}*/
