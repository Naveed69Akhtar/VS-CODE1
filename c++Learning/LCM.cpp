#include <iostream>
using namespace std;
int main()
{
    int n1, n2;
    cout << "Enter 2 numbers : \n";
    cin >> n1 >> n2;

    if (n1 < n2)
    {
        int temp;
        temp = n1;
        n1 = n2;
        n2 = temp;
    }

    for (int i = 2; i < n2; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            cout << "LCM is : " << i << endl;
            return 0;
        }
    }
    cout << "No LCM";
    return 0;
}