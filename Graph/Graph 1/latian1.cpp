#include <iostream>
#define N 5
#define M 1000
using namespace std;

//membuat struct Stack dan inisialisasinya
typedef struct stack STACK;
struct stack
{
    int data[N][N];
    int row;
    int col;
};

//prototype func
void inisiate(STACK *s);
bool isEmpty(STACK *s);
bool isFull(STACK *s);
void push(STACK *s, int data);
int pop(STACK *s);

void Tampil(int data[N][N], string judul);
void Warshall(int Q[N][N], int P[N][N], int R[N][N]);

int main()
{
    //deklarasi stack
    STACK stackz;
    inisiate(&stackz);

    //deklarasi array 2D
    int Beban[N][N] = {M, 1, 3, M, M,
                       M, M, 1, M, 5,
                       3, M, M, 2, M,
                       M, M, M, M, 1,
                       M, M, M, M, M};
    int Jalur[N][N] = {0, 1, 1, 0, 0,
                       0, 0, 1, 0, 1,
                       1, 0, 0, 1, 0,
                       0, 0, 0, 0, 1,
                       0, 0, 0, 0, 0};
    int Rute[N][N] = {M, 0, 0, M, M,
                      M, M, 0, M, 0,
                      0, M, M, 0, M,
                      M, M, M, M, 0,
                      M, M, M, M, M};

    //melakukan push pop rute terpendek
    push(&stackz, 4);
    push(&stackz, 3);
    push(&stackz, 2);
    pop(&stackz);
    Tampil(Rute, "Rute Terpendek");

    return 0;
}
//func dalam struct
void inisiate(STACK *s)
{
    s->row = 0;
}

bool isEmpty(STACK *s)
{
    if (s->row == 0)
    {
        return 1;
    }
    else
        return 0;
}

bool isFull(STACK *s)
{
    if (s->row == N)
    {
        return 1;
    }
    else
        return 0;
}

void push(STACK *s, int data)
{
    if (isFull(s))
    {
        cout << "Stack penuh! Tidak dapat memasukkan data.";
    }
    else
        s->data[s->row][s->col] = data;
    ++s->row;
}

int pop(STACK *s)
{
    if (isEmpty(s))
    {
        cout << "Stack Kosong! Tidak dapat menampilkan data.";
    }
    else
        --s->row;
    return (s->data[s->row][s->col]);
}

void Tampil(int data[N][N], string judul)
{
    cout << judul << " = " << endl;
    //menggunakan nested loop for karena merupakan array 2D
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (data[i][j] >= M)
                cout << "M ";
            else
                cout << data[i][j] << " ";
        cout << endl;
    }
}

void Warshall(int Q[N][N], int P[N][N], int R[N][N])
{
    //menggunakan nested loop kij
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                P[i][j] = P[i][j] | (P[i][k] & P[k][j]);
                if ((Q[i][k] + Q[k][j]) < Q[i][j])
                {
                    Q[i][j] = Q[i][k] + Q[k][j];
                    if (R[k][j] == 0)
                        R[i][j] = k + 1;
                    else
                        R[i][j] = R[k][j];
                }
            }
}
