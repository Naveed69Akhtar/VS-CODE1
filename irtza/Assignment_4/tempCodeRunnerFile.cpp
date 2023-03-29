#include <iostream>
#include <string>
using namespace std;

class student
{
    float marks[3];

public:
    void input();
    float sum();
    float average();
    float max();
    int count_pass();
};

void student::input()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Marks " << i << "  : ";
        cin >> marks[i];
    }
    cout << "Input is completed\n";
}

float student::sum()
{
    float s = 0;
    for (int i = 0; i < 3; i++)
    {
        s += marks[i];
    }
    return s;
}

float student::average()
{
    return sum() / 3.0;
}

float student::max()
{
    float max = marks[0];
    for (int i = 1; i < 3; i++)
    {
        if (max < marks[i])
            max = marks[i];
    }
    return max;
}

int student::count_pass()
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (marks[i] >= 50)
            count++;
    }
    return count;
}

int main()
{
    student student1;
    student1.input();
    cout << "Maximum Value of marks in Student1 is : " << student1.max() << endl;
    cout << "The Sum of Marks in Student1 is : " << student1.sum() << endl;
    cout << "The average of Marks in Student1 is : " << student1.average() << endl;
    cout << "The Passed marks are : " << student1.count_pass() << endl;
    getchar();
}