#include <iostream>
#include <string>

using namespace std;

int totalParking = 0;

struct parking
{
    int rNo, model;
    int eTime[3];
    string Dname, vMake, vColor;
    parking *nptr;
};

void ex(parking *cptr)
{
    parking *h;
    h = cptr->nptr;
    int t[3], carry1 = 0, carry2 = 0, tim;
    cout << "Color : " << cptr->nptr->vColor;
    cout << "\nModel Number : " << cptr->nptr->model;
    cout << "Enter Current Time (hh,mm,ss) : ";
    cin >> t[0];
    cin >> t[1];
    cin >> t[2];
    tim = ((t[0] - cptr->nptr->eTime[0]) * 3600) + ((t[1] - cptr->nptr->eTime[1]) * 60) + t[2] + cptr->nptr->eTime[2];
    if (tim <= 120)
    {
        cout << "Parking Fees Is : Rs. 50\n";
        totalParking += 50;
    }
    else
    {
        cout << "Parking Fees Is : Rs. 70\n";
        totalParking += 70;
    }
    cptr->nptr = cptr->nptr->nptr;
    delete h;
}

parking *fptr = NULL;

int main()
{
    while (true)
    {
        string name, maker, color;
        int r, modal;
        int et[3];
        int choice;
        cout << "Enter a Choice\n1.Entery\n2.Exit of Vehicle\n3.Total parking fee\n";
        cout << "4.All Parked Vehicles\nEnter Choice : ";
        cin >> choice;
        if (choice == 1)
        {
            cin.ignore();
            cout << "Enter Name of Driver : ";
            getline(cin, name);
            cout << "Enter Color Of Vehicle : ";
            getline(cin, color);
            cout << "Enter Vehicle Maker : ";
            getline(cin, maker);
            cout << "Enter Vehicle Registration Number : ";
            cin >> r;
            cout << "Enter Vehicle Modal : ";
            cin >> modal;
            cout << "Enter Current Time (hh,mm,ss) : ";
            cin >> et[0];
            cin >> et[1];
            cin >> et[2];

            parking *ptr;
            ptr = new parking;

            ptr->Dname = name;
            ptr->model = modal;
            ptr->rNo = r;
            ptr->vColor = color;
            ptr->vMake;
            ptr->eTime[0] = et[0];
            ptr->eTime[1] = et[1];
            ptr->eTime[2] = et[2];

            if (fptr == NULL)
            {

                fptr = ptr;
                ptr->nptr = NULL;
            }
            else
            {
                parking *cptr;
                cptr = fptr;

                while (cptr->nptr != NULL)
                {
                    cptr = cptr->nptr;
                }

                cptr->nptr = ptr;
                ptr->nptr = NULL;
            }
        }
        else if (choice == 2)
        {
            int rn;
            cout << "Enter Registration No : ";
            cin >> rn;

            parking *cptr = fptr;
            parking *prev = NULL;
            bool found = false;

            while (cptr != NULL)
            {
                if (cptr->rNo == rn)
                {
                    found = true;
                    if (prev == NULL)
                    {
                        // Deleting the first node
                        ex(cptr);
                        fptr = cptr->nptr;
                        delete cptr;
                    }
                    else
                    {
                        // Deleting a node in the middle or end
                        ex(cptr);
                        prev->nptr = cptr->nptr;
                        delete cptr;
                    }
                    break;
                }
                prev = cptr;
                cptr = cptr->nptr;
            }

            if (!found)
            {
                cout << "Vehicle not found\n";
            }
        }

        parking *p;
        p = fptr;
        cout << "LIST\n";
        while (p != NULL)
        {
            cout << p->rNo << "  ";
            p = p->nptr;
        }
        cout << "\nEnd\n";
    }
}
