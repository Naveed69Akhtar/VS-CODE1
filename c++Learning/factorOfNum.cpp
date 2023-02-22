#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "ENter a number\n";
    cin >> num;

    cout << "The Factors are : ";
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << i << ",  ";
        }
    }
    return 0;
}