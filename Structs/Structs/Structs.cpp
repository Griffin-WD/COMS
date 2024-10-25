// Griffin Dunlap
// Structs program that uses a struct with array or vector variables to give output of employees
// 9/30/2024

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Global Struct for the employees base information
struct employee 
{
    string fName, lName, job, empNum;
    double hrsWorked, wage, oPay, oWage, oHours, gross, netPay, tax;
    int deductions;
};

void getData(int& empAmount, employee info[]);
void getOvertime(int& empAmount, employee info[]);
void getTax(int& empAmount, employee info[]);
void output(int& empAmount, employee info[]);

int main()
{   
    // Variables, setting array size, and setting the decimal places to 2 points
    int empAmount;
    employee info[100];

    cout << fixed << showpoint << setprecision(2);

    // Calling all of the functions to do the program
    getData(empAmount, info);
    getOvertime(empAmount, info);
    getTax(empAmount, info);
    output(empAmount, info);
}
// getData asks the user for all of the information needed for the calculations and outputs while using both a struct and array to keep that information for each user and give it to the other functions
void getData(int &empAmount, employee info[])
{
    cout << "How many employees information will you be giving: " << endl;
    cin >> empAmount;

    for (int a = 0; a < empAmount; a++)
    {
        cout << "Enter First Name: ";
        cin >> info[a].fName;

        cout << "Enter Last Name: ";
        cin >> info[a].lName;

        cout << "Enter Job Title: ";
        cin >> info[a].job;

        cout << "Enter Employee Number: ";
        cin >> info[a].empNum;

        cout << "Enter Hours Worked: ";
        cin >> info[a].hrsWorked;

        cout << "Enter Hourly Wage: ";
        cin >> info[a].wage;

        cout << "Enter Number of Deductions: ";
        cin >> info[a].deductions;
        cin.ignore();
    }
}
// For both getOvertime and getTax I included the math to determine everything instead of making a different function to shorten the program
// getOvertime calculates the overtime hours and money by increasing the amount made if somebody has worked more than 40 hours
void getOvertime(int& empAmount, employee info[])
{
    for (int a = 0; a < empAmount; a++)
    {
        if (info[a].hrsWorked > 40)
        {
            info[a].oWage = info[a].wage * 1.5;
            info[a].oHours = info[a].hrsWorked - 40;
            info[a].oPay = info[a].oWage * info[a].oHours;
            info[a].gross = 40 * info[a].wage + info[a].oPay;
        }
        else
        {
            info[a].oWage = 0;
            info[a].oHours = 0;
            info[a].oPay = 0;
            info[a].gross = info[a].hrsWorked * info[a].wage;
        }
    }
}
// getTax takes the users input on how many deductions they filed and then setting the tax amount based on that number. It also calculate the overall tax and net pay
void getTax(int& empAmount, employee info[])
{
    for (int a = 0; a < empAmount; a++) 
    {
        if (info[a].deductions <= 0)
            info[a].tax = .35;
        else if (info[a].deductions == 1)
            info[a].tax = .30;
        else if (info[a].deductions == 2)
            info[a].tax = .25;
        else if (info[a].deductions == 3)
            info[a].tax = .20;
        else
            info[a].tax = .15;

        info[a].tax = info[a].tax * info[a].gross;
        info[a].netPay = info[a].gross - info[a].tax;
    }
}
// output displays all of the information of every employee and displays the overtime pay if the employee had overtime
void output(int& empAmount, employee info[])
{
    for (int a = 0; a < empAmount; a++)
    {
        if (info[a].hrsWorked <= 40)
        {
            cout << endl;
            cout << "Name: " << info[a].lName << ", " << info[a].fName << endl;
            cout << "Job Title: " << info[a].job << endl;
            cout << "Employee Number: " << info[a].empNum << endl;
            cout << "Deductions Claimed: " << info[a].deductions << endl;
            cout << "Hours Worked: " << info[a].hrsWorked << endl;
            cout << "Hourly Wage: $" << info[a].wage << endl;
            cout << "Gross Pay: $" << info[a].gross << endl;
            cout << "Taxes Withheld: $" << info[a].tax << endl;
            cout << "Net Pay: $" << info[a].netPay << endl;
        }
        else
        {
            cout << endl;
            cout << "Name: " << info[a].lName << ", " << info[a].fName << endl;
            cout << "Job Title: " << info[a].job << endl;
            cout << "Employee Number: " << info[a].empNum << endl;
            cout << "Deductions Claimed: " << info[a].deductions << endl;
            cout << "Hours Worked: " << info[a].hrsWorked << endl;
            cout << "Hourly Wage: $" << info[a].wage << endl;
            cout << "Gross Pay: $" << info[a].gross << endl;
            cout << "Taxes Withheld: $" << info[a].tax << endl;
            cout << "Net Pay: $" << info[a].netPay << endl;
            cout << "Overtime Pay: $" << info[a].oPay << endl;
        }
    }
}