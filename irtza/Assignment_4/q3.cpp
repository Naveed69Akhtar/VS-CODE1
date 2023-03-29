#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class student
{
    int marks[10];

public:
    void input();
    void show();
    int max();
    int min();
    float average();
    void sort_array();
    void reverse_array();
    void freq_call();
    float standard_deviation();
};

void student::input()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter Marks " << i << "  : ";
        cin >> marks[i];
    }
    cout << "Input is completed\n";
}

int student::max()
{
    int max = marks[0];
    for (int i = 1; i < 10; i++)
    {
        if (max < marks[i])
            max = marks[i];
    }
    return max;
}

int student::min()
{
    int min = marks[0];
    for (int i = 1; i < 10; i++)
    {
        if (min > marks[i])
            min = marks[i];
    }
    return min;
}

float student::average()
{
    int s = 0;
    for (int i = 0; i < 10; i++)
        s += marks[i];
    return s / 10.0;
}

void student::sort_array()
{
    cout << "Array before Sorting\n";

    for (int i = 0; i < 10; i++)
        cout << marks[i] << "  ";

    sort(marks, marks + 10);

    cout << "\nArray After Sorting\n";

    for (int i = 0; i < 10; i++)
        cout << marks[i] << "  ";

    cout << "\n";
}

void student::reverse_array()
{
    cout << "Array before Sorting\n";

    for (int i = 0; i < 10; i++)
        cout << marks[i] << "  ";

    sort(marks, marks + 10);

    int temp;
    int j = 9;
    for (int i = 0; i < 5; i++)
    {
        temp = marks[j];
        marks[j] = marks[i];
        marks[i] = temp;
        j--;
    }

    cout << "\nArray After Sorting\n";

    for (int i = 0; i < 10; i++)
        cout << marks[i] << "  ";

    cout << "\n";
}

void student::show()
{
    cout << "The Marks are : ";
    for (int i = 0; i < 10; i++)
    {
        cout << marks[i] << "  ";
    }
    cout << endl;
}

void student::freq_call()
{
    int freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (marks[i] == marks[j])
            {
                freq[i]++;
            }
        }
    }

    // showing frequency

    for (int i = 0; i < 10; i++)
    {
        cout << "The Frequency of " << marks[i] << " is : " << freq[i] << endl;
    }
    cout << endl;
}

float student::standard_deviation()
{
    float mean, dev = 0;
    float sum = 0;
    // mean find

    for (int i = 0; i < 10; i++)
    {
        sum += marks[i];
    }
    mean = sum / 10.0;

    for (int i = 0; i < 10; i++)
    {
        dev += ((marks[i] - mean) * (marks[i] - mean));
    }

    dev = dev / 9.0;

    dev = sqrt(dev);
    return dev;
}

int main()
{
    int choice;
    student s1;
    s1.input();
    while (true)
    {
        cout << "0. Show All Marks\n";
        cout << "1. Find Max Marks\n";
        cout << "2. Find Min Marks\n";
        cout << "3. Find Average Marks\n";
        cout << "4. Find Standard Deviation\n";
        cout << "5. Sort Marks\n";
        cout << "6. Reverse Marks Order\n";
        cout << "7. Find Frequency of Marks\n";
        cout << "8. Exit\n";
        cout << "Enter a Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            s1.show();
            break;
        case 1:
            cout << "The Maximum Marks are : " << s1.max() << endl;
            break;
        case 2:
            cout << "The Minimum Marks are : " << s1.min() << endl;
            break;
        case 3:
            cout << "The average Marks are : " << s1.average() << endl;
            break;
        case 4:
            cout << "The Standard Deviation of Marks are : " << s1.standard_deviation() << endl;
            break;
        case 5:
            s1.sort_array();
            break;
        case 6:
            s1.reverse_array();
            break;
        case 7:
            s1.freq_call();
            break;
        case 8:
            exit(0);
            break;
        default:
            cout << "Invalid Input\nPlease Try again\n";
        }
    }
}