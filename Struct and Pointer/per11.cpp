#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct dtnilai {
    char nrp[10];
    char nama[20];
    double nilai;
};

struct dtnilai data[10];
int j=0;
void tambah_data();
void tampil();

int main() {
    tambah_data();
    tampil();
    return 0;
}

void tambah_data(){
    char jawab[2];
    while(1)
    {
        fflush(stdin);
        cout <<"NRP: "; cin>>data[j].nrp;
        cout <<"Nama: "; cin>>data[j].nama;
        cout <<"Nilai Test: "; cin>>data[j].nilai;
        cout <<"Ada data lagi (Y/T): "; cin>>jawab;
    
        if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0))
        {
            j++;continue;
        } 
        else if ((strcmp(jawab,"T")==0)||(strcmp(jawab,"t")==0))
            break; 
    }
}

void tampil()
{
    int i;
    cout<<"Data Mahasiswa yang telah diinputkan :\n";
    cout<<"NRP\tNama\tNilai\n";

    for (i=0;i<=j;i++)
    {
        cout << data[i].nrp <<"\t"<< data[i].nama <<"\t"<< data[i].nilai;
    }
}