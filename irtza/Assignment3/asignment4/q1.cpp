/*
Task 2 - [CLO-1]
Write a Complete & Efficient C++ code, with menu as following:
1. Add Value – Takes input of single integer value from user and adds it into
the linked list in ascending order. [All entries are maintained in same way]
2. Find Value – User enters value to find, program to traverse entire linked list
and display the value if found in Linked list, else display message “Value not
found in Linked List”
3. Delete Value – User enters value to delete, program searches for value and
deletes the node from linked list. [*Use of delete operator to free the
dynamic memory]
4. Print All Values – Displays all values in linked list
struct input_array
{
int value;
input_array* nptr;
};
input_array *fptr=NULL;

*/

#include <iostream>
#include <string>
using namespace std;

struct list
{
    int data;
    list *nptr;
};

list *fptr = NULL;

int main()
{
    while (true)
    {

        int choice, val;

        cout << "Enter Choice : ";
        cout << "\n1.Add Value\n2.Search Value\n3.Delete Value\n4.Display All : ";
        cin >> choice;
        if (choice == 1)
        {
            list *ptr;
            ptr = new list;
            cout << "Enter Value : ";
            cin >> val;
            if (fptr == NULL)
            {
                ptr->data = val;
                ptr->nptr = NULL;
                fptr = ptr;
            }
            else if (val < fptr->data)
            {
                ptr->data = val;
                ptr->nptr = fptr;
                fptr = ptr;
            }
            else if (val > fptr->data && fptr->nptr == NULL)
            {
                ptr->data = val;
                ptr->nptr = NULL;

                fptr->nptr = ptr;
            }
            else
            {
                list *cptr;
                cptr = fptr;
                while (cptr->nptr != NULL)
                {
                    if (cptr->nptr->data > val)
                    {
                        ptr->data = val;
                        ptr->nptr = cptr->nptr;
                        cptr->nptr = ptr;
                        break;
                    }
                    cptr = cptr->nptr;
                    if (cptr->nptr == NULL)
                    {
                        ptr->data = val;
                        cptr->nptr = ptr;
                        ptr->nptr = NULL;
                        break;
                    }
                }
            }
        }
        else if (choice == 2)
        {
            int count = 0;
            cout << "Enter Value to Search : ";
            cin >> val;
            list *currentptr;
            currentptr = fptr;
            while (currentptr != NULL)
            {
                count++;
                if (currentptr->data == val)
                {
                    cout << val << " Found at " << count << "th Place\n";
                    break;
                }
                currentptr = currentptr->nptr;
                if (currentptr == NULL)
                {
                    cout << "No Such Value Found\n";
                }
            }
        }
        else  if(choice==3)
        {
            cout<<"Enter Value to Delete : ";
            cin>>val;
             list *currentptr;
            currentptr = fptr;
            while (currentptr != NULL)
            {
              if(currentptr==fptr&&currentptr->data==val)
                    {
                        fptr=currentptr->nptr;
                        delete currentptr;
                        break;
                    }
                else if (currentptr->nptr->data == val)
                {
                    
                    currentptr->nptr=currentptr->nptr->nptr;
                   //delete currentptr->nptr;
                    break;
                }
                currentptr = currentptr->nptr;
                if (currentptr->nptr == NULL)
                {
                    cout << "No Such Value Found\n";
                }
            }
        }
        else if (choice == 4)
        {
            int count=0;
            list *p;
            p = fptr;
            cout << "List\n";
            while (p != NULL)
            {
                count++;
                cout<<count<<"th Position    Value : "<<p->data<<endl;
                p = p->nptr;
            }
           cout<<"End\n";
        }
    }
}