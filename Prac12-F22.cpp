#include <bits/stdc++.h>
using namespace std;

struct employee
{
    int id;
    string name;
    string desg;
    int salary;
};

void add_employees()
{
    employee s;
    cout << "Enter the id of the employee-\n";
    cin >> s.id;
    cout << "Enter the name of the employee-\n";
    cin >> s.name;
    cout << "Enter the desg of the employee-\n";
    cin >> s.desg;
    cout << "Enter the salary of the employee-\n";
    cin >> s.salary;

    if (1 <= s.id and s.id <= 10)
    {
        ofstream write;
        write.open("1to10.txt", ios::app);

        write << "\n"
              << s.id;
        write << "\n"
              << s.name;
        write << "\n"
              << s.desg;
        write << "\n"
              << s.salary;

        write.close();
    }
    if (11 <= s.id and s.id <= 20)
    {
        ofstream write;
        write.open("11to20.txt", ios::app);

        write << "\n"
              << s.id;
        write << "\n"
              << s.name;
        write << "\n"
              << s.desg;
        write << "\n"
              << s.salary;

        write.close();
    }
    if (21 <= s.id and s.id <= 30)
    {
        ofstream write;
        write.open("21to30.txt", ios::app);

        write << "\n"
              << s.id;
        write << "\n"
              << s.name;
        write << "\n"
              << s.desg;
        write << "\n"
              << s.salary;

        write.close();
    }
    if (31 <= s.id and s.id <= 40)
    {
        ofstream write;
        write.open("31to40.txt", ios::app);

        write << "\n"
              << s.id;
        write << "\n"
              << s.name;
        write << "\n"
              << s.desg;
        write << "\n"
              << s.salary;

        write.close();
    }
    if (41 <= s.id and s.id <= 50)
    {
        ofstream write;
        write.open("41to50.txt", ios::app);

        write << "\n"
              << s.id;
        write << "\n"
              << s.name;
        write << "\n"
              << s.desg;
        write << "\n"
              << s.salary;

        write.close();
    }
}

void print(employee s)
{
    cout << "Roll number: " << s.id << endl;
    cout << "Name: " << s.name << endl;
    cout << "desg: " << s.desg << endl;
    cout << "salary: " << s.salary << endl;
}

void display_employees()
{
    employee s1;
    ifstream read;
    read.open("1to10.txt");
    while (!read.eof())
    {
        read >> s1.id;
        read >> s1.name;
        read >> s1.desg;
        read >> s1.salary;

        print(s1);
    }
    read.close();

    cout << endl;

    employee s2;
    read.open("11to20.txt");
    while (!read.eof())
    {
        read >> s2.id;
        read >> s2.name;
        read >> s2.desg;
        read >> s2.salary;

        print(s2);
    }
    read.close();

    cout << endl;

    employee s3;
    read.open("21to30.txt");
    while (!read.eof())
    {
        read >> s3.id;
        read >> s3.name;
        read >> s3.desg;
        read >> s3.salary;

        print(s3);
    }
    read.close();

    cout << endl;

    employee s4;
    read.open("31to40.txt");
    while (!read.eof())
    {
        read >> s4.id;
        read >> s4.name;
        read >> s4.desg;
        read >> s4.salary;

        print(s4);
    }
    read.close();

    cout << endl;

    employee s5;
    read.open("41to50.txt");
    while (!read.eof())
    {
        read >> s5.id;
        read >> s5.name;
        read >> s5.desg;
        read >> s5.salary;

        print(s5);
    }
    read.close();

    cout << endl;
}

int search_employees(int id)
{
    if (1 <= id and id <= 10)
    {
        employee s;
        ifstream read;
        read.open("1to10.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id == id)
            {
                cout << "employee's record found!" << endl;
                return id;
            }
        }

        read.close();
    }
    if (11 <= id and id <= 20)
    {
        employee s;
        ifstream read;
        read.open("11to20.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id == id)
            {
                cout << "employee's record found!" << endl;
                return id;
            }
        }

        read.close();
    }
    if (21 <= id and id <= 30)
    {
        employee s;
        ifstream read;
        read.open("21to30.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id == id)
            {
                cout << "employee's record found!" << endl;
                return id;
            }
        }

        read.close();
    }
    if (31 <= id and id <= 40)
    {
        employee s;
        ifstream read;
        read.open("31to40.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id == id)
            {
                cout << "employee's record found!" << endl;
                return id;
            }
        }

        read.close();
    }
    if (41 <= id and id <= 50)
    {
        employee s;
        ifstream read;
        read.open("41to50.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id == id)
            {
                cout << "employee's record found!" << endl;
                return id;
            }
        }

        read.close();
    }

    return -1;
}

void delete_employees(int id)
{
    id = search_employees(id);

    if (id == -1)
    {
        cout << "employee record to be deleted is not present in the file!" << endl;
        return;
    }

    if (1 <= id and id <= 10)
    {
        employee s;
        ifstream read;
        ofstream write;
        read.open("1to10.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id != id)
            {
                write << "\n"
                      << s.id;
                write << "\n"
                      << s.name;
                write << "\n"
                      << s.desg;
                write << "\n"
                      << s.salary;
            }
        }
        read.close();
        write.close();
        remove("1to10.txt");
        rename("temp.txt", "1to10.txt");
    }
    if (11 <= id and id <= 20)
    {
        employee s;
        ifstream read;
        ofstream write;
        read.open("11to20.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id != id)
            {
                write << "\n"
                      << s.id;
                write << "\n"
                      << s.name;
                write << "\n"
                      << s.desg;
                write << "\n"
                      << s.salary;
            }
        }
        read.close();
        write.close();
        remove("11to20.txt");
        rename("temp.txt", "11to20.txt");
    }
    if (21 <= id and id <= 30)
    {
        employee s;
        ifstream read;
        ofstream write;
        read.open("21to30.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id != id)
            {
                write << "\n"
                      << s.id;
                write << "\n"
                      << s.name;
                write << "\n"
                      << s.desg;
                write << "\n"
                      << s.salary;
            }
        }
        read.close();
        write.close();
        remove("21to30.txt");
        rename("temp.txt", "21to30.txt");
    }
    if (31 <= id and id <= 40)
    {
        employee s;
        ifstream read;
        ofstream write;
        read.open("31to40.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id != id)
            {
                write << "\n"
                      << s.id;
                write << "\n"
                      << s.name;
                write << "\n"
                      << s.desg;
                write << "\n"
                      << s.salary;
            }
        }
        read.close();
        write.close();
        remove("31to40.txt");
        rename("temp.txt", "31to40.txt");
    }
    if (41 <= id and id <= 50)
    {
        employee s;
        ifstream read;
        ofstream write;
        read.open("1to10.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> s.id;
            read >> s.name;
            read >> s.desg;
            read >> s.salary;
            if (s.id != id)
            {
                write << "\n"
                      << s.id;
                write << "\n"
                      << s.name;
                write << "\n"
                      << s.desg;
                write << "\n"
                      << s.salary;
            }
        }
        read.close();
        write.close();
        remove("41to50.txt");
        rename("temp.txt", "41to50.txt");
    }
}

int main()
{
    cout << "\nPrepared By - Anshul Singh" << endl;
    cout << "Practical No. 12 (F -24)" << endl;
    int ch;
    while (1)
    {
        cout << "\n----MENU----" << endl;
        cout << "\n1. Add Employee, 2.Display Employee, 3.Search Employee, 4.Delete Employee, 5.Exit" << endl;
        cin >> ch;
        cout<<endl;

        if (ch == 1)
        {
            add_employees();
        }
        else if (ch == 2)
        {
            display_employees();
        }
        else if (ch == 3)
        {
            int temp;
            cout << "Enter the ID of employee to search" << endl;
            cin >> temp;
            int x = search_employees(temp);
            if (x == -1)
            {
                cout << "Record not found!" << endl;
                cout << endl;
            }
        }
        else if (ch == 4)
        {
            int temp;
            cout << "Enter the ID of employee to delete" << endl;
            cin >> temp;
            delete_employees(temp);
        }
        else if (ch == 5)
        {
            exit(0);
        }
    }
    return 0;
}