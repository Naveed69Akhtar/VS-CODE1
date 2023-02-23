#include <iostream>
#include <string>
#include "head.h"
using namespace std;
int main()
{
    int x = 0;
    cout << "Welcome to bank\n";
    do
    {
        pincheck();
    } while (x > 1);
    return 0;
}