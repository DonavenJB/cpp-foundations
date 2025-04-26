#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const string kDivider = "***********************************";
const string kEmployeeFile = "employees.txt";
const string kDeptFile = "departments.txt";

bool departmentExists(int departmentId)
{
    ifstream in(kDeptFile);
    if (!in)
        return false;
    string line;
    while (getline(in, line))
    {
        if (line.empty())
            continue;
        stringstream ss(line);
        string token;
        int id;
        getline(ss, token, ',');
        id = stoi(token);
        if (id == departmentId)
            return true;
    }
    return false;
}

bool employeeExists(int employeeId)
{
    ifstream in(kEmployeeFile);
    if (!in)
        return false;
    string line;
    while (getline(in, line))
    {
        if (line.empty())
            continue;
        string token;
        stringstream ss(line);
        getline(ss, token, ',');
        if (stoi(token) == employeeId)
            return true;
    }
    return false;
}

void printMenu(bool printDividerLine)
{
    if (printDividerLine)
        cout << kDivider << '\n';
    cout << "1. To collect employee data press 1.\n"
         << "2. To search employee press 2.\n"
         << "3. To create a department press 3.\n"
         << "4. To search a department press 4.\n"
         << "5. Quit the program press 5.\n"
         << "Please enter your choice.\n";
}

void addDepartment()
{
    int departmentId;
    string departmentName, departmentHead;

    cout << "Enter new department id:\n";
    cin >> departmentId;

    if (departmentExists(departmentId))
    {
        cout << "Department with id " << departmentId << " already exists.\n";
        return;
    }

    cout << "Enter new department name:\n";
    cin >> departmentName;

    cout << "Enter department head:\n";
    cin >> departmentHead;

    ofstream out(kDeptFile, ios::app);
    out << departmentId << ',' << departmentName << ',' << departmentHead << '\n';
    out.close();

    cout << "New department " << departmentName << " with id " << departmentId << " has been created.\n";
}

void searchDepartment()
{
    cout << "Enter department id you want to search\n";
    int departmentId;
    cin >> departmentId;

    ifstream in(kDeptFile);
    if (!in)
    {
        cout << "Department with id " << departmentId << " is not found.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(in, line))
    {
        if (line.empty())
            continue;
        string token, name, head;
        int id;
        stringstream ss(line);
        getline(ss, token, ',');
        id = stoi(token);
        getline(ss, name, ',');
        getline(ss, head, ',');
        if (id == departmentId)
        {
            cout << "Department id is: " << id << '\n';
            cout << "Department name is: " << name << '\n';
            cout << "Department head is: " << head << '\n';
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Department with id " << departmentId << " is not found.\n";
}

void addEmployee()
{
    int employeeId, departmentId, age, salary;
    string firstName;

    cout << "Enter employee id: \n";
    cin >> employeeId;

    if (employeeExists(employeeId))
    {
        cout << "Employee with id " << employeeId << " already exists.\n";
        return;
    }

    cout << "Enter employee department id: \n";
    cin >> departmentId;

    if (!departmentExists(departmentId))
    {
        cout << "Department with id " << departmentId << " doesn't exist.\n";
        return;
    }

    cout << "Enter employee first name: \n";
    cin >> firstName;

    cout << "Enter employee age: \n";
    cin >> age;

    cout << "Enter employee salary: \n";
    cin >> salary;

    ofstream out(kEmployeeFile, ios::app);
    out << employeeId << ',' << firstName << ',' << departmentId << ',' << age << ',' << salary << '\n';
    out.close();

    cout << "Employee data was saved to a file.\n\n";
}

bool searchEmployee()
{
    cout << "Enter employee id you want to search:\n";
    int targetId;
    cin >> targetId;

    ifstream in(kEmployeeFile);
    if (!in)
    {
        cout << "Employee with this id is not found.\n";
        return false;
    }

    string line;
    bool found = false;
    while (getline(in, line))
    {
        if (line.empty())
            continue;
        string token, firstName;
        int employeeId, departmentId, age, salary;
        stringstream ss(line);
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
            cout << kDivider << '\n';
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Employee with this id is not found.\n";
        return false;
    }
    return true;
}

int main()
{
    {
        ofstream clearEmployees(kEmployeeFile, ios::trunc);
    }
    {
        ofstream clearDepartments(kDeptFile, ios::trunc);
    }

    int choice;
    bool showMenuNext = true;
    bool printDividerNextMenu = true;

    while (true)
    {
        if (showMenuNext)
            printMenu(printDividerNextMenu);

        if (!(cin >> choice))
        {
            cin.clear();
            string junk;
            cin >> junk;
            cout << "Please enter 1, 2, 3, 4 or 5.\n";
            showMenuNext = false;
            continue;
        }

        printDividerNextMenu = true;

        if (choice == 1)
        {
            addEmployee();
            showMenuNext = true;
        }
        else if (choice == 2)
        {
            bool wrapped = searchEmployee();
            printDividerNextMenu = !wrapped;
            showMenuNext = true;
        }
        else if (choice == 3)
        {
            addDepartment();
            showMenuNext = true;
        }
        else if (choice == 4)
        {
            searchDepartment();
            showMenuNext = true;
        }
        else if (choice == 5)
        {
            cout << "Thank you for using the program!\n";
            break;
        }
        else
        {
            cout << "Please enter 1, 2, 3, 4 or 5.\n";
            showMenuNext = false;
        }
    }
    return 0;
}
