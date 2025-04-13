#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const string kDivider = "***********************************";
const string kDataFile = "employees.txt";

void printMenu()
{
    cout << kDivider << '\n'
         << "1. To add employee data press 1.\n"
         << "2. To search for an employee press 2.\n"
         << "3. Quit the program press 3.\n"
         << "Please enter your choice.\n";
}

void addEmployee()
{
    int employeeId, departmentId, age, salary;
    string firstName;

    cout << "Enter employee id: \n";
    cin >> employeeId;
    cout << "Enter employee first name: \n";
    cin >> firstName;
    cout << "Enter employee department id: \n";
    cin >> departmentId;
    cout << "Enter employee age: \n";
    cin >> age;
    cout << "Enter employee salary: \n";
    cin >> salary;

    ofstream out(kDataFile, ios::app);
    out << employeeId << ',' << firstName << ',' << departmentId << ',' << age << ',' << salary << '\n';
    out.close();

    cout << "Employee data was saved to a file.\n";
}

void searchEmployee()
{
    cout << "Enter employee id you want to search:\n";
    int targetId;
    cin >> targetId;

    ifstream in(kDataFile);
    if (!in)
    {
        cout << "Employee with this id is not found.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(in, line))
    {
        if (line.empty())
            continue;
        stringstream ss(line);
        string token, firstName;
        int employeeId, departmentId, age, salary;

        getline(ss, token, ',');
        employeeId = stoi(token);
        getline(ss, firstName, ',');
        getline(ss, token, ',');
        departmentId = stoi(token);
        getline(ss, token, ',');
        age = stoi(token);
        getline(ss, token, ',');
        salary = stoi(token);

        if (employeeId == targetId)
        {
            cout << kDivider << '\n';
            cout << "Employee id is: " << employeeId << '\n';
            cout << "Employee name is: " << firstName << '\n';
            cout << "Employee department id is: " << departmentId << '\n';
            cout << "Employee age is: " << age << '\n';
            cout << "Employee salary is: " << salary << '\n';
            found = true;
            break;
        }
    }
    in.close();

    if (!found)
        cout << "Employee with this id is not found.\n";
}

int main()
{
    {
        ofstream clearFile(kDataFile, ios::trunc);
    }

    int choice;
    bool showMenuNext = true;

    while (true)
    {
        if (showMenuNext)
            printMenu();

        if (!(cin >> choice))
        {
            cin.clear();
            string junk;
            cin >> junk;
            cout << "Please enter 1, 2, or 3.\n";
            showMenuNext = false;
            continue;
        }

        if (choice == 1)
        {
            addEmployee();
            showMenuNext = true;
        }
        else if (choice == 2)
        {
            searchEmployee();
            showMenuNext = true;
        }
        else if (choice == 3)
        {
            cout << "Thank you for using the program!\n";
            break;
        }
        else
        {
            cout << "Please enter 1, 2, or 3.\n";
            showMenuNext = false;
        }
    }
    return 0;
}
