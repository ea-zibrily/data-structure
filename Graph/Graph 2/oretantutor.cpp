#include <iostream>
using namespace std;
// mendefinisikan variable global, 999 merepresentasikan infinity
#define INF 999

void djikstra(int data[5][5], int ver, int source, int target)
{
    int i, j, start, minimum, m, update, min_weight;
    // inisialisasi matriks bobot, buffer, visited dll
    int weight[ver][ver], buff[ver], path[ver], prev[ver], visited[ver] = {0};
    // inisalisasi nilai awal bobot, buffer, dll
    for (i = 1; i < ver; i++)
    {
        buff[i] = INF;
        prev[i] = -1;
        path[i] = 0;
        for (int j = 1; j < ver; j++)
        {
            weight[i][j] = INF;
        }
    }
    // memasukkan nilai bobot
    for (i = 1; i < ver; i++)
    {
        for (j = i + 1; j < ver; j++)
        {
            weight[j][i] = data[i][j];
        }
        cout << "\n";
    }

    start = source;
    visited[start] = 1;
    buff[start] = 0;
    // proses mencari bobot terkecil
    while (visited[target] == 0)
    {
        minimum = INF;
        m = 0;
        for (i = 1; i < ver; i++)
        {
            update = buff[start] + weight[start][i];
            // cek vertex yang sudah dikunjungi
            if (update < buff[i] && visited[i] == 0)
            {
                buff[i] = update;
                prev[i] = start;
            }
            if (minimum > buff[i] && visited[i] == 0)
            {
                minimum = buff[i];
                m = i;
            }
        }
        start = m;
        visited[start] = 1;
    }
    // bobot terkecil
    min_weight = buff[target];
    // backtracking untuk mencari jalur yang dilalui
    // mulai backtracking
    start = target;
    j = 0;
    // mencari vertex yang dikunjungi
    while (start != -1)
    {
        path[j] = start;
        start = prev[start];
        j++;
    }
    // menampilkan bobot terkecil yang dilalui
    cout << "\nBobot terkecil yang dilalui adalah " << min_weight << "\n";
    // menampilkan vertex yang dikunjungi
    cout << "Jalur yang ditempuh adalah : ";
    for (int i = ver - 1; i >= 0; i--)
    {
        if (path[i] != 0)
        {
            cout << path[i] << " ";
        }
    }
    cout << "\n";
}
// program utama
int main()
{
    // inisalisasi variable
    int i, j, source, target, start, minimum, m, update, ver, min_weight;
    cout << "CONTOH PROGRAM DENGAN ALGORITMA DIJKSTRA \n\n";
    // masukkan jumlah vertex yang diinginkan

    int input[5][5] = {INF, 1, 3, INF, INF,
                       INF, INF, 1, INF, 5,
                       3, INF, INF, 2, INF,
                       INF, INF, INF, INF, 1,
                       INF, INF, INF, INF, INF};

    // masukkan vertex awal dan tujuan
    cout << "Masukkan Vertex Awal : ";
    cin >> source;
    cout << "Masukkan Vertex Tujuan : ";
    cin >> target;
    
    djikstra(input, 5, source, target);
}

/*#include <iostream>
#include <climits>
#define N 5
#define M 1000
using namespace std;

// this method returns a minimum distance for the
// vertex which is not included in Tset.
int minimumDist(int dist[], bool Tset[])
{
    int min = INT_MAX, index;

    for (int i = 0; i < 6; i++)
    {
        if (Tset[i] == false && dist[i] <= min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(int graph[N][N], int src) // adjacency matrix used is 6x6
{
    int dist[6];  // integer array to calculate minimum distance for each node.
    bool Tset[6]; // boolean array to mark visted/unvisted for each node.

    // set the nodes with infinity distance
    // except for the initial node and mark
    // them unvisited.
    for (int i = 0; i < 6; i++)
    {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }

    dist[src] = 0; // Source vertex distance is set to zero.

    for (int i = 0; i < 6; i++)
    {
        int m = minimumDist(dist, Tset); // vertex not yet included.
        Tset[m] = true;                  // m with minimum distance included in Tset.
        for (int i = 0; i < 6; i++)
        {
            // Updating the minimum distance for the particular node.
            if (!Tset[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i])
                dist[i] = dist[m] + graph[m][i];
        }
    }
    cout << "Vertex\t\tDistance from source" << endl;
    for (int i = 0; i < 6; i++)
    {                      // Printing
        char str = 65 + i; // Ascii values for pritning A,B,C..
        cout << str << "\t\t\t" << dist[i] << endl;
    }
}

int main()
{
    int input[N][N] = {M, 1, 3, M, M,
                       M, M, 1, M, 5,
                       3, M, M, 2, M,
                       M, M, M, M, 1,
                       M, M, M, M, M};

    Dijkstra(input, 0);
    return 0;
} */
