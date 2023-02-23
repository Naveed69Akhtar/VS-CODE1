#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void pincheck()
{
    int count = 3;
    string pin, pin1;
manue:
    cout << "Enter Pin\n";
    getline(cin, pin);
    count--;
    ifstream myfile("pin.txt");

    if (myfile.is_open())
    {
        getline(myfile, pin1);
        if (pin1 == pin)
        {
            cout << "Welcome";
        }
        else
        {
            cout << "You Entered wrong pin\n";
            cout << count << " Tries Left\n";
            if (count == 0)
            {
                cout << "Programm End\n";
                exit(0);
            }
            else
                goto manue;
        }

        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}