
//fehfkskfhskfhkefksfhkhfkshf

#include <iostream>
#include <string>
using namespace std;

struct employee
{
	int id, phone, salary, basicpay;
	string name, adress;
	employee *nptr;
};

float total(float a)
{
	float q = 0;
	q = a + (45 * a / 100) + (5 * a / 100) + (10 * a / 100);
	return q;
}

employee *fptr = NULL;

int main()
{
	while (1)
	{
		int choice;
		cout << "Enter Choice\n1.Add Employee\n2.Check Exisence\n3.Chack Allowance and Total Salary\n";
		cout << "4.Total Database\n";
		cin >> choice;

		if (choice == 1)
		{
			employee *ptr;
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
				ptr->salary = total(ptr->basicpay);
				fptr = ptr;
				ptr->nptr = NULL;
			}
			else
			{
				employee *cptr;
				cptr = fptr;
				while (cptr->nptr != NULL)
				{
					cptr = cptr->nptr;
				}
				employee *ptr;
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
				ptr->salary = total(ptr->basicpay);
				ptr->nptr = NULL;
				cptr->nptr = ptr;
				cout << "Employee Added Successfully\n";
			}
		}
		else if (choice == 2)
		{
			int emp, flag = 0;
			cout << "Enter Employee ID\n";
			cin >> emp;
			employee *cptr = fptr;
			while (cptr != NULL)
			{
				if (emp == cptr->id)
				{
					flag++;
					cout << "Name : " << cptr->name << endl;
					cout << "ID : " << cptr->id << endl;
					cout << "Address : " << cptr->adress << endl;
					cout << "Phone Number : " << cptr->phone << endl;
					cout << "***********************\n";
				}
				cptr = cptr->nptr;
			}
			if (flag == 0)
			{
				cout << "No Such Entery Found\n";
				cout << "*************************\n";
			}
		}
		else if (choice == 3)
		{
			int emp, flag = 0;
			cout << "Enter Employee ID\n";
			cin >> emp;
			employee *cptr = fptr;
			while (cptr != NULL)
			{
				if (emp == cptr->id)
				{
					flag++;
					cout << "Name : " << cptr->name << endl;
					cout << "ID : " << cptr->id << endl;
					cout << "Basic Pay : " << cptr->basicpay << endl;
					cout << "Allowance : " << cptr->salary - cptr->basicpay << endl;
					cout << "Total Salary : " << cptr->salary << endl;
					cout << "***********************\n";
				}
				cptr = cptr->nptr;
			}
			if (flag == 0)
			{
				cout << "No Such Entery Found\n";
				cout << "*************************\n";
			}
		}
		else if (choice == 4)
		{
			int flag = 0;
			employee *cptr = fptr;
			while (cptr != NULL)
			{
				flag++;
				cout << "Name : " << cptr->name << endl;
				cout << "ID : " << cptr->id << endl;
				cout << "Address : " << cptr->adress << endl;
				cout << "Phone Number : " << cptr->phone << endl;
				cout << "Basic Pay : " << cptr->basicpay << endl;
				cout << "Allowance : " << cptr->salary - cptr->basicpay << endl;
				cout << "Total Salary : " << cptr->salary << endl;
				cout << "***********************\n";

				cptr = cptr->nptr;
			}
			if (flag == 0)
			{
				cout << "No Such Entery Found\n";
				cout << "*************************\n";
			}
		}
	}
}
