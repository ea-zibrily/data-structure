#include <iostream>
//menggunakan library stdlib.h karena ingin memanggil free dan malloc
#include <stdlib.h>
using namespace std;

typedef struct simpul NODE; //membuat inisal struct simpul
struct simpul
{
  string nama;
  int nrp;
  NODE *next;
};
//deklarasi head dan tail untuk menentukan NULL Linked List
NODE *head;
NODE *tail;
//membuat func inisiate
void inisiate()
{
  head = NULL;
  tail = NULL;
}
//membuat func isEmpty untuk pengecekan head dan tail
bool isEmpty()
{
  if (head == NULL && tail == NULL)
  {
    return 1;
  }
  else
    return 0;
}
//membuat func *alokasi_simpul
NODE *alokasi_simpul(string nama, int nrp)
{
  NODE *data;
  //menggunakan malloc
  data = (NODE *)malloc(sizeof(NODE));
  //menentukan data nama, data nrp, data next
  data->nama = nama;
  data->nrp = nrp;
  data->next == NULL;
  //menggunakan if else untuk menentukan NULL data
  if (data == NULL)
  {
    return NULL;
  }
  else
  {
    data->next = NULL;
  }
  return data;
}
//membuat func addFirst NODE
void addFirst(string nama, int nrp)
{
  //membuat var *data dan memanggil alokasi_simpul;
  NODE *data = alokasi_simpul(nama, nrp);
  if (isEmpty())
  {
    head = tail = data;
  }
  else
  {
    data->next = head;
    head = data;
  }
  free(data); //menggunakan free untuk menghapus data
}
//membuat func addLast NODE
void addLast(string nama, int nrp)
{
  //membuat var *data dan memanggil alokasi_simpul;
  NODE *data = alokasi_simpul(nama, nrp);
  if (isEmpty())
  {
    head = tail = data;
  }
  else
  {
    tail->next = data;
    tail = data;
  }
  free(data); //menggunakan free untuk menghapus data
}
//membuat func findNode
void findNode(string nama, int nrp)
{
  //membuat var *temp yang beralamat di head
  NODE *temp = head;
  int i;

  if (isEmpty())
  {
    cout << "Linked List ini Kosong!\nTidak bisa menampilkan data.";
  }
  else
  {
    for (i = 0; temp != NULL; i++)
    {
      if (temp->nama == nama && temp->nrp == nrp)
      {
        cout << nama << " ada pada index ke-" << i << endl;
        cout << "Nama : " << nama << endl;
        cout << "NRP  : " << nrp << endl;
        return;
      }
      temp = temp->next; //mengatur alamat temp agar berpindah
    }
    cout << nama << " tidak ada dalam Linked List ini!." << endl;
  }
  free(temp); //membuat var *temp yang beralamat di head
}
//membuat func cetaks
void cetakss()
{
  //membuat var *temp yang beralamat di head
  NODE *temp = head;
  int i;
  if (temp == NULL)
  {
    cout << "Linked List masih kosong!\nTidak bisa menampilkan data.";
    return;
  }
  for (i = 0; temp != NULL; i++)
  {
    cout << "Data pada index ke-" << i << endl;
    cout << "Nama : " << temp->nama << endl;
    cout << "NRP  : " << temp->nrp << endl;
    cout << endl;

    temp = temp->next; //mengatur alamat temp agar berpindah
  }
}

