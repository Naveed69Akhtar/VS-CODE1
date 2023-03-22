#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    time_t time_is = time(0);
    tm *get_time = localtime(&time_is);
    cout << get_time->tm_hour << " ";
    cout << get_time->tm_min << " ";
    cout << get_time->tm_sec << " ";
    cout << get_time->tm_mday << " ";
    cout << get_time->tm_mon << " ";
    cout << get_time->tm_wday << " ";
    cout << get_time->tm_yday << " ";
    cout << get_time->tm_year << " ";
}