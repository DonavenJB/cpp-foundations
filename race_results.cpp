#include <iostream>
#include <string>
using namespace std;

int main()
{
    string firstRunnerName, secondRunnerName, thirdRunnerName;
    double firstRunnerTime, secondRunnerTime, thirdRunnerTime;

    cout << "Enter first runner's name: \n";
    cin >> firstRunnerName;
    cout << "Enter first runner's time: \n";
    cin >> firstRunnerTime;

    cout << "Enter second next runner's name: \n";
    cin >> secondRunnerName;
    cout << "Enter second next runner's time: \n";
    cin >> secondRunnerTime;

    cout << "Enter third next runner's name: \n";
    cin >> thirdRunnerName;
    cout << "Enter third next runner's time: \n";
    cin >> thirdRunnerTime;

    if (firstRunnerTime <= 0 || secondRunnerTime <= 0 || thirdRunnerTime <= 0)
    {
        cout << "\nPlease only enter positive numbers for runner's time.\n";
        cout << "Please restart program";
        return 0;
    }

    if (firstRunnerTime < secondRunnerTime && firstRunnerTime < thirdRunnerTime)
    {
        cout << "First Place  : " << firstRunnerName << " " << firstRunnerTime << endl;
        if (secondRunnerTime < thirdRunnerTime)
        {
            cout << "Second Place : " << secondRunnerName << " " << secondRunnerTime << endl;
            cout << "Third Place  : " << thirdRunnerName << " " << thirdRunnerTime << endl;
        }
        else
        {
            cout << "Second Place : " << thirdRunnerName << " " << thirdRunnerTime << endl;
            cout << "Third Place  : " << secondRunnerName << " " << secondRunnerTime << endl;
        }
    }
    else if (secondRunnerTime < firstRunnerTime && secondRunnerTime < thirdRunnerTime)
    {
        cout << "First Place  : " << secondRunnerName << " " << secondRunnerTime << endl;
        if (firstRunnerTime < thirdRunnerTime)
        {
            cout << "Second Place : " << firstRunnerName << " " << firstRunnerTime << endl;
            cout << "Third Place  : " << thirdRunnerName << " " << thirdRunnerTime << endl;
        }
        else
        {
            cout << "Second Place : " << thirdRunnerName << " " << thirdRunnerTime << endl;
            cout << "Third Place  : " << firstRunnerName << " " << firstRunnerTime << endl;
        }
    }
    else
    {
        cout << "First Place  : " << thirdRunnerName << " " << thirdRunnerTime << endl;
        if (firstRunnerTime < secondRunnerTime)
        {
            cout << "Second Place : " << firstRunnerName << " " << firstRunnerTime << endl;
            cout << "Third Place  : " << secondRunnerName << " " << secondRunnerTime << endl;
        }
        else
        {
            cout << "Second Place : " << secondRunnerName << " " << secondRunnerTime << endl;
            cout << "Third Place  : " << firstRunnerName << " " << firstRunnerTime << endl;
        }
    }

    return 0;
}