int main()
{
  //deklarasi variabel
  string nama;
  int menu, nrp;
  char pilih;

  cout << "SINGLE LINKED LIST IMPLEMENTATION PROGRAM" << endl;
  cout << "===========================================\n";
  do
  {
    cout << "Silahkan memilih menu Linked List\n";
    cout << "1. Input First Node\n";
    cout << "2. Cetak Data\n";
    cout << "3. Cari Data\n";
    cout << "4. Input Last Node\n";
    cout << "5. Keluar\n";
    cout << "==================================\n";
    cout << "Masukkan pilihan anda(1-5): ";
    cin >> menu;
    //menggunakan switch
    switch (menu)
    {
    case 1:
      cout << "\nMasukkan data" << endl;
      cout << "Nama : ";
      cin >> nama;
      cout << "NRP  : ";
      cin >> nrp;
      addFirst(nama, nrp);
      break;
    case 2:
      cetakss();
      break;
    case 3:
      cout << "Masukkan data yang ingin dicari!" << endl;
      cout << "Nama : ";
      cin >> nama;
      cout << "NRP  : ";
      cin >> nrp;
      cout << "==================\n";
      findNode(nama, nrp);
      break;
    case 4:
      cout << "\nMasukkan data" << endl;
      cout << "Nama : ";
      cin >> nama;
      cout << "NRP  : ";
      cin >> nrp;
      addLast(nama, nrp);
      break;
    case 5:
      exit(0);
      break;
    default:
      cout << "Pilihan anda salah!\nSilahkan mengisi kembali." << endl;
      break;
    }

    cout << "\nApa anda ingin mengisi lagi? (Y/T): ";
    cin >> pilih;
    cout << "==================================\n";
  } while (pilih == 'Y' || 'y');

  return 0;

}


/*
#include <iostream>
#include <stdlib.h>
#define max 5
using namespace std;
typedef struct simpul NODE;

struct simpul
{
    char nama[30];
    int nrp;
    NODE *next;
};
NODE *ujung;
NODE *baru;
int j;

NODE *alokasi_simpul()
{
    baru = (NODE *)malloc(sizeof(NODE));
    if (baru == NULL)
        return NULL;
    else
        baru->next = NULL;
    return baru;
}

void nodeAwal(NODE *tampung)
{
    ujung = alokasi_simpul();
    if (ujung == NULL)
    {
        cout << "Alokasi Gagal!" << endl;
    }
    else
    {
        cout << "Nama : ";
        cin >> ujung->nama;
        cout << "NRP  : ";
        cin >> ujung->nrp;
        if (j == 0)
        {
            tampung = ujung;
        }
        else
        {
            ujung->next = tampung;
            tampung = ujung;
        }
    }
    free(tampung);
}

void cetakss(NODE *tampil)
{
    tampil = ujung;

    while (tampil != NULL)
    {
        cout << "Nama : " << tampil->nama << endl;
        cout << "NRP  : " << tampil->nrp;
        tampil = tampil->next;
    }
}

void carigan(NODE *cari, NODE *tampil)
{
    cari = ujung;
    while (cari->nama != cari->nama)
    {
        cari = cari->next;
    }
    cetakss(tampil);
}

void nodeAkhir(NODE *cari, NODE *tampil)
{
    baru = alokasi_simpul();
    cari = ujung;
    while (cari->next != NULL)
    {
        cari = cari->next;
    }
    cari->next = baru;
}

int main()
{
    int menu;
    char pilih;
    char name2;
    NODE tampung;
    NODE cari;
    NODE tampil;

    cout << "SINGLE LINKED LIST IMPLEMENTATION PROGRAM" << endl;
    cout << "===========================================\n";
    do
    {
        cout << "Silahkan memilih menu Linked List\n";
        cout << "1. Input Data\n";
        cout << "2. Cetak Data\n";
        cout << "3. Cari Data\n";
        cout << "4. Last Data\n";
        cout << "5. Keluar\n";
        cout << "==================================\n";
        cout << "Masukkan pilihan anda(1-5): ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            nodeAwal(&tampung);
            break;
        case 2:
            cetakss(&tampil);
            break;
        case 3:
            carigan(&cari, &tampil);
            break;
        case 4:
            nodeAkhir(&cari, &tampil);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<"Pilihan anda salah!\nSilahkan mengisi kembali."<<endl;
            break;
        }

        cout << "\nApa anda ingin mengisi lagi? (Y/T): ";
        cin >> pilih;
        cout << "==================================\n";
    } while (pilih == 'Y' || 'y');

    return 0;
}

*/