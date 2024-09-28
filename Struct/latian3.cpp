#include <iostream>
#define MAKS 20
using namespace  std;

struct date //definisi global dr tipe date
{ 
    int month;
    int day;
    int year;
};
struct student //definisi global dr tipe student
{ 
    char name[30];
    struct date birthday;
};

struct student data_mhs[MAKS]; //deklarasi global/public dari variabel student

int main()
{
    int i=0, sudah_benar, jml;
    char lagi;
    //memasukkan data
    do
    {
    cout << "Name: ";
    fgets(data_mhs[i].name,sizeof data_mhs[i].name,stdin);

    cout << "Birthday (mm-dd-yyyy): ";
    cin >> data_mhs[i].birthday.day >> data_mhs[i].birthday.month >> data_mhs[i].birthday.year;
    cout << "\n";
    
    i++;
    cout << "Mau memasukkan data lagi [Y/T] ? " << endl;
    do
    {
    lagi = getchar( ); //baca tombol
    sudah_benar = (lagi == 'Y') || (lagi== 'y')||(lagi == 'T') || (lagi == 't');
    } while(!sudah_benar); //!sudah_benar == sudah_benar==false
    //hapus sisa data dalam penampung keyboard
    fflush(stdin);
    cout << "\n";
    } while(lagi == 'Y' || lagi == 'y');
    jml = i;
    //menampilkan data
    cout << "DATA SISWA\n" << endl;
    for (i=0; i<jml; i++)
    {
        cout << i+1 << "Name: " << data_mhs[i].name;
        cout << "Birthday : " << data_mhs[i].birthday.month << data_mhs[i].birthday.day
        << data_mhs[i].birthday.year << "\n\n";
    };
}