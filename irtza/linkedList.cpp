#include <iostream>
#include <string>
using namespace std;
struct list
{

    string car, name;
    list *nptr;
};
list *fptr = NULL;
int main()
{
    list *ptr;
    ptr = new list;

    if (fptr == NULL)
    {
        cout << "Enter Name\n";
        cin >> ptr->name;
        cout << "Enter Car\n";
        cin >> ptr->car;
        ptr->nptr == NULL;
        fptr = ptr;
    }
    else
    {
        list *currentPTR = fptr;
        while (currentPTR != NULL)
        {
            currentPTR = currentPTR->nptr;
        }
        cout << "Enter Name\n";
        cin >> ptr->name;
        cout << "Enter Car\n";
        cin >> ptr->car;
        currentPTR->nptr = ptr;
        ptr->nptr == NULL;
    }

    return 0;
}