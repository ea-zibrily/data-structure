#include <iostream>
#include <queue>
#define N 5
#define M 1000
using namespace std;

// membuat inisialisasi graph
void inisialisasi(int a, int Q[])
{
    for (int i = 0; i < N; i++)
        if ((i + 1) == a)
            Q[i] = 0;
        else
            Q[i] = M;
}

// membuat cetak isi graph
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

// membuat cetak isi graph dengan algoritma djikstra
void printDjikstra(queue<int> quii)
{
    while (!quii.empty())
    {
        cout << quii.front() << " ";
        quii.pop();
    }

    cout << endl;
}

// membuat graph dengan algoritma djikstra
void djikstra(int data[N][N], int start, int target)
{
    int i, j;
    int current = start - 1, check;
    int weightCheck[N][N];
    queue<int> rute;
    queue<int> beban;

    // pengecekan beban vertex
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            // jika nilai var data = 0 maka akan diubah menjadi M
            if (data[i][j] == 0)
            {
                weightCheck[i][j] = M;
            }
            else
            {
                weightCheck[i][j] = data[i][j];
            }
        }
    }

    // inisialisasi vertex pertama
    rute.push(start);
    beban.push(0);

    // membuat decision vertex 3 / node 2 = M agar dapat dilewati vertex/node setelahnya
    if (target != 3)
    {
        weightCheck[2][0] = M;
    }

    while (current != (target - 1))
    {
        check = M;
        // menggunakan loop for untuk mencari jalan yang dapat dilalui
        for (i = 0; i < 5; i++)
        {
            if (weightCheck[current][i] < check)
            {
                check = i; // mencari beban terkeceil
                beban.push(weightCheck[current][i]);
            }
        }

        current = check;
        rute.push(current + 1);
    }

    cout << "Rute = ";
    printDjikstra(rute);
    cout << "Beban = ";
    printDjikstra(beban);
}

int main()
{
    // deklarasi var dan matriks 2D
    int asal, tujuan;
    int Beban[N], Rute[N] = {0, 0, 0, 0, 0};
    int input[N][N] = {M, 1, 3, M, M,
                       M, M, 1, M, 5,
                       3, M, M, 2, M,
                       M, M, M, M, 1,
                       M, M, M, M, M};

    cout << "Graph With Djikstra Algorithm Program" << endl;
    cout << "=========================================" << endl;

    cout << "Masukkan vertex asal : ";
    cin >> asal;
    cout << "Masukkan vertex tujuan : ";
    cin >> tujuan;
    // memanggil fungsi inisialisasi dan tampil
    inisialisasi(asal, Beban);

    cout << "Beban dan Rute Awal : " << endl;
    Tampil(Beban, "Beban");
    Tampil(Rute, "Rute");
    // memanggil fungsi djikstra
    cout << "Beban dan Rute Djikstra : " << endl;
    djikstra(input, asal, tujuan);

    return 0;
}
