#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct batsman
{
    string name = "ali";
    int score = 0;
    int balls = 0;
    float sr = 0.0;
};

struct bowler
{
    string name = "ali";
    int ball = 0;
    int runs = 0;
    int wickets = 0;
};
int flag = 1;
batsman a[12];
bowler b[11];
int i = 0;
void score_add(int temp_bowler)
{
    int counter = 0;
    int temp_score;
    while (counter < 6)
    {

        cout << "Enter Score : ";
        cin >> temp_score;
        if (flag == 1)
        {
            a[i + 0].balls++;
            a[i + 0].score += temp_score;
            a[i + 0].sr = a[i].score * 100.0 / a[i].balls;
            cout << "Batsman 1\n";
        }
        else if (flag == 2)
        {
            cout << "Batsman 2\n";
            a[i + 1].balls++;
            a[i + 1].score += temp_score;
            a[i + 1].sr = a[i + 1].score * 100.0 / a[i + 1].balls;
        }
        if (temp_score == 1 || temp_score == 3 || temp_score == 5)
        {
            if (flag == 1)
                flag = 2;
            else if (flag == 2)
                flag = 1;
        }

        a[12].balls++;
        a[12].score += temp_score;
        b[temp_bowler].ball++;
        b[temp_bowler].runs += temp_score;

        counter++;
    }
    if (flag == 1)
        flag = 2;
    else if (flag == 2)
        flag = 1;
}
const int over = 3;
int main()
{
    int counter = 0;
    while (counter < over)
    {
        int i = 0, temp_bowler;
        cout << "Enter Bowler : ";
        cin >> temp_bowler;
        cout << "**********************\n";
        score_add(temp_bowler);
        cout << "Batsman\tRuns\tBalls\tSR\n";
        while (i < 11)
        {
            cout << setw(6) << a[i].name;
            cout << setw(4) << a[i].score << "\t";
            cout << setw(5) << a[i].balls << "\t";
            cout << setw(2) << a[i].sr << endl;
            i++;
        }

        counter++;
    }
}
