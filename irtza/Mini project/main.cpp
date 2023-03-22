#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct inventory_item
{
    string i_Name;
    int id;
    float price;
    int quantity;
    inventory_item *next_pointer;
};

inventory_item *fptr = NULL;
int main()
{
    int choice;
    while (true)
    {
        cout << "1. Add new Inventory Item\n2. Make an Inventory Sale\n3. Buy Inventory from Supplier\n4. Check Stocks\nChoose One :  ";
        cin >> choice;
        if (choice == 1)
        {
            inventory_item *ptr;
            ptr = new inventory_item;

            cin.ignore();
            cout << "Enter Item Name : ";
            getline(cin, ptr->i_Name);
            cout << "Enter Item Id : ";
            cin >> ptr->id;
            cout << "Enter Price pr Item : ";
            cin >> ptr->price;
            cout << "Enter quantity : ";
            cin >> ptr->quantity;

            ptr->next_pointer = NULL;

            if (fptr == NULL)
            {
                fptr = ptr;
            }
            else
            {
                inventory_item *cptr = fptr;
                while (cptr->next_pointer != NULL)
                {
                    cptr = cptr->next_pointer;
                }
                cptr->next_pointer = ptr;
            }
        }
        else if (choice == 2)
        {
            int temp_quantity, temp_id;
            inventory_item *cptr = fptr;
            cout << "Item Id\tItem Name\n";
            while (cptr != NULL)
            {
                cout << cptr->id << "  \t" << cptr->i_Name << endl;
                cptr = cptr->next_pointer;
            }
            cout << "Enter Id You want to Buy : ";
            cin >> temp_id;

            if (fptr->next_pointer == NULL && temp_id == fptr->id)
            {
            ss:
                cout << "Enter Quantity : ";
                cin >> temp_quantity;
                if (temp_quantity <= fptr->quantity)
                {
                    cout << "Your Total Bill is : Rs." << temp_quantity * fptr->price;
                    cout << "\nThanks for Shoping\n";
                    fptr->quantity -= temp_quantity;
                    if (fptr->quantity == 0)
                    {
                        inventory_item *temp = fptr;
                        fptr = NULL;
                        delete temp;
                    }
                }
                else
                {
                    cout << fptr->quantity << " Stock  Available\nTry Again\n";
                    goto ss;
                }
            }
            else if (fptr->id == temp_id)
            {
            ssss:
                cout << "Enter Quantity : ";
                cin >> temp_quantity;
                if (temp_quantity <= fptr->quantity)
                {
                    cout << "Your Total Bill is : Rs." << temp_quantity * fptr->price;
                    cout << "\nThanks for Shoping\n";
                    fptr->quantity -= temp_quantity;
                    if (fptr->quantity == 0)
                    {
                        inventory_item *temp = fptr;
                        fptr = fptr->next_pointer;
                        delete temp;
                    }
                }
                else
                {
                    cout << fptr->quantity << " Stock  Available\nTry Again\n";
                    goto ss;
                }
            }
            else if (fptr == NULL)
                cout << "No Stock Available\n";
            else
            {
                cptr = fptr;
                while (cptr->next_pointer != NULL)
                {
                    if (temp_id == cptr->next_pointer->id)
                    {
                    s:
                        cout << "Enter Quantity : ";
                        cin >> temp_quantity;
                        if (temp_quantity <= cptr->next_pointer->quantity)
                        {
                            cout << "Your Total Bill is : Rs." << temp_quantity * cptr->next_pointer->price;
                            cout << "\nThanks for Shoping\n";
                            cptr->next_pointer->quantity -= temp_quantity;
                            if (cptr->next_pointer->quantity == 0)
                            {
                                inventory_item *temp = cptr->next_pointer;
                                cptr->next_pointer = cptr->next_pointer->next_pointer;
                                delete temp;
                            }
                            break;
                        }
                        else
                        {
                            cout << cptr->next_pointer->quantity << " Stock Available\n";
                            cout << "Try Again\n";
                            goto s;
                        }
                        cptr = cptr->next_pointer;
                        if (cptr->next_pointer == NULL)
                            cout << "No Such Item Found\n";
                    }
                }
            }
        }
        else if (choice == 3)
        {
            int temp_quantity, temp_id;
            cout << "Enter Id You want to Buy : ";
            cin >> temp_id;
            inventory_item *cptr = fptr;
            while (cptr != NULL)
            {
                if (cptr->id == temp_id)
                {
                sss:
                    cout << "Enter Quantity : ";
                    cin >> temp_quantity;
                    if (temp_quantity > 0)
                    {
                        cptr->quantity += temp_quantity;
                        cout << "Item Added\n";
                        break;
                    }
                    else
                    {
                        cout << "Try Again\n";
                        goto sss;
                    }
                }
                cptr = cptr->next_pointer;
                if (cptr == NULL)
                {
                    cout << "No Such Item Found\n";
                }
            }
        }
        else if (choice == 4)
        {
            inventory_item *cptr = fptr;
            cout << "Avalaible Stock\n";
            cout << "Item Id\tItem Name\tItem Quantity\n";
            while (cptr != NULL)
            {
                cout << setw(7) << cptr->id << setw(9) << cptr->i_Name << setw(13) << cptr->quantity << endl;
                cptr = cptr->next_pointer;
            }
        }
    }
}