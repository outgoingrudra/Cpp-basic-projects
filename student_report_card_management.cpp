#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class Student {
    string RollNo, Name, Grade;
    int Physics, Maths, Computer;
    float Total, Average;

public:
    Student() : RollNo(""), Name(""), Grade(""), Physics(0), Maths(0), Computer(0), Total(0), Average(0) {}

    void inputMarksOnly() {
        cout << "\tEnter Roll Number of Student: ";
        cin >> RollNo;

        cout << "\tEnter Name of Student: ";
        cin >> Name;

        cout << "\tEnter Physics Marks: ";
        cin >> Physics;

        cout << "\tEnter Maths Marks: ";
        cin >> Maths;

        cout << "\tEnter Computer Marks: ";
        cin >> Computer;

        cout << "\n\tMarks Stored Successfully.\n";
    }

    void inputDetails() {
        inputMarksOnly();
        calculateGrade();
    }

    void calculateGrade() {
        Total = Physics + Maths + Computer;
        Average = Total / 3.0;

        if (Average >= 90)
            Grade = "A+";
        else if (Average >= 80)
            Grade = "A";
        else if (Average >= 70)
            Grade = "B";
        else if (Average >= 60)
            Grade = "C";
        else if (Average >= 50)
            Grade = "D";
        else
            Grade = "F";
    }

    void displayReportCard() {
        cout << "\n\t------ Report Card ------\n";
        cout << "\tName     : " << Name << endl;
        cout << "\tRoll No  : " << RollNo << endl;
        cout << "\tPhysics  : " << Physics << endl;
        cout << "\tMaths    : " << Maths << endl;
        cout << "\tComputer : " << Computer << endl;
        cout << "\tTotal    : " << Total << "/300" << endl;
        cout << "\tAverage  : " << Average << "%" << endl;
        cout << "\tGrade    : " << Grade << endl;
        cout << "\t--------------------------\n";
    }
};

int main() {
    Student s;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;

        cout << "\tWelcome To Student Report Card System \n";
        cout << "\t**************************************\n";
        cout << "\t1. Generate Report Card\n";
        cout << "\t2. Enter Marks Only\n";
        cout << "\t3. Exit\n";
        cout << "\tEnter Choice: ";
        cin >> val;

        switch (val) {
            case 1:
                system("cls");
                s.inputDetails();
                system("cls");
                s.displayReportCard();
                system("pause");
                break;

            case 2:
                system("cls");
                s.inputMarksOnly();
                system("pause");
                break;

            case 3:
                exit = true;
                break;

            default:
                cout << "\tInvalid Choice. Try Again.\n";
                system("pause");
        }
    }

    return 0;
}
