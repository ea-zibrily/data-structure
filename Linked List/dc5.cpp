#include <iostream>
#include <assert.h>
using namespace std;
typedef struct simpul Node;

struct simpul
{
    int data;
    Node *next;
};

void print(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void Pushnew(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void Addend(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

int GetNth(Node *head, int index)
{

    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
    assert(0);
}

int main()
{
    int n, menu, ap;
    char ans;
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    cout << "\t\t\t\t\t\t====================" << endl;
    cout << "\t\t\t\t\t\tLinked List Project" << endl;
    cout << "\t\t\t\t\t\t====================" << endl;
    cout << "Current linked list : ";
    print(head);

    do
    {
        cout << "\n1. Add node" << endl;
        cout << "2. Search for specific node" << endl;
        cout << "3. View Current node" << endl;
        cout << "What do you want to do? ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "\nInput data : ";
            cin >> n;
            cout << "Add to front or back? " << endl;
            cout << "1. Front" << endl;
            cout << "2. Back" << endl;
            cout << "Input : ";
            cin >> ap;
            if (ap == 1)
            {
                Pushnew(&head, n);
            }
            else if (ap == 2)
            {
                Addend(&head, n);
            }
            break;
        case 2:
            int i;
            cout << "Which index dou you want to search? ";
            cin >> i;
            cout << "\nElement at index " << i << " is " << GetNth(head, i);
            break;
        case 3:
            cout << "Current linked list data: ";
            print(head);
            break;
        default:
            cout << "Wrong code, please input correct codes." << endl;
            break;
        }

        cout << "\nAgain? (y/t)";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');

    cout << "Linked list after changes : ";
    print(head);
    return 0;
}
