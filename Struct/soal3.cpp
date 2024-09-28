#include <iostream>
#include <string.h>
using namespace std;

struct menu //membuat struct menu
{
    char kPotong;
    int jumlah;
};

struct menu gfc[15]; //deklarasi var struct menu gfc[15]

int main()
{
    //deklarasi variabel
    int i = 0, j, hSatuan, total=0;
    string jPotong;
    char ulang;

    cout <<"\tToko GFC - Gerobak Fried Chicken\n" << endl;
    cout <<"Daftar Harga\n";
    cout <<"========================================\n";
    cout <<"Kode\tJenis Potong\tHarga Per Potong" << endl;
    cout <<"========================================\n";
    cout <<"D\tDada\t\tRp. 5000.00" << endl;
    cout <<"P\tPaha\t\tRp. 4000.00" << endl;
    cout <<"S\tSayap\t\tRp. 3000.00\n";
     cout <<"========================================\n";

    cout <<"Harga belum termasuk pajak 10%\n";
    cout <<"\nMasukkan Pesanan Anda\n";
    do //menguunakan loop do-while untuk pengulangan
    {
        //input data
        cout <<"Pesanan ke-" << i+1 << "\n";
        cout <<"Jenis [D/P/S]\t: ";
        cin >> gfc[i].kPotong;
        cout <<"Jumlah\t\t: ";
        cin >> gfc[i].jumlah;

        i++; //untuk menambah var i
        cout<<"Apakah anda ingin menambah pesanan? [Y/T]:";
        cin >> ulang;
    } while (ulang=='y'||ulang=='Y');

    cout <<"\nNota Belanja Anda: \n" << endl;
    cout <<"\t\tGEROBAK FRIED CHICKEN\n"<<endl;
    cout <<"==============================================================\n";
    cout <<"No\tJenis Potong\tHarga Satuan\tQty\tJumlah Harga\n";
    cout <<"==============================================================\n";

    for (j=0; j<i; j++) //menggunakan loop for untuk menghitung data
    {
       switch (gfc[j].kPotong) //menggunakan switch untuk cek input data
       {
        case 'D':
        case 'd':
           jPotong="DADA";
           hSatuan = 5000;
           break;
        case 'P':
        case 'p':
           jPotong="PAHA";
           hSatuan = 4000;
           break;
        case 'S':
        case 's':
           jPotong="SAYAP";
           hSatuan = 3000;
           break;
       default:
           cout <<"Kode Menu Tidak Tersedia!";
           break;
       }
       cout <<j+1<<"\t"<<jPotong<<"\t\tRp. "<<hSatuan<<".00"<<"\t"
       <<gfc[j].jumlah<<"\tRp. "<<hSatuan*gfc[j].jumlah<<".00";
       cout <<"\n";
       total+=hSatuan*gfc[j].jumlah;
    }

   cout <<"==============================================================\n";
    cout <<"\t\t\t\tJumlah Bayar\tRp. "<<total<<".00";;
    cout <<"\n\t\t\t\tPajak 10%\tRp. "<<total/10<<".00";
    cout <<"\n\t\t\t\tTOTAL BAYAR\tRp. "<<total*2/10<<".00";;
    cout <<"\n\n\t\tTERIMA KASIH ATAS KUNJUNGAN ANDA\n";
    
    return 0;
}