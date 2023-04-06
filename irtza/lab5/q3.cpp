#include <iostream>
#include <string>
using namespace std;

class cars
{
    int Chassis_Number, Engine_Number, Model;
    string Type, Make;
    void input();

public:
    void Display_data();

    void getter(int *t_Chassis_Number, int *t_Engine_Number, int *t_Model, string *t_Type, string *t_Make);

    cars()
    {
        cout << "Constructor Called Without Giving any Arguments\n";
    };

    void input_again();

    cars(int t_Chassis_Number, int t_Engine_Number, int t_Model, string t_Type, string t_Make)
    {
        Chassis_Number = t_Chassis_Number;
        Engine_Number = t_Engine_Number;
        Model = t_Model;
        Make = t_Make;
        Type = t_Type;
        cout << "Constructor called With Arguments\n";
    }

    void setter()
    {
        input();
    }
};

void cars::input()
{
    cout << "Enter Car Maker : ";

    getline(cin, Make);

    cout << "Enter Car Type (Jeep or Seden) : ";
    cin >> Type;

    cout << "Enter Engine Number : ";
    cin >> Engine_Number;

    cout << "Enter Chasis Number : ";
    cin >> Chassis_Number;

    cout << "Enter Model : ";
    cin >> Model;

    cout << "Data Entered Successfully\n";
}

void cars::getter(int *t_Chassis_Number, int *t_Engine_Number, int *t_Model, string *t_Type, string *t_Make)
{
    *t_Chassis_Number = Chassis_Number;
    *t_Engine_Number = Engine_Number;
    *t_Model = Model;
    *t_Make = Make;
    *t_Type = Type;
}

void cars::input_again()
{
    cin.ignore();
    cout << "Enter Car Maker : ";
    getline(cin, Make);

    cout << "Enter Car Type (Jeep or Seden) : ";
    cin >> Type;

    cout << "Enter Engine Number : ";
    cin >> Engine_Number;

    cout << "Enter Chasis Number : ";
    cin >> Chassis_Number;

    cout << "Enter Model : ";
    cin >> Model;

    cout << "Data Entered Successfully\n";
}

void cars::Display_data()
{
    cout << "Car Maker : " << Make << endl;
    cout << "Car Type (Jeep or Seden) : " << Type << endl;
    cout << "Engine Number : " << Engine_Number << endl;
    cout << "Chasis Number : " << Chassis_Number << endl;
    cout << "Model : " << Model << endl;
}

int main()
{
    // temporary veriables;
    int t_Chassis_Number, t_Engine_Number, t_Model;
    string t_Type, t_Make;

    cars car1;
    // setting car1
    car1.setter();
    car1.getter(&t_Chassis_Number, &t_Engine_Number, &t_Model, &t_Type, &t_Make);

    // showing all
    cout << "************CAR 1***************\n";
    cout << "Car Maker : " << t_Make << endl;
    cout << "Car Type (Jeep or Seden) : " << t_Type << endl;
    cout << "Engine Number : " << t_Engine_Number << endl;
    cout << "Chasis Number : " << t_Chassis_Number << endl;
    cout << "Model : " << t_Model << endl;

    // data of 2nd car
    cout << "Enter data of 2nd Car\n";
    cin.ignore();
    cout << "Enter Car Maker : ";
    getline(cin, t_Make);
    cout << "Enter Car Type (Jeep or Seden) : ";
    cin >> t_Type;
    cout << "Enter Engine Number : ";
    cin >> t_Engine_Number;
    cout << "Enter Chasis Number : ";
    cin >> t_Chassis_Number;
    cout << "Enter Model : ";
    cin >> t_Model;

    cars car2(t_Chassis_Number, t_Engine_Number, t_Model, t_Type, t_Make);

    car2.Display_data();

    // input again
    cout << "Enter Car2 data again\n";
    car2.input_again();
    // show again
    cout << "Showing Car 2 data Again";
    car2.Display_data();
}