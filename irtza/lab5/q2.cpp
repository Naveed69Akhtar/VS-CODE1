#include <iostream>
#include <string>
using namespace std;

class Distance
{
    float feets, inches;

public:
    Distance()
    {
        cout << "Constructor Called Without Giving any Arguments\n";
    }
    Distance(float feet, float inch)
    {
        feets = feet;
        inches = inch;
        cout << "Constructor Called by Giving Arguments\n";
    }
    void setter()
    {
        cout << "Enter Distance (feets Inches) : ";
        cin >> feets >> inches;
        cout << "Distance Entered\n";
    }
    void getter(float *a, float *b)
    {
        *a = feets;
        *b = inches;
    }
    void Display()
    {
        cout << "Distance is : " << feets << " Feets " << inches << " Inches\n";
    }
    void addDistance(float a, float b, float c, float d)
    {
        int carry = 0;
        float temp_a;
        temp_a = b + d;
        while (temp_a >= 12)
        {
            temp_a -= 12;
            carry++;
        }
        inches = temp_a;
        feets = a + c + carry;

        cout << "Distance Added\n";
    }
};

int main()
{
    Distance obj;
    cout << "Enter Distance 1\n";
    obj.setter();

    float d1, d2;
    cout << "Enter Distance 2\n";
    cout << "Enter Distance (feets Inches) : ";
    cin >> d1 >> d2;
    Distance obj2(d1, d2);

    float a, b, c, d;
    obj.getter(&a, &b);
    obj2.getter(&c, &d);
    // now display object
    // obj2.Display();
    // add two distance
    Distance addition;
    addition.addDistance(a, b, c, d);

    // now dispaly Results
    addition.Display();
}