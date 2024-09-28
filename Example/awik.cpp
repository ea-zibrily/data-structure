#include <iostream>
using namespace std;

typedef struct mhs Mahasiswa;
struct mhs
{
    string nama;
    int nrp;
    string kelas;
};

void menyimpan(Mahasiswa *x, string nama, int nrp, string kelas);

int main()
{
    Mahasiswa data;
    menyimpan(&data, "Rahmat", 1, "GTA");

}

void menyimpan(Mahasiswa *x, string nama, int nrp, string kelas)
{
    Mahasiswa info;
    info.nama = nama;
    info.nrp = nrp;
    info.kelas = kelas;

    x = &info;

    cout << "Nama  : " << x->nama << endl;
    cout << "NRP   : " << x->nrp << endl;
    cout << "Kelas : " << x->kelas << endl;
}
