#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct simpul NODE;
struct simpul
{
    string nama;
    int nrp;
    NODE *next;
    NODE *prev;
};

NODE *head;
NODE *tail;

void inisiate()
{
    head = NULL;
    tail = NULL;
}

bool isEmpty()
{
    if (head == NULL && tail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

NODE *alokasi_simpul(string nama, int nrp)
{
    NODE *data;
    data = (NODE *)malloc(sizeof(NODE));
    data->nama = nama;
    data->nrp = nrp;
    if (data == NULL)
    {
        return NULL;
    }
    else
    {
        data->next = NULL;
        data->prev = NULL;
        return data;
    }
}

void addFirst(string nama, int nrp)
{
    NODE *data = alokasi_simpul(nama, nrp);
    if (isEmpty())
    {
        head = tail = data;
    }
    else
    {
        data->next = head;
        head->prev = data;
        head = data;
    }
}

void addLast(string nama, int nrp)
{
    NODE *data = alokasi_simpul(nama, nrp);
    if (isEmpty())
    {
        head = tail = data;
    }
    else
    {
        tail->next = data;
        data->prev = tail;
        tail = data;
    }
}

void findNode(string nama, int nrp)
{
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
            temp = temp->next;
        }
        cout << nama << " tidak ada dalam Linked List ini!." << endl;
    }
}

void cetakFIFO()
{
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

        temp = temp->next;
    }
}

void cetakLIFO()
{
    NODE *temp = tail;
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

        temp = temp->prev;
    }
}

void removeFirst()
{
    NODE *hapus = head;
    if (hapus->nama == head->nama)
    {
        head = head->next;
        head->prev = NULL;
        free(hapus);
    }
}

void removeLast(string nama, int nrp)
{
    NODE *hapus = head;
    while (hapus->nama != nama && hapus->nrp != nrp)
        hapus = hapus->next;
    if (hapus->nama == tail->nama)
    {
        tail = tail->prev;
        tail->next = NULL;
        free(hapus);
    }
}

void removeCenter(string nama, int nrp)
{
    NODE *hapus = head;
    while (hapus->nama != nama && hapus->nrp != nrp)
    {
        hapus = hapus->next;
    }
    hapus->prev->next = hapus->next;
    hapus->next->prev = hapus->prev;
    free(hapus);
}


int main()
{
//deklarasi variabel
    string nama;
    int menu, nrp;
    char pilih;

    cout << "DOUBLE LINKED LIST IMPLEMENTATION PROGRAM" << endl;
    cout << "===========================================\n";
    do
    {
        cout << "Silahkan memilih menu Linked List\n";
        cout << "1. Input First Node\n";
        cout << "2. Input Last Node\n";
        cout << "3. Cetak FIFO\n";
        cout << "4. Cetak LIFO\n";
        cout << "5. Cari Data\n";
        cout << "6. Hapus First Node\n";
        cout << "7. Hapus Last Node\n";
        cout << "8. Hapus Center Node\n";
        cout << "9. Keluar\n";
        cout << "==================================\n";
        cout << "Masukkan pilihan anda(1-9): ";
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
            cout << "\nMasukkan data" << endl;
            cout << "Nama : ";
            cin >> nama;
            cout << "NRP  : ";
            cin >> nrp;
            addLast(nama, nrp);
            break;
        case 3:
            cetakFIFO();
            break;
        case 4:
            cetakLIFO();
            break;
        case 5:
            cout << "Masukkan data yang ingin dicari!" << endl;
            cout << "Nama : ";
            cin >> nama;
            cout << "NRP  : ";
            cin >> nrp;
            cout << "==================\n";
            findNode(nama, nrp);
            break;
        case 6:
            removeFirst();
            break;
        case 7:
            cout << "Masukkan data terakhir yang ingin dihapus" << endl;
            cout << "Nama : ";
            cin >> nama;
            cout << "NRP  : ";
            cin >> nrp;
            cout << "==================\n";
            removeLast(nama, nrp);
            cout << "Data berhasil dihapus!\n";
            break;
        case 8:
            cout << "Masukkan data yang ingin dihapus!" << endl;
            cout << "Nama : ";
            cin >> nama;
            cout << "NRP  : ";
            cin >> nrp;
            cout << "==================\n";
            removeCenter(nama, nrp);
            cout << "Data berhasil dihapus!\n";
            break;
         case 9:
            exit(0);
            break;
        default:
            cout << "Pilihan anda salah!\nSilahkan mengisi kembali." << endl;
            break;
        }

        cout << "\nApa anda ingin mengisi lagi? (Y/T): ";
        cin >> pilih;
        cout << "==================================\n";
    } while (pilih == 'Y' || pilih == 'y');
    
    return 0;
}

