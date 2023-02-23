#include <iostream>
#include <string>
using namespace std;
bool pincheck()
{
    string pin;
    cout << "Enter Pin\n";
    cin >> pin;
    cin.ignore();
    FILE *ptr;
    if ((ptr = fopen("pin.txt", "r+")) == NULL)
    {
        cout << "File Error\n";
    }
}