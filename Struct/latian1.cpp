#include <iostream>
#include <string.h>
using namespace std;

struct date //definisi global dari tipe date
{ 
    int month;
    int day;
    int year;
};
struct student //definisi global dari tipe student
{ 
    char name[30];
    struct date birthday;
};

struct student mhs; //deklarasi global/public dari var mhs

int main()
{
    //memberikan nilai kepada field dari struktur mhs
    strcpy(mhs.name, "MUHAMMAD IHSAN");
    mhs.birthday.month = 8;
    mhs.birthday.day = 10;
    mhs.birthday.year = 1970;

    //menampilkan isi semua field dari struktur mhs
    cout << "Name: " << mhs.name << endl;
    cout << "Birthday: " << mhs.birthday.day << "-" << mhs.birthday.month << "-" << mhs.birthday.year;
    return 0;
}