/*#include <iostream>
using namespace std;

struct Player
{
    string name;
    int score;

    Player *next, *prev;
};
Player *head, *tail;

void initialization()
{
    head = tail = NULL;
}

bool isEmpty()
{
    if (head == NULL && tail == NULL)
        return true;
    else
        return false;
}

Player *createPlayer(string name, int score)
{

    Player *New;
    New = new Player;

    New->name = name;
    New->score = score;
    New->next = NULL;
    New->prev = NULL;

    return New;
}

void print()
{
    Player *temp = head;
    cout << "========================================================\n";
    cout << "Index\tName\t\t\t\tScore\n";
    cout << "========================================================\n";

    if (temp == NULL)
        cout << "No Data found!\n";

    for (int i = 0; temp != NULL; i++)
    {
        cout << i << "\t" << temp->name << "\t\t\t\t" << temp->score << "\n";
        temp = temp->next;
    }

    cout << "========================================================\n";
    string headName = (head) ? head->name : "none";
    string tailName = (tail) ? tail->name : "none";
    cout << "Head\t: " << headName << "\n"
         << "Tail\t: " << tailName << "\n";
    cout << "========================================================\n";
}

void addFirst(string name, int score)
{
    Player *Data = createPlayer(name, score);
    if (isEmpty())
        head = tail = Data;
    else
    {
        Data->next = head;
        head->prev = Data;
        head = Data;
    }
}

void addLast(string name, int score)
{
    Player *Data = createPlayer(name, score);
    if (isEmpty())
        head = tail = Data;
    else
    {
        tail->next = Data;
        Data->prev = tail;
        tail = Data;
    }
}

void findIndex(string name)
{
    if (isEmpty())
    {
        cout << "Err\t: You don't have any data!\n";
        return;
    }
    else
    {
        Player *temp = head;
        for (int index = 0; temp != NULL; index++)
        {
            if (temp->name == name)
            {
                cout << "Msg\t: Data found!\n"
                     << "Data\t: \n{\n  index\t: " << index << "\n}\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Err\t: Data Not Found!\n";
        return;
    }
}

void addAfterIndex(int index, string name, int score)
{
    Player *node = head;

    if (isEmpty())
    {
        addFirst(name, score);
        return;
    }

    for (int i = 0; node != NULL; i++)
    {
        if (i == index)
        {

            if (node->next == NULL)
            {
                addLast(name, score);
                return;
            }

            Player *Data = createPlayer(name, score);
            Data->prev = node;
            Data->next = node->next;
            node->next = Data;
            return;
        }
        node = node->next;
    }
}

void printAtIndex(int index)
{
    Player *temp = head;

    for (int i = 0; temp != NULL; i++)
    {
        if (i == index)
        {
            cout << "Msg\t: Data found!\n"
                 << "Data\t: \n{\n  name\t: " << temp->name
                 << "\n  score\t: " << temp->score
                 << "\n}\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Err\t: Data not found!\n";
}

void removeFirst()
{
    if (isEmpty())
        cout << "Err\t: You don't have any data!\n";
    else
    {

        Player *temp = head;

        if (temp->next == NULL && temp->prev == NULL)
        {
            head = tail = NULL;
            free(temp);
            return;
        }

        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void removeLast()
{
    if (isEmpty())
        cout << "Err\t: You don't have any data!\n";
    else
    {
        if (tail->prev == NULL)
        {
            head = tail = NULL;
            free(tail);
            return;
        }

        Player *temp = tail->prev;
        free(tail);
        tail = temp;
        tail->next = NULL;
    }
}

void removeAtIndex(int index)
{
    if (isEmpty())
        cout << "Err\t: You don't have any data!\n";
    else
    {
        Player *node = head;

        for (int i = 0; node != NULL; i++)
        {
            if (i == index)
            {
                Player *temp, *temp2;

                if (node->next == NULL && node->prev == NULL)
                {
                    head = tail = NULL;
                    free(node);
                    return;
                }

                if (node->next == NULL)
                {
                    removeLast();
                    return;
                }

                if (node->prev == NULL)
                {
                    removeFirst();
                    return;
                }

                temp = node->next;
                temp2 = node->prev;
                temp->prev = temp2;
                temp2->next = temp;
                free(node);
                return;
            }
            node = node->next;
        }
        cout << "Err\t: Data not found!\n";
        return;
    }
}

int main()
{
    initialization();
    while (true)
    {
        system("clear");
        cout << "Hello! Welcome to Temporary Player Database!\n";
        print();

        cout << "\n1. Find Index\n"
             << "2. Add First\n"
             << "3. Add Last\n"
             << "4. Add After Index\n"
             << "5. Print At Index\n"
             << "6. Remove First\n"
             << "7. Remove Last\n"
             << "8. Remove At Index\n"
             << "Ctrl + C to Exit\n";

        int ans;
        cout << "Choose Method\t: ";
        cin >> ans;

        switch (ans)
        {
        case 1:
        {
            cout << "\nFIND INDEX\n";
            string name;
            cout << "Name\t: ";
            cin >> name;
            findIndex(name);

            string con;
            cout << "\nInput anything to Continue! ";
            cin >> con;

            break;
        }

        case 2:
        {
            cout << "\nADD FIRST\n";

            string name;
            int score;

            cout << "Name\t: ";
            cin >> name;
            cout << "Score\t: ";
            cin >> score;
            addFirst(name, score);

            break;
        }

        case 3:
        {
            cout << "\nADD LAST\n";

            string name;
            int score;

            cout << "Name\t: ";
            cin >> name;
            cout << "Score\t: ";
            cin >> score;
            addLast(name, score);

            break;
        }

        case 4:
        {
            cout << "\nADD AFTER INDEX\n";

            string name;
            int index, score;

            cout << "Index\t: ";
            cin >> index;
            cout << "Name\t: ";
            cin >> name;
            cout << "Score\t: ";
            cin >> score;
            addAfterIndex(index, name, score);

            break;
        }

        case 5:
        {
            cout << "\nPRINT AT INDEX\n";

            int index;

            cout << "Index\t: ";
            cin >> index;
            printAtIndex(index);

            string con;
            cout << "\nInput anything to Continue! ";
            cin >> con;

            break;
        }

        case 6:
        {
            removeFirst();

            break;
        }
        case 7:
        {
            removeLast();
            break;
        }
        case 8:
        {
            cout << "\nREMOVE AT INDEX\n";
            int index;
            cout << "Index\t: ";
            cin >> index;
            removeAtIndex(index);

            break;
        }

        default:
            break;
        }
    }
}*/