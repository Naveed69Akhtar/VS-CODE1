#include <iostream>
#include <string>
using namespace std;

int main()
{
    string food = "Pizza";
    string &meal = food;

    cout << food << "\n";
    cout << meal << "\n";
    // now change it
    meal = "burger";
    cout << food << "\n";
    cout << meal << "\n";
    return 0;
}
