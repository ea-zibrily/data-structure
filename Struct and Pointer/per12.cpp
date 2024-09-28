#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

void tampil(struct dtnilai *p);
struct dtnilai
{
    char nrp[10];
    char nama[20];
    double nilai;
};

struct dtnilai my_struct;
int main()
{
    struct dtnilai *st_ptr;

    st_ptr = &my_struct;
    strcpy(my_struct.nrp,"01");
    cout <<"\n"<<my_struct.nrp;

    strcpy(my_struct.nama,"Arini");
    cout <<"\n"<<my_struct.nama;
    my_struct.nilai = 63.6;
    cout<<endl;
    tampil(st_ptr);

    return 0;
}

void tampil(struct dtnilai *p)
{
    cout<<"\nNRP: "<<p->nrp;
    cout<<"\nNama: "<<p->nama;
    cout<<"\nNilai: "<<p->nilai;
}