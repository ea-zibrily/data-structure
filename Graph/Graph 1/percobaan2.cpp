#include <iostream>
#define N 5
#define M 1000
using namespace std;

void Tampil(int data[N][N], string judul);
void Warshall(int Q[N][N], int P[N][N], int R[N][N]);

int main()
{
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

    cout << "Matriks Awal: " << endl;
    Tampil(Beban, "Beban");
    cout << endl;
    Tampil(Jalur, "Jalur");
    cout << endl;
    Tampil(Rute, "Rute");

    //mengubah ke algoritma warshall
    Warshall(Beban, Jalur, Rute);
    cout << "========================" << endl;
    cout << "Matriks Setalah Algoritma Warshall: " << endl;

    Tampil(Beban, "Beban");
    cout << endl;
    Tampil(Jalur, "Jalur");
    cout << endl;
    Tampil(Rute, "Rute");

    return 0;
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
