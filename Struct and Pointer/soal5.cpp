#include <iostream>
using namespace std;

struct bilangan //membuat struct bilangan
{
    float a;
    float b;
    float c;
    float d;
};
//deklarasi prototype function
int jumlah(int a, int b, int c, int d);
int kurang(int a, int b, int c, int d);
int kali(int a, int b, int c, int d);
float bagi(float a, float b, float c, float d);

struct bilangan number; //deklarasi variabel number

int main(){
    //deklarasi var int menu
    int menu; 

    cout<<"Program Penghitung Bilangan Kompleks"<<endl;
    cout<<"=======================================\n";
    cout<<"Masukkan bilangan 1: ";
    cin>>number.a;
    cout<<"Masukkan bilangan 2: ";
    cin>>number.b;
    cout<<"Masukkan bilangan 3: ";
    cin>>number.c;
    cout<<"Masukkan bilangan 4: ";
    cin>>number.d;
    
    //menampilkan menu
    cout<<"\nBerikut pilihan menu penghitungan:\n";
    cout<<"1. Penjumlahan \n";
    cout<<"2. Pengurangan \n";
    cout<<"3. Perkalian \n";
    cout<<"4. Pembagian \n";
    //memilih menu penghitungan
    cout<<"\nSilahkan pilih menu penghitungan(1-4): ";
    cin>>menu;

    switch (menu) //menggunakan switch untuk pilihan menu
    {
    case 1:
        jumlah(number.a,number.b,number.c,number.d);
        break;
    case 2:
        kurang(number.a,number.b,number.c,number.d);
        break;
    case 3:
        kali(number.a,number.b,number.c,number.d);
        break;
    case 4:
        bagi(number.a,number.b,number.c,number.d);
        break;  
    default:
        cout<<"Pilihan tidak tersedia!"<<endl;
        exit(0);//jika pilihan salah, maka program akan berhenti
        break;
    }

    return 0;
}
//membuat func jumlah
int jumlah(int a, int b, int c, int d){
    int gas1, gas2;
    gas1 = a + c;
    gas2 = b + d;

    cout<<"Hasil Penjumlahan ("<<a<<" + "<<b<<"i)"<<" + "<<"("<<c<<" + "<<d<<"i)"<<" = ("
    <<a<<" + "<<c<<") + ("<<b<<" + "<<d<<")i adalah "<<gas1<<" + "<<gas2<<"i";
    return 0;
}
//membuat func kurang
int kurang(int a, int b, int c, int d){
    int gas1, gas2;
    gas1 = a - c;
    gas2 = b - d;

    cout<<"Hasil Pengurangan ("<<a<<" + "<<b<<"i)"<<" - "<<"("<<c<<" + "<<d<<"i)"<<" = ("
    <<a<<" - "<<c<<") + ("<<b<<" - "<<d<<")i adalah "<<gas1<<" + "<<gas2<<"i";
    return 0;
}
//membuat fucn kali
int kali(int a, int b, int c, int d){
    int gas1, gas2;
    gas1 = (a*c) - (b*d);
    gas2 = (a*d) + (b*c);

    cout<<"Hasil Perkalian ("<<a<<" + "<<b<<"i)"<<" * "<<"("<<c<<" + "<<d<<"i)"<<" = ("
    <<a<<"*"<<c<<" - "<<b<<"*"<<d<<")"<<" + "<<"("<<a<<"*"<<d<<" + "<<b<<"*"<<c<<")i"<<"adalah" 
    <<gas1<<" + "<<gas2<<"i";
    return 0;
}
//membuat func bagi
float bagi(float a, float b, float c, float d){
    float gas1, gas2, gas3, gas4;
    float hasil1, hasil2;
    gas1 = (a*c) + (b*d);
    gas2 = (a*a) + (b*b);
    gas3 = (b*c) - (a*d);
    gas4 = (c*c) + (d*d);
    hasil1 = gas1/gas2;
    hasil2 = gas3/gas4;

    cout<<"Hasil Pembagian ("<<a<<" + "<<b<<"i)"<<" / "<<"("<<c<<" + "<<d<<"i)"<<" = [("
    <<a<<"*"<<c<<" + "<<b<<"*"<<d<<")"<<" / "<<"("<<a<<"*"<<a<<" + "<<b<<"*"<<c<<")]"<<"[("
    <<b<<"*"<<c<<" - "<<a<<"*"<<d<<")"<<" / "<<"("<<c<<"*"<<c<<" + "<<d<<"*"<<d<<")]"<<"i adalah\n"
    <<"[("<<gas1<<" / "<<gas2<<")] + "<<"[("<<gas3<<" / "<<gas4<<")]"<<" = "<<hasil1<<
    " + "<<hasil2<<"i";   
    return 0;
}