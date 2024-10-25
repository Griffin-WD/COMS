// Griffin Dunlap
// Midterm where we use what we've learned so far to take info from an input file then sort it and output it using arrays, vectors, structs, etc...
// 11/7/2024

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Creating a struct for all of the employee information
struct employee {
    string fName, lName, jobTitle;
    double gross, timeEmployed;
};

void checkFile(ifstream& iFile);
void swapData(vector<employee>& info, int b);
void sortData(vector<employee>& info, int choice);
void getData(vector<employee>& info, ifstream& iFile);
void displayMenu(vector<employee>& info, int choice, ofstream& oFile);
void output(vector<employee>& info, int choice, ofstream& oFile);

int main()
{
    // Setting decimals to 2 places for correct output and creating variables / vectors
    cout << fixed << showpoint << setprecision(2);
    vector<employee> info;
    int choice = 0;
    
    // Opening and checking files
    ifstream iFile;
    ofstream oFile;
    iFile.open("input.txt");
    oFile.open("output.txt");
    checkFile(iFile);

    // Gets the data from the input file
    getData(info, iFile);
    // Sorts the data from the input file
    sortData(info, choice);
    // Displays a menu for the user to choose how they want the information output
    displayMenu(info, choice, oFile);
    // Outputs what was chosen
    output(info, choice, oFile);

    // Closing files
    iFile.close();
    oFile.close();
}

