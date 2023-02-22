#include <iostream>
#include <string>

using namespace std;
struct liberary
{
    int bookID;
    string bookName;
    string bookAuthor;
    int dateIssue[3];
    int dateReturn[3];
    bool issue;
    int studentID;
};
int main()
{
    liberary books[10];
    int bookcount = 0;
    cout << "**************WELCOME TO PIEAS LIBERARY*************\n\n\n\n\n";
manue:
    cout << "****************************************************\n";
    int choice;
    cout << "Enter choice\n";
    cout << "1.Add Book in Database\n 2.Issue Book\n3.Return Book\n 4.List of all Books\n 5.List of issued books\n";
    cin >> choice;
    cin.ignore();
    cout << "***********************\n";
    if (choice == 1)
    {
        cout << "Enter book ID\n";
        cin >> books[bookcount].bookID;
        cin.ignore();
        cout << "Enter Book Name\n";
        getline(cin, books[bookcount].bookName);

        cout << "Enter book Author\n";
        getline(cin, books[bookcount].bookAuthor);

        books[bookcount].issue = false;

        bookcount++;
        goto manue;
    }

    else if (choice == 2)
    {
        int b; // book id
        cout << "Enter book ID\n";
        cin >> b;
        for (int i = 0; i < bookcount; i++)
        {
            if (b == books[i].bookID)
            {
                cout << "Book Name : " << books[i].bookName << endl;
                cout << "Book Author : " << books[i].bookAuthor << endl;
                if (!(books[i].issue))
                {
                    cout << "Date of issuence";
                    cout << "Enter ddmmyyyy\n";
                    cin >> books[i].dateIssue[0];
                    cin >> books[i].dateIssue[1];
                    cin >> books[i].dateIssue[2];

                    books[i].dateReturn[0] = books[i].dateIssue[0] + 10;
                    int r, rr;
                    r = books[i].dateReturn[0] / 31;
                    books[i].dateReturn[0] %= 31;
                    books[i].dateReturn[1] = books[i].dateIssue[1] + r;
                    rr = books[i].dateReturn[1] / 12;
                    books[i].dateReturn[1] %= 12;
                    books[i].dateReturn[2] = books[i].dateIssue[2] + rr;
                    cout << "enter student ID ";
                    cin >> books[i].studentID;
                    cout << "The book is issued to you\n";
                    books[i].issue = true; // true
                }
                else
                {
                    cout << "The book is already issued\n";
                    cout << "Going to main menu";
                    goto manue;
                }
            }
        }
        goto manue;
    }
    else if (choice == 3)
    {
        int c; // for book id
        cout << "Enter Book ID\n";
        cin >> c;
        for (int i = 0; i < bookcount; i++)
        {
            if (c == books[i].bookID)
            {
                cout << "Book Name : " << books[i].bookName << endl;
                cout << "Book Author : " << books[i].bookAuthor << endl;
                if (books[i].issue)
                {
                    cout << "Book returned\n";
                    books[i].issue = false;
                }
                else
                {
                    cout << "Book is not issued to anyone\nGoing to Main Menu\n";
                    goto manue;
                }
            }
            else
            {
                cout << "Wrong Book Id \nGoing to Main Menu\n";
            }
        }
        goto manue;
    }
    else if (choice == 4)
    {
        for (int i = 0; i < bookcount; i++)
        {
            cout << "Book ID : " << books[i].bookID << endl;
            cout << "Book Name : " << books[i].bookName << endl;
            cout << "Book Author : " << books[i].bookAuthor << endl
                 << endl
                 << endl;
        }
        goto manue;
    }
    else if (choice == 5)
    {
        for (int i = 0; i < bookcount; i++)
        {
            if (books[i].issue)
            {
                cout << "Book ID : " << books[i].bookID << endl;
                cout << "Book Name : " << books[i].bookName << endl;
                cout << "Book Author : " << books[i].bookAuthor << endl;
                cout << "Student Id : " << books[i].studentID << endl;
                cout << "Book will be returned on : " << books[i].dateReturn[0] << "/" << books[i].dateReturn[1] << "/" << books[i].dateReturn[2] << endl
                     << endl
                     << endl;
            }
        }
        goto manue;
    }
    return 0;
}