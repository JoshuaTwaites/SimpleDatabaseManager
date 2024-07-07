#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxrow = 10;

string EmpName[maxrow] = {};
string EmpID[maxrow] = {};

void OpenFile()
{
    string line;
    ifstream myfile("myFile.txt");
    if (myfile.is_open())
    {
        int x = 0;
        while (getline(myfile, line))
        {
            int l = line.length();
            EmpID[x] = line.substr(0, 3);
            EmpName[x] = line.substr(4, 1 - 4);
            x++;
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void AddRecord()
{
    char name[50];
    string empno;

    cin.ignore();

    cout << "Enter Employee number (must be 3 characters): " << endl;
    getline(cin, empno);
    while (empno.length() != 3)
    {
        cout << "Sorry employee number must be 3 characters, please enter it again: ";
        getline(cin, empno);
    }

    cout << "Enter Employee name: ";
    cin.getline(name, 50);

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == "\0")
        {
            EmpID[x] = empno;
            EmpName[x] = name;
            break;
        }
    }
}

void Listrecord()
{
    system("CLS");
    cout << "Current Record(s)" << endl;
    cout << "=======================" << endl;

    int counter = 0;
    cout << "No. |  ID  |       Name   " << endl
         << "-----------------------\n";

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] != "\0")
        {
            counter++;
            cout << "  " << counter << "   " << EmpID[x] << "           " << EmpName[x] << endl;
        }
    }

    if (counter == 0)
    {
        cout << "No Record Found" << endl;
    }

    cout << "=======================" << endl;
}

void SearchRecord()
{
    system("CLS");
    string search;
    cout << "Search by ID: ";
    cin >> search;

    cout << "Current Record(s)" << endl;
    cout << "================================" << endl;
    int counter = 0;
    for (int x = 0; x < maxrow; x++)
    {

        if (EmpID[x] == search)
        {

            counter++;
            cout << "  " << counter << "   " << EmpID[x] << "           " << EmpName[x] << endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout << "No Record Found" << endl;
    }

    cout << "================================" << endl;
}

void UpdateRecord(string search)
{
    char name[50];
    string empno;

    int counter = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == search)
        {
            counter++;
            cout << "Employee name: ";
            cin.getline(name, 50);

            EmpName[x] = name;

            cout << "Update Successful" << endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout << "ID Not Found" << endl;
    }
}

void DeleteRecord(string search)
{
    int counter = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == search)
        {
            counter++;
            EmpName[x] = "";
            EmpID[x] = "";

            cout << "Successfully deleted" << endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout << "ID not found" << endl;
    }
}

void SaveToFile()
{
    ofstream myfile;
    myfile.open("myFile.txt");

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == "\0")
        {
            break;
        }
        else
        {
            myfile << EmpID[x] + ", " + EmpName[x] << endl;
        }
    }
}

int main()
{
    cout << "Menu" << endl;
    int option;
    string empID;
    system("CLS");
    OpenFile();

    do
    {

        cout << "1-Create Records" << endl;
        cout << "2-Update Records" << endl;
        cout << "3-Delete Records" << endl;
        cout << "4-Search Records" << endl;
        cout << "5-Display Records" << endl;
        cout << "6-Exit and Save to Text file" << endl;
        cout << "================================" << endl;

        cout << "Select option:";
        cin >> option;

        switch (option)
        {
        case 1:
            AddRecord();
            system("CLS");
            break;
        case 2:
            cin.ignore();
            cout << "Enter Employee ID (must be 3 numbers): " << endl;
            getline(cin, empID);
            UpdateRecord(empID);
            system("CLS");
            break;
        case 3:
            cin.ignore();
            cout << "Delete by ID: " << endl;
            getline(cin, empID);
            DeleteRecord(empID);
            cin.ignore();
            break;
        case 4:
            SearchRecord();
            break;
        case 5:
            Listrecord();
            break;
        }

    } while (option != 6);

    SaveToFile();
    cout << "Exiting.... Saved to File" << endl;
    return 0;
}
