#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("myfile.txt"); // open the file
    int num;

    if (infile.is_open())
    { // check if file is open
        while (infile >> num)
        {                        // read integers until end of file
            cout << num << endl; // print the integer
        }
        infile.close(); // close the file
    }
    else
    {
        cout << "Unable to open file" << endl; // file not found or unable to open
    }

    return 0;
}
