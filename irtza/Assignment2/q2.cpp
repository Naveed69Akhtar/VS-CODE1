#include <iostream>
#include <string>

using namespace std;

// Structure to hold student information
struct Student
{
    int roll;
    string name;
    string city;
    string phone;
    int marks[3];
    string grade[3];
    Student *next;
};

// Function to calculate grade based on marks
char calculate_grade(int marks)
{
    if (marks >= 80)
        return 'A';
    else if (marks >= 70)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 50)
        return 'D';
    else
        return 'F';
}

int main()
{
    Student *head = NULL;
    int count = 0;

    while (true)
    {
        cout << "\n***** MENU *****" << endl;
        cout << "1. Add Student Data" << endl;
        cout << "2. Search Student Data" << endl;
        cout << "3. Duplicate Student Data" << endl;
        cout << "4. Display Student Name and Grades" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            // Create a new student
            Student *newStudent = new Student;

            // Take input from user
            cout << "\nEnter Student Roll No.: ";
            cin >> newStudent->roll;

            // Check if roll no. is unique
            bool rollNoExists = false;
            Student *temp = head;
            while (temp != NULL)
            {
                if (temp->roll == newStudent->roll)
                {
                    rollNoExists = true;
                    break;
                }
                temp = temp->next;
            }

            if (rollNoExists)
            {
                cout << "\nRoll No. already exists. Please enter a unique Roll No." << endl;
                continue;
            }

            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, newStudent->name);

            cout << "Enter Student City: ";
            getline(cin, newStudent->city);

            cout << "Enter Student Phone No.: ";
            getline(cin, newStudent->phone);

            cout << "Enter marks of 3 Subjects (English, Urdu, Maths): ";
            for (int i = 0; i < 3; i++)
            {
                cin >> newStudent->marks[i];
                newStudent->grade[i] = calculate_grade(newStudent->marks[i]);
            }

            newStudent->next = head;
            head = newStudent;

            count++;
            cout << "\nStudent data added successfully." << endl;
        }
        else if (choice == 2)
        {
            // Search student by roll no.
            int rollNo;
            cout << "\nEnter roll no. to search: ";
            cin >> rollNo;

            Student *temp = head;
            bool found = false;
            while (temp != NULL)
            {
                if (temp->roll == rollNo)
                {
                    found = true;
                    cout << "\n***** STUDENT DETAILS *****" << endl;
                    cout << "Student Roll No.: " << temp->roll << endl;
                    cout << "Student Name: " << temp->name << endl;
                    cout << "Student City: " << temp->city << endl;
                    cout << "Student Phone No.: " << temp->phone << endl;
                    cout << "English: " << temp->grade[0] << endl;
                    cout << "Urdu: " << temp->grade[1]<<endl;
                     if (!found)
                    {
                        cout << "\nStudent data not found." << endl;
                    }
                }
                else if (choice == 3)
                {
                    // Duplicate student data
                    int rollNo;
                    cout << "\nEnter roll no. to duplicate: ";
                    cin >> rollNo;

                    Student *temp = head;
                    bool found = false;
                    while (temp != NULL)
                    {
                        if (temp->roll == rollNo)
                        {
                            found = true;
                            Student *newStudent = new Student;

                            // Copy data to new student
                            newStudent->roll = ++count;
                            newStudent->name = temp->name;
                            newStudent->city = temp->city;
                            newStudent->phone = temp->phone;
                            for (int i = 0; i < 3; i++)
                            {
                                newStudent->marks[i] = temp->marks[i];
                                newStudent->grade[i] = temp->grade[i];
                            }

                            newStudent->next = head;
                            head = newStudent;

                            cout << "\nStudent data duplicated successfully." << endl;
                            break;
                        }
                        temp = temp->next;
                    }

                    if (!found)
                    {
                        cout << "\nStudent data not found." << endl;
                    }
                }
            }
        }
    }
}
