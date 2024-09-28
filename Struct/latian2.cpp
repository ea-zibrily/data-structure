#include <iostream>
using namespace std;

int main()
{
    struct zodiak
    {
    char nama[11];
    int tgl_awal;
    int bln_awal;
    int tgl_akhir;
    int bln_akhir;
    };

    static struct zodiak bintang = {"Sagitarius", 22, 11, 21, 12};
    int tgl_lhr, bln_lhr, thn_lhr;
    cout << "Masukkan tgl lahir Anda (XX-XX-XXXX): ";
    cin >> tgl_lhr >> bln_lhr >> thn_lhr;

    if ((tgl_lhr >= bintang.tgl_awal && bln_lhr == bintang.bln_awal) || 
    (tgl_lhr <= bintang.tgl_akhir && bln_lhr == bintang.bln_akhir))
    {
        cout << "Bintang anda adalah " << bintang.nama << endl;
    }
    else
    {
        cout << "Bintang anda bukan " << bintang.nama << endl;
    }
   return 0;
}