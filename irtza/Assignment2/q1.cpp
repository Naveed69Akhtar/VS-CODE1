#include <iostream>
#include <string>
using namespace std;
struct list
{
    string name;
    int rollNo;
    list *nptr;
};
list *fptr = NULL;
int main()
{
    int choice;
    int count = 0;
manue:
    cout << "Enter choice\n";
    cout << "1. Add data\n";
    cout << "2. Search Data\n";
    cout << "3. Display data Data\n";
    cin >> choice;

    if (choice == 1)
    {
        list *ptr;
        ptr = new list;
        if (fptr == NULL)
        {
            fptr = ptr;
            ptr->nptr = NULL;
            cout << "Enter Name\n";
            cin >> ptr->name;
            cin.ignore();
            cout << "Enter RollNo\n";
            cin >> ptr->rollNo;
        }
        else
        {
            list *current = fptr;
            while (current->nptr != NULL)
            {
                current = current->nptr;
            }
            list *ptr = new list;
            current->nptr = ptr;
            ptr->nptr = NULL;
            cout << "Enter Name\n";
            cin.ignore();
            getline(cin, ptr->name);
            cout << "Enter RollNo\n";
            cin >> ptr->rollNo;
        }

        goto manue; // goto statement
    }
    else if (choice == 2)
    {
        int r;
        list *ptr;
        ptr = new list;
        list *current = fptr;
        cout << "Enter RollNo\n";
        cin >> r;
        while (1)
        {
            if (current->rollNo == r)
            {
                cout << "Name : " << current->name << endl;
                cout << "Roll No. : " << current->rollNo << endl;
                break;
            }
            if (current != NULL)
            {
                current = current->nptr;
                continue;
            }
            else
            {
                cout << "No Such Record\n";
                break;
            }
        }
        goto manue;
    }
    else if (choice == 3)
    {
        list *ptr;
        ptr = new list;
        list *current = fptr;
        while (1)
        {
            if (current == NULL)
            {
                break;
            }
            cout << "Name : " << current->name << endl;
            cout << "Roll No. : " << current->rollNo << endl;
            current = current->nptr;
            cout << endl;
        }
        goto manue;
    }
}
