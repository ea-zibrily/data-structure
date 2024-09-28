#include <iostream>
#define Max 5
using namespace std;

typedef struct stackzz
{
    int item[Max];
    int count;
}STACK;

void inisialisasi (STACK *s){
    s->count = 0;
}

int kosong (STACK *s){
    return(s->count == 0);
}

int penuh (STACK *s){
    return(s->count == Max);
}

int push (STACK *s, int x){
    if(penuh(s)){
        cout<<"Stack Penuh!\nTidak bisa memasukkan data.";
    }
    else{
        s->item[s->count]=x;
        s->count++;
    }
    return 0;
}

int pop(STACK *s){
    int temp;
    if (kosong(s)){
        cout<<"Stack Kosong!\nTidak bisa mengambil data.";
        return ' ';
    }
    else
    {
        s->count--;
        temp = s->item[s->count];
        return temp;
    }
}

int main(){
    STACK stackzzz;
    int i, inputd;
    inisialisasi(&stackzzz);
    
    for (i = 0; i < Max; i++)
    {
        cout<<"Masukkan isi stack ke-"<<i+1<<": ";
        cin>>inputd;
        push(&stackzzz, inputd);
    }
    
    for (i = Max; i > 0 ; i--)
    {
        cout<<"Isi stack ke-"<<i<<": "<<pop(&stackzzz)<<endl;
    }
    
    return 0;
}

