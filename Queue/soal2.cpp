#include <iostream>
#define max 20
using namespace std;
//membuat stack dengan inisial stackz1 dan stackz2
typedef struct stack1
{
    int item[max];
    int top1;
} STACKZ1;

typedef struct stack1
{
    int item[max];
    int top2;
} STACKZ2;

//membuat func inisialisasi s1 dan s2
void inisiate(STACKZ1 *s1){
    s1->top1 = 0;
}
void inisiate(STACKZ2 *s2){
    s2->top1 = 0;
}
//membuat func pengecekan kosong dan penuh s1 dan s2
int isMt1(STACKZ1 *s1){
    return s1->top1 == 0;
}

int isMt2(STACKZ2 *s2){
    return s2->top2 == 0;
}

int isFull1(STACKZ1 *s1){
    return s1->top1 == max;
}

int isFull2(STACKZ2 *s2){
    return s2->top2 == max;
}
//membuat func push 1 dan 2
void push1(STACKZ1 *s1, int x){
    if (isFull1(s1))
    {
        cout<<"Data Kosong.";
    }
    else
        s1->item[s1->top1]=x;
        s1->top1++;
}

int push2(STACKZ2 *s2, int x){
    if (isFull2(s2))
    {
        cout<<"Data Kosong.";
    }
    else
        s1->item[s2->top2]=x;
        s1->top2++;
        
    return x;
}
//membuat func remove
void removeQ()
{
    if (s2.isEmpty())
        repeat
            s2.push(s1.top())
                s1.pop()
                    until(s1.isEmpty())
                        endif
                            s2.pop()
}

int main(){

    return 0;
}