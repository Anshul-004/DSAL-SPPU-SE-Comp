#include <iostream>
#include <fstream>
using namespace std;

void writef()
{
    int roll;
    string name, div, address;
    fstream write;

    cout << "Enter the roll no : ";
    cin >> roll;
    cout << "Enter the Name : ";
    cin >> name;
    cout << "Enter the div : ";
    cin >> div;
    cout << "Enter the address : ";
    cin >> address;

    // writing to file
    write.open("students.txt", ios::app);
    write << roll << "\n";
    write << name << "\n";
    write << div << "\n";
    write << address << "\n";
    write << "\n";
    write.close();
}

void readf()
{
    int roll;
    string name, div, address;
    fstream read;
    read.open("students.txt", ios::in);
    while (read >> roll >> name >> div >> address)
    {
        cout << endl;
        cout << roll << endl;
        cout << name << endl;
        cout << div << endl;
        cout << address << endl;
        cout << endl;
    }

    read.close();
}

void searchf()
{
    int roll, froll;
    bool flag = false;
    string name, div, address;
    fstream read;
    cout << "Enter Roll no to search" << endl;
    cin >> froll;
    read.open("students.txt", ios::in);
    while (read >> roll >> name >> div >> address)
    {
        if (roll == froll)
        {
            flag = true;
            cout << "Record Found" << endl;
        }
    }
    if (!flag)
        cout << "Record Not Found" << endl;

    read.close();
}

void deletef()
{
    int roll, froll;
    bool flag = false;
    string name, div, address;
    fstream read, write;
    cout << "Enter Roll no to Delete" << endl;
    cin >> froll;
    read.open("students.txt", ios::in);
    while (read >> roll >> name >> div >> address)
    {
        if (roll == froll)
        {
            flag = true;
        }
        else
        {
            write.open("stud_updated.txt", ios::app);
            write << roll << "\n";
            write << name << "\n";
            write << div << "\n";
            write << address << "\n";
            write << "\n";
            write.close();
        }
    }
    read.close();
    remove("students.txt");
    rename("stud_updated.txt", "students.txt");
}

int main()
{
    int ch;
    while (1)
    {
        cout << endl;
        cout << "1.Write, 2.Read, 3.Delete, 4.Search" << endl;
        cin >> ch;

        if (ch == 1)
            writef();
        else if (ch == 2)
            readf();
        else if (ch == 3)
            deletef();
        else if (ch == 4)
            searchf();
        else
            exit(0);
    }

    return 0;
}