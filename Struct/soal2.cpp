#include <iostream>
using namespace std;

struct date //membuat struct date
{
    int day;
    int month;
    int year;
};

struct date today; //deklarasi var today & tomorrow
struct date tomorrow;
int daypermonth (int month, int year); //prototype func daypermonth

int main(){
    int i; //deklasi var i dan ulang
    char ulang;
    cout <<"\t MENAMPILKAN TANGGAL BESOK HARI" << "\n" << endl;
    do //menggunakan loop do-while untuk menentukan pengulangan
    {
    cout <<"Masukkan tanggal hari ini(dd-mm-yyyy): ";
    cin >> today.day >> today.month >> today.year;  //input data
    //menggunakan if untuk memfilter data
    if (today.day<1 || today.day>31 || today.month<1 || today.month>12 || today.year<1)
    {
        cout << "EROR - Tanggal yang anda masukkan salah!";
    }
    //menggunakan else if untuk menentukan tahun kabisat
    else if (today.month == 2 && (today.year%4!=0 || today.year%400!=0))
    {
            if (today.day > 28)
            {
                cout << "EROR - Bukan tahun kabisat!";
            }
    }

    //menggunakan if untuk menentukan akhir bulan/tahun
    if (today.day >= daypermonth(today.month, today.year))
    {
        if (today.month == 12)
        {
            tomorrow.day = 1;
            tomorrow.month = 1;
            tomorrow.year = today.year+1;
        }
        else
        {
            tomorrow.day = 1;
            tomorrow.month = today.month+1;
            tomorrow.year = today.year;
        }        
    }
    else //menambahkan else untuk menentukan tanggal tomorrow
    {
        tomorrow.day = today.day+1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }

    cout <<"\nTanggal besok (dd-mm-yyyy): " << tomorrow.day << " "<< tomorrow.month << " " << tomorrow.year << endl;
    cout <<"\nApa anda ingin mengulang lagi? (Y/T): ";
    cin >> ulang;
    } while (ulang=='y' || ulang=='Y');

    return 0;
}

//membuat func daypermont dengan parameter month dan year sebagai penentu jumlah tanggal tiap bulannya
int daypermonth (int month, int year)
{
    int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int dayplust = day[month]; //nilai dayplust yaitu nilai dari input data month
    if (month == 2 && (year%4==0 || year%400==0)) //menggunakan if untuk menentukan tahun kabisat
    {
        dayplust = 29;
    }
    return dayplust;
}


