// Griffin Dunlap
// Vector program that reads an unkown number of records and stores the data into vector variables
// 9/25/2024

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void checkFile(ifstream& iFile);
void getData(ifstream& iFile, vector<string>& fName, vector<string>& lName, vector<string>& major, vector<string>& advisor, vector<string>& hClass, vector<string>& eClass, vector<int>& tNum, vector<int>& cHours, vector<int>& gYear, vector<double>& gpa);
void fullOutput(ofstream &oFile, vector<string>& fName, vector<string>& lName, vector<string>& major, vector<string>& advisor, vector<string>& hClass, vector<string>& eClass, vector<int>& tNum, vector<int>& cHours, vector<int>& gYear, vector<double>& gpa);
void creditOutput(ofstream& oFile, vector<string>& lName, vector<string>& major, vector<string>& advisor, vector<string>& hClass, vector<string>& eClass, vector<string>& fName, vector<int>& tNum, vector<int>& cHours, vector<int>& gYear, vector<double>& gpa);
void gpaOutput(ofstream& oFile, vector<string>& lName, vector<string>& major, vector<string>& advisor, vector<string>& hClass, vector<string>& eClass, vector<string>& fName, vector<int>& tNum, vector<int>& cHours, vector<int>& gYear, vector<double>& gpa);


int main()
{
    // Initializing the vector variables for getData
    vector<string> fName, lName, major, advisor, hClass, eClass;
    vector<int> tNum, cHours, gYear;
    vector<double> gpa;

    // Creating, opening, and checking files
    ifstream iFile;
    ofstream oFile;
    iFile.open("input.txt");
    oFile.open("output.txt");

    checkFile(iFile);

    // Calling getData function for the vector information about the students
    getData(iFile, fName, lName, major, advisor, hClass, eClass, tNum, cHours, gYear, gpa);
    // Calling fullOutput to give all the information listed for each student
    fullOutput(oFile, fName, lName, major, advisor, hClass, eClass, tNum, cHours, gYear, gpa);
    // Calling creditOutput to give the information of the highest credit student
    creditOutput(oFile, fName, lName, major, advisor, hClass, eClass, tNum, cHours, gYear, gpa);
    // Calling gpaOutput to give the information of the highest gpa student
    gpaOutput(oFile, fName, lName, major, advisor, hClass, eClass, tNum, cHours, gYear, gpa);

    // Closing the files
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

void getData(ifstream& iFile, vector<string>& fName, vector<string>& lName, vector<string>& major, vector<string>& advisor, vector<string>& hClass, vector<string>& eClass, vector<int>& tNum, vector<int>& cHours, vector<int>& gYear, vector<double>& gpa)
{

    // Temp variables for string, int, and double variables
    string tempS;
    int tempI;
    double tempD;
    
    // Using the vector to get each piece of info from each student
    while (!iFile.eof())
    {
        getline(iFile, tempS);
        fName.push_back(tempS);
        getline(iFile, tempS);
        lName.push_back(tempS);
        iFile >> tempI;
        tNum.push_back(tempI);
        iFile.ignore();
        getline(iFile, tempS);
        major.push_back(tempS);
        getline(iFile, tempS);
        advisor.push_back(tempS);
        iFile >> tempD;
        gpa.push_back(tempD);
        iFile >> tempI;
        cHours.push_back(tempI);
        iFile >> tempI;
        gYear.push_back(tempI);
        iFile.ignore();
        getline(iFile, tempS);
        hClass.push_back(tempS);
        getline(iFile, tempS);
        eClass.push_back(tempS);
    }

}

void fullOutput(ofstream &oFile, vector<string>& fName, vector<string>& lName, vector<string>& major, vector<string>& advisor, vector<string>& hClass, vector<string>& eClass, vector<int>& tNum, vector<int>& cHours, vector<int>& gYear, vector<double>& gpa)
{
    // For loop to display all the info to both the console and output file for each student stopping once 'a' reaches the amount of student names in the file
    for (int a = 0; a < fName.size(); a++)
    {
        cout << fName[a] << " " << lName[a] << " " << tNum[a] << " " << major[a] << " " << advisor[a] << " " << gpa[a] << " " << cHours[a] << " " << gYear[a] << " " << hClass[a] << " " << eClass[a] << endl;
        oFile << fName[a] << " " << lName[a] << " " << tNum[a] << " " << major[a] << " " << advisor[a] << " " << gpa[a] << " " << cHours[a] << " " << gYear[a] << " " << hClass[a] << " " << eClass[a] << endl;
    }
}

void creditOutput(ofstream& oFile, vector<string>& fName, vector<string>& lName, vector<string>& major, vector<string>& advisor, vector<string>& hClass, vector<string>& eClass, vector<int>& tNum, vector<int>& cHours, vector<int>& gYear, vector<double>& gpa)
{
    // Create a temp variable to sort through each students credit hours by comparing the newest one to the last and display the one with the highest amount
    int temp = 0;
    for (int a = 1; a < fName.size(); a++)
    {
        if (cHours[a] > cHours[temp])
        {
            temp = a;
            // The cout here and the one in the next function are just here to make it look better
            cout << endl;
            cout << "Highest Credit Hour Student: " << fName[a] << " " << lName[a] << " " << tNum[a] << " " << major[a] << " " << advisor[a] << " " << gpa[a] << " " << cHours[a] << " " << gYear[a] << " " << hClass[a] << " " << eClass[a] << endl;
            oFile << "Highest Credit Hour Student: " << fName[a] << " " << lName[a] << " " << tNum[a] << " " << major[a] << " " << advisor[a] << " " << gpa[a] << " " << cHours[a] << " " << gYear[a] << " " << hClass[a] << " " << eClass[a] << endl;
        }
    }
}

void gpaOutput(ofstream& oFile, vector<string>& fName, vector<string>& lName, vector<string>& major, vector<string>& advisor, vector<string>& hClass, vector<string>& eClass, vector<int>& tNum, vector<int>& cHours, vector<int>& gYear, vector<double>& gpa)
{
    // Create a temp variable to sort through each students gpa by comparing the newest one to the last and display the one with the highest amount
    int temp = 0;
    for (int a = 1; a < fName.size(); a++)
    {
        if (gpa[a] > gpa[temp])
        {
            temp = a;
            cout << endl;
            cout << "Highest GPA Student: " << fName[a] << " " << lName[a] << " " << tNum[a] << " " << major[a] << " " << advisor[a] << " " << gpa[a] << " " << cHours[a] << " " << gYear[a] << " " << hClass[a] << " " << eClass[a] << endl;
            oFile << "Highest GPA Student: " << fName[a] << " " << lName[a] << " " << tNum[a] << " " << major[a] << " " << advisor[a] << " " << gpa[a] << " " << cHours[a] << " " << gYear[a] << " " << hClass[a] << " " << eClass[a] << endl;
        }
    }
}