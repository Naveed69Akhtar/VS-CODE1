#include <iostream>
#include <string>
using namespace std;
int main()
{
    string cars[] = {"Hunda", "Sozuki", "Cvic", "Frrari", "lambergini"};
    // we can ommit array size as above

    cout << "now get total bytes occupied by array\n";
    cout << "The bytes are : " << sizeof(cars) << endl;

    // cout << "now get total items occupied by array\n";
    int nums[] = {12, 23, 5, 34, 556, 44, 23, 454, 23, 556, 34, 6};
    cout << "The bytes are : " << sizeof(nums) / sizeof(int) << endl;

    //
    return 0;
}