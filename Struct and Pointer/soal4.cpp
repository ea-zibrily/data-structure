#include <iostream>
using namespace std;

struct bil //deklarasi struct bil
{
    int p1;
    int p2;
    int p3;
};

struct bil bilangan[10]; //deklarasi var array bilangan

int main(){
    int i;
    //deklarasi hasil untuk mencetak
    float hasil[11]={0,0,0,0,0,0,0,0,0,0,0}; 
    //mengisi nilai p1-p3
    bilangan[0].p1=15;
    bilangan[1].p1=0;
    bilangan[2].p1=0;
    bilangan[3].p1=1;
    bilangan[4].p1=0;
    bilangan[5].p1=5;
    bilangan[6].p1=0;
    bilangan[7].p1=8;
    bilangan[8].p1=6;
    bilangan[9].p1=0;

    bilangan[0].p2=10;
    bilangan[1].p2=0;
    bilangan[2].p2=2;
    bilangan[3].p2=2;
    bilangan[4].p2=3;
    bilangan[5].p2=0;
    bilangan[6].p2=0;
    bilangan[7].p2=4;
    bilangan[8].p2=0;
    bilangan[9].p2=3;

    bilangan[0].p3=5;
    bilangan[1].p3=1;
    bilangan[2].p3=0;
    bilangan[3].p3=0;
    bilangan[4].p3=0;
    bilangan[5].p3=0;
    bilangan[6].p3=0;
    bilangan[7].p3=0;
    bilangan[8].p3=0;
    bilangan[9].p3=0;

    cout<<"\t Aritmatika Polinom"<<endl;
    cout<<"Diketahui: \n";
    cout<<"\nP1 = 6x^8 + 8x^7 + 5x^5 + x^3 + 15\n";
    cout<<"P2 = 3x^9 + 4x^7 + 3x^4 + 2x^3 + 2x^2 + 10\n";
    cout<<"P3 = x^2 + 5\n";
    cout<<"============================================="<<endl;

    cout<<"Penambahan: ";
    for (i=0; i<10; i++) //menggunakan loop for untuk menambah array hasil
    {
        hasil[i]+=(bilangan[i].p1)+(bilangan[i].p2);
    }
    for (i=10; i>=0; i--) //menggunakan loop for untuk mencetak
    {
       if (hasil[i] == 0)
       {
           continue;
       }
       else if (hasil[i] > 1)
       {
          cout<<" "<<hasil[i]<<"x"<<i<<" + ";
       }
       else if (hasil[i] == 1)
       {
           cout<<" "<<hasil[i]<<"x"<<" + ";
       }
        else if (hasil[i] >= 0)
       {
           cout<<" "<<hasil[i];
       }       
    }
   
    return 0;
}