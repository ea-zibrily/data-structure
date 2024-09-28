#include <stdio.h>
#include <string.h>
#define MAXSTACK 40
typedef int ItemType;
typedef struct
{
    ItemType item[MAXSTACK];
    int count;
} Stack;
void InisialisasiStack(Stack *s)
{
    s->count = 0;
}
int Kosong(Stack *
               s)
{
    return s->count == 0;
}
int Penuh(Stack *
              s)
{
    return s->count == MAXSTACK;
}
void Push(Stack *
              s,
          ItemType x)
{
    if (Penuh(s))
        printf("Stack penuh! Data tidak dapat masuk!\n");
    else
    {
        s->item[s->count] = x;
        s->count++;
    }
}
ItemType Pop(Stack *
                 s)
{
    ItemType temp = -1;
    if (Kosong(s))
        printf("Stack masih kosong!\n");
    else
    {
        s->count--;
        temp = s->item[s->count];
    }
    return temp;
}
int level(char oper)
{
    if (oper == '^')
        return 4;
    else if (oper == '*' || oper == '/')
        return 3;
    else if (oper == '+' || oper == '-')
        return 2;
    else if (oper == '(')
        return 1;
    else
        return 0;
}
int main()
{
    Stack t;
    char infix[MAXSTACK], temp;
    int i, j;
    InisialisasiStack(&t);
    printf("Masukkan notasi infix: ");
    scanf("%s", &infix);
    for (i = 0; i < strlen(infix); i++)
    {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') ||
            (infix[i] >= '0' && infix[i] <= '9'))
            printf("%c", infix[i]);
        else if (infix[i] == '(')
        {
            Push(&t, infix[i]);
            if (i != 0 && !(infix[i - 1] == '^' ||
                            infix[i - 1] == '*' || infix[i - 1] == '/' || infix[i - 1] == '+' || infix[i - 1] == '-'))
                printf("\nNotasi infix salah, operator tidak lengkap\n");
            char kurung = 't';
            for (j = i; infix[j] != '\0'; j++)
            {
                if (infix[j] == ')')
                {
                    kurung = 'y';
                    break;
                }
            }
            if (kurung == 't')
                printf("\nNotasi infix salah, kurung tidak lengkap\n");
        }
        else if (infix[i] == ')')
        {
            if (!(infix[i - 1] >= '0' && infix[i] <=
                                             '9'))
                printf("\nNotasi infix salah, operand tidak lengkap\n");
            while (t.item[t.count - 1] != '(')
                printf("%c", Pop(&t));
            temp = Pop(&t);
        }
        else if (infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-')
        {
            if (Kosong(&t) || level(t.item[t.count -
                                           1] < level(infix[i])))
                Push(&t, infix[i]);
            else
            {
                while (level(t.item[t.count - 1]) >=
                       level(infix[i]))
                {
                    printf("%c", Pop(&t));
                }
                Push(&t, infix[i]);
            }
        }
        else if (infix[i] == ' ')
            continue;
        else
            printf("Notasi salah\n");
    }
    while (!Kosong(&t))
        printf("%c", Pop(&t));
    return 0;
}