void checkFile(ifstream& iFile)
{
    if (!iFile.is_open())
    {
        cout << "Input file not found" << endl;
        exit(1);
    }
}
// swapData is used to make the code a little less repetitive
void swapData(vector<employee>& info, int b)
{
    employee temp;
    temp = info[b];
    info[b] = info[b + 1];
    info[b + 1] = temp;
}
// sortData takes the data from each employee and compares them and replaces them in different ways to then give to the output function to display
void sortData(vector<employee>& info, int choice)
{
    for (int a = 0; a < info.size(); a++)
    {
        for (int b = 0; b < info.size() - 1; b++)
        {
            if (choice == 1)
            {
                if (info[b].lName > info[b + 1].lName)
                {
                    swapData(info, b);
                }
            }
            if (choice == 2)
            {
                if (info[b].jobTitle > info[b + 1].jobTitle)
                {
                    swapData(info, b);
                }
            }
            if (choice == 3)
            {
                if (info[b].timeEmployed < info[b + 1].timeEmployed)
                {
                    swapData(info, b);
                }
            }
            if (choice == 4)
            {
                if (info[b].gross < info[b + 1].gross)
                {
                    swapData(info, b);
                }
            }
            if (choice == 5)
            {
                if (info[b].gross > info[b + 1].gross)
                {
                    swapData(info, b);
                }
            }
            if (choice == 6)
            {
                if (info[b].timeEmployed > info[b + 1].timeEmployed)
                {
                   swapData(info, b);
                }
            }
        }
    }
}
// getData gets all of the information of the employees
void getData(vector<employee>& info, ifstream& iFile)
{
    employee temp;

    while (!iFile.eof())
    {
        getline(iFile, temp.fName);
        getline(iFile, temp.lName);
        getline(iFile, temp.jobTitle);
        iFile >> temp.timeEmployed;
        iFile >> temp.gross;
        iFile.ignore();
        info.push_back(temp);
    }
}
// displayMenu puts a menu onto the screen for the user to choose which type of way they want the information sorted or displayed
void displayMenu(vector<employee>& info, int choice, ofstream& oFile)
{
    while (choice != 7)
    {
        cout << "Please select one of the following options" << endl;
        cout << "1 - Sort by name(Last, First)" << endl;
        cout << "2 - Sort by Job Title" << endl;
        cout << "3 - Sort by Time Employed(highest to lowest)" << endl;
        cout << "4 - Sort by Gross Pay(highest to lowest)" << endl;
        cout << "5 - Display information of highest paid employee" << endl;
        cout << "6 - Display information of longest employed employee" << endl;
        cout << "7 - Exit the program" << endl;
        cin >> choice;

        sortData(info, choice);
        output(info, choice, oFile);
        // Shows an error message if the user inputs something invalid
        if (choice < 1 || choice > 7)
        {
            cout << "Invalid input, try again." << endl << endl;
            oFile << "Invalid input, try again." << endl << endl;
        }
    }
}
// output displays the information the user wants to both the console and the output file
void output(vector<employee>& info, int choice, ofstream& oFile)
{
    // Outputs what is being displayed outside of the loop so it doesn't repeat
    if (choice == 1)
    {
        cout << "Now sorting by name(Last, First)" << endl << endl;
        oFile << "Now sorting by name(Last, First)" << endl << endl;
    }
    else if (choice == 2)
    {
        cout << "Now sorting by job title" << endl << endl;
        oFile << "Now sorting by job title" << endl << endl;
    }
    else if (choice == 3)
    {
        cout << "Now sorting by time employed from highest to lowest" << endl << endl;
        oFile << "Now sorting by time employed from highest to lowest" << endl << endl;
    }
    else if (choice == 4)
    {
        cout << "Now sorting by gross pay from highest to lowest" << endl << endl;
        oFile << "Now sorting by gross pay from highest to lowest" << endl << endl;
    }
    // Loop used to output the information chosen by the user 
    for (int a = 0; a < info.size(); a++)
    {
        if (choice == 1)
        {
            cout << info[a].lName << ", " << info[a].fName << endl;
            cout << info[a].jobTitle << endl;
            cout << info[a].timeEmployed << " years" << endl;
            cout << "$" << info[a].gross << endl << endl;
            oFile << info[a].lName << ", " << info[a].fName << endl;
            oFile << info[a].jobTitle << endl;
            oFile << info[a].timeEmployed << " years" << endl;
            oFile << "$" << info[a].gross << endl << endl;
        }
        else if (choice == 2)
        {
            cout << info[a].lName << ", " << info[a].fName << endl;
            cout << info[a].jobTitle << endl;
            cout << info[a].timeEmployed << " years" << endl;
            cout << "$" << info[a].gross << endl << endl;
            oFile << info[a].lName << ", " << info[a].fName << endl;
            oFile << info[a].jobTitle << endl;
            oFile << info[a].timeEmployed << " years" << endl;
            oFile << "$" << info[a].gross << endl << endl;
        }
        else if (choice == 3)
        {
            cout << info[a].lName << ", " << info[a].fName << endl;
            cout << info[a].jobTitle << endl;
            cout << info[a].timeEmployed << " years" << endl;
            cout << "$" << info[a].gross << endl << endl;
            oFile << info[a].lName << ", " << info[a].fName << endl;
            oFile << info[a].jobTitle << endl;
            oFile << info[a].timeEmployed << " years" << endl;
            oFile << "$" << info[a].gross << endl << endl;
        }
        else if (choice == 4)
        {
            cout << info[a].lName << ", " << info[a].fName << endl;
            cout << info[a].jobTitle << endl;
            cout << info[a].timeEmployed << " years" << endl;
            cout << "$" << info[a].gross << endl << endl;
            oFile << info[a].lName << ", " << info[a].fName << endl;
            oFile << info[a].jobTitle << endl;
            oFile << info[a].timeEmployed << " years" << endl;
            oFile << "$" << info[a].gross << endl << endl;
        }
        // Displays the information of either the highest paid or longest employed employee(chosen by the user) only if it's at the end of the loop
        if (a == info.size() - 1)
        {
            if (choice == 5)
            {
                cout << "Now displaying information of highest paid employee" << endl << endl;
                cout << info[a].lName << ", " << info[a].fName << endl;
                cout << info[a].jobTitle << endl;
                cout << info[a].timeEmployed << " years" << endl;
                cout << "$" << info[a].gross << endl << endl;
                oFile << "Now displaying information of highest paid employee" << endl << endl;
                oFile << info[a].lName << ", " << info[a].fName << endl;
                oFile << info[a].jobTitle << endl;
                oFile << info[a].timeEmployed << " years" << endl;
                oFile << "$" << info[a].gross << endl << endl;
            }
            else if (choice == 6)
            {
                cout << "Now displaying information of longest employed employee" << endl << endl;
                cout << info[a].lName << ", " << info[a].fName << endl;
                cout << info[a].jobTitle << endl;
                cout << info[a].timeEmployed << " years" << endl;
                cout << "$" << info[a].gross << endl << endl;
                oFile << "Now displaying information of longest employed employee" << endl << endl;
                oFile << info[a].lName << ", " << info[a].fName << endl;
                oFile << info[a].jobTitle << endl;
                oFile << info[a].timeEmployed << " years" << endl;
                oFile << "$" << info[a].gross << endl << endl;
            }
        }
    }
}