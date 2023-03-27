#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class box
{
public:
    float height, width, length;
    void input();
    void cal_vol();
    void disp_att();
    void disp_least_two();
};

void box ::input()
{
    cout << "Enter Length : ";
    cin >> length;
    cout << "Enter Width : ";
    cin >> width;
    cout << "Enter Height : ";
    cin >> height;
}

void box::cal_vol()
{
    cout << "Length : " << length << endl;
    cout << "Width : " << width << endl;
    cout << "Height : " << height << endl;
}

void box::disp_least_two()
{
    int x[3] = {length, width, height};
    sort(x, x + 3);
    cout << "Least Two are : " << x[0] << " " << x[1] << endl;
}

void box::disp_att()

{
    cout << "The Volume is : " << length * width * height << " cubic unit\n";
}
int main()
{
    box b1;

    b1.input();
    b1.cal_vol();
    b1.disp_att();
    b1.disp_least_two();
}