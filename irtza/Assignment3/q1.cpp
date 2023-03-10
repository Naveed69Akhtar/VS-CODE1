#include <iostream>
#include <string>
using namespace std;

struct employee
{
    int id, phone, salary,basicpay;
    string name, adress;
    employee *nptr;
};

float total(float a)
{

}

employee *fptr = NULL;

int main()
{
    int choice;
    cout << "Enter Choice\n1.Add Employee\n3.Check Exisence\n3.Chack Allowance and Total Salary\n";
    cout << "4.Total Database\n";
    cin >> choice;

    if (choice == 1)
    {
            employee* ptr;
			ptr = new employee;
			if (fptr == NULL)
			{
		
				cout << "Enter Name\n";
				cin >> ptr->name;
				
				cin.ignore();
				cout << "Enter ID\n";
				cin >> ptr->id;
				cout << "Enter Basic Pay\n";
				cin >> ptr->basicpay;
				cout << "Enter Adress\n";
				cin >> ptr->adress;
				cout << "Enter Phone Number\n";
				cin >> ptr->phone;
                cin.ignore();
				fptr = ptr;
				ptr->nptr = NULL;
			}
			else
			{
				employee* cptr;
				cptr = fptr;
				while (cptr->nptr != NULL)
				{
					cptr = cptr->nptr;
				}
			employee* ptr;
			ptr = new employee;
				cout << "Enter Name\n";
				cin >> ptr->name;
				
				cin.ignore();
				cout << "Enter ID\n";
				cin >> ptr->id;
				cout << "Enter Basic Pay\n";
				cin >> ptr->basicpay;
				cout << "Enter Adress\n";
				cin >> ptr->adress;
				cout << "Enter Phone Number\n";
				cin >> ptr->phone;
                cin.ignore();
				ptr->nptr = NULL;
				cptr->nptr = ptr;
				cout << "Employee Added Successfully\n";
			}

    }
}