#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct patient
{
    long long ID;
    string firstname;
    string lastname;
    int age;
    string blood;
    char gender;
    patient* next;
};

class linkedqueue
{
    patient* head, * last;
public:
    linkedqueue() // constructor
    {
        head = NULL;
        last = NULL;
    }
    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void listofpatients();
    int search(int);
    string departmentname;
};

int linkedqueue::search(int item)
{
    patient* p = head;
    while (p != NULL)
    {
        if (p->ID == item)
            return true;
        p = p->next;
    }
    return false;
}

int readnumber()
{
    string input;
    getline(cin, input);
    return atoi(input.c_str());
}

patient linkedqueue::input()
{
    patient* p = new patient();
    cout << "\n   Please enter data for patient\n";
    cout << "\n   First name     : ";
    getline(cin, p->firstname);
    cout << "   Last name      : ";
    getline(cin, p->lastname);
    int flag = 0;
    do
    {
        cout << "   Blood Group    : ";
        cin >> p->blood;
        if (p->blood == "A+" || p->blood == "a+" || p->blood == "A-" || p->blood == "a-" ||
            p->blood == "B+" || p->blood == "b+" || p->blood == "B-" || p->blood == "b-" ||
            p->blood == "O+" || p->blood == "o+" || p->blood == "O-" || p->blood == "o-" ||
            p->blood == "AB+" || p->blood == "ab+" || p->blood == "AB-" || p->blood == "ab-")
        {
            flag = 1;
        }
        else
        {
            cout << "\n   Invalid Blood Group. Try Again.\n\n";
        }
    } while (flag == 0);

    cout << "   Gender(m/f)    : ";
    cin >> p->gender;
    cout << "   Age            : ";
    cin >> p->age;
    cout << "   Mobile number  : ";
    cin >> p->ID;

    if (search(p->ID))
    {
        p->ID = 0;
        cout << "\n   Data not valid. Operation cancelled.";
    }
    return *p;
}

void output(patient* p)
{
    cout << "\n  ---------------------------------";
    cout << "\n   Patient data:";
    cout << "\n   First Name         : " << p->firstname;
    cout << "\n   Last Name          : " << p->lastname;
    cout << "\n   Gender             : " << p->gender;
    cout << "\n   Age                : " << p->age;
    cout << "\n   Blood Group        : " << p->blood;
    cout << "\n   Mobile Number      : " << p->ID;
    cout << "\n  ---------------------------------";
}

void linkedqueue::insertatbeg()
{
    patient* p = new patient();
    *p = input();
    if (p->ID == 0)
    {
        delete p;
        return;
    }

    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = head;
        head = p;
    }
    system("cls");
    cout << "\n\tPatient added:";
    output(p);
}

void linkedqueue::insertatend()
{
    patient* p = new patient();
    *p = input();
    if (p->ID == 0)
    {
        delete p;
        return;
    }

    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = NULL;
        last->next = p;
        last = p;
    }
    system("cls");
    cout << "\n  ---------------------------------";
    cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  ---------------------------------";
    cout << "\n\n  ----------PATIENT ADDED-----------";
    output(p);
}

void linkedqueue::getpatientout()
{
    system("cls");
    if (head == NULL)
    {
        cout << "\n  No Patient to operate";
    }
    else
    {
        patient* p = head;
        head = head->next;
        cout << "\n  Patient to operate:";
        output(p);
        delete p;
    }
}

void linkedqueue::listofpatients()
{
    if (head == NULL)
    {
        cout << "\n  No patient";
    }
    system("cls");
    cout << "\n  ---------------------------------";
    cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  ---------------------------------";
    patient* p = head;
    while (p != NULL)
    {
        cout << "\n   Patient data:\n";
        cout << "\n   First Name       : " << p->firstname;
        cout << "\n   Last Name        : " << p->lastname;
        cout << "\n   Gender           : " << p->gender;
        cout << "\n   Age              : " << p->age;
        cout << "\n   Blood Group      : " << p->blood;
        cout << "\n   Mobile Number    : " << p->ID;
        cout << "\n  ---------------------------------";
        p = p->next;
    }
    cout << "\n";
}

void departmentmenu(linkedqueue* q)
{
    int choice = 0;
    while (choice != 5)
    {
        system("cls");
        cout << "\n  ---------------------------------";
        cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  ---------------------------------";
        cout << "\n\n   " << q->departmentname;
        cout << "\n   [1] Add normal patient";
        cout << "\n   [2] Add critically ill patient";
        cout << "\n   [3] Take patient to Doctor";
        cout << "\n   [4] Display list";
        cout << "\n   [5] Change department or exit";
        cout << "\n\n   Please enter your choice : ";
        choice = readnumber();
        cout << "\n  ---------------------------------";

        switch (choice)
        {
        case 1:
            q->insertatend();
            cout << "\n   Press any key";
            cin.ignore();
            cin.get();
            break;

        case 2:
            q->insertatbeg();
            cout << "\n   Press any key";
            cin.ignore();
            cin.get();
            break;

        case 3:
            q->getpatientout();
            cout << "\n   Press any key";
            cin.ignore();
            cin.get();
            break;

        case 4:
            system("cls");
            q->listofpatients();
            cout << "\n   Press any key";
            cin.ignore();
            cin.get();
            break;
        }
    }
}

int main()
{
    int choice = 0;
    linkedqueue departments[4];

    while (choice != 5)
    {
        departments[0].departmentname = "GENERAL CLINIC";
        departments[1].departmentname = "HEART CLINIC";
        departments[2].departmentname = "LUNG CLINIC";
        departments[3].departmentname = "PLASTIC SURGERY";
        system("cls");
        cout << "\n  ---------------------------------";
        cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  ---------------------------------";
        cout << "\n\n   Main Menu\n";
        for (int i = 0; i < 4; i++)
        {
            cout << "\n   " << (i + 1) << ": " << departments[i].departmentname;
        }
        cout << "\n   5: Exit";
        cout << "\n\n   Please enter your choice : ";
        choice = readnumber();
        if (choice >= 1 && choice <= 4)
        {
            departmentmenu(&departments[choice - 1]);
        }
    }
    if (choice == 5)
        cout << "\n\t\tThank you! \n";
    return 0;
}


/*
************************************************************
*                     CODE   BY                            *
*                      WaRRioR                             *
*                                                          *
************************************************************
*/