// Griffin Dunlap
// This program aims to make a class and a child class that is used to collect info
// 10/23/2024

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// including person.h because I made a header file that needs to be included
#include "Person.h"

using namespace std;

// created a class and child class that inherits its information. I had to make functions to get the information from the private class (and protected class in the header)
class Student : public Person {
public:
    void setMajor(string text)
    {
        major = text;
    }
    void setGPA(int number)
    {
        gpa = number;
    }
    void setgradYear(int number)
    {
        gradYear = number;
    }
    void setcHours(int number)
    {
        cHours = number;
    }
    string getMajor()
    {
        return major;
    }
    int getcHours()
    {
        return cHours;
    }
    double getGPA()
    {
        return gpa;
    }
    int getgradYear()
    {
        return gradYear;
    }
    // getData gets the data of each student by creating a temp variable and assigning the information of a student to it then going on to the next student until there aren't anymore students
    void getData(vector<Student>& atu, ifstream& iFile)
    {
        while (!iFile.eof())
        {
            Student temp;
            iFile >> temp.fName;
            iFile >> temp.lName;
            iFile.ignore();
            getline(iFile, temp.address);
            iFile >> temp.city;
            iFile >> temp.state;
            iFile >> temp.zip;
            iFile >> temp.phoneNum;
            iFile.ignore();
            getline(iFile, temp.major);
            iFile >> temp.gpa;
            iFile >> temp.gradYear;
            iFile >> temp.cHours;
            atu.push_back(temp);
        }
    }
    // averageGPA gets the average GPA of the students by adding each students GPA then dividing it by the amount of students
    void averageGPA(vector<Student>& atu)
    {
        double totalGPA = 0;
        double averageGPA = 0;
        for (int a = 0; a < atu.size(); a++)
        {
            totalGPA += atu[a].gpa;
        }
        averageGPA = totalGPA / atu.size();

        cout << "Average GPA: " << averageGPA << endl << endl;
    }
    // highlowGPA gets the highest and lowest GPA of the students by sorting through them and comparing the gpa of the current student to the last students gpa and then replacing it
    void highlowGPA(vector<Student>& atu)
    {
        double highGPA = 0;
        double lowGPA = 100;
        for (int a = 0; a < atu.size(); a++)
        {
            if (atu[a].gpa > highGPA)
            {
                highGPA = atu[a].gpa;
            }
            else if (atu[a].gpa < lowGPA)
            {
                lowGPA = atu[a].gpa;
            }
        }
        cout << "Highest GPA: " << highGPA << endl;
        cout << "Lowest GPA: " << lowGPA << endl;
    }
    // output displays the information of each student
    void output(vector<Student>& atu)
    {
        for (int a = 0; a < atu.size(); a++)
        {
            cout << "Name: " << atu[a].getfName() << " " << atu[a].getlName() << endl;
            cout << "Address: " << atu[a].getAddress() << endl;
            cout << "City: " << atu[a].getCity() << endl;
            cout << "State: " << atu[a].getState() << endl;
            cout << "ZIP Code: " << atu[a].getZip() << endl;
            cout << "Phone Number: " << atu[a].getphoneNum() << endl;
            cout << "Major: " << atu[a].getMajor() << endl;
            cout << "GPA: " << atu[a].getGPA() << endl;
            cout << "Year of graduation: " << atu[a].getgradYear() << endl;
            cout << "Credit Hours: " << atu[a].getcHours() << endl << endl;
        }
        averageGPA(atu);
        highlowGPA(atu);
    }

private:
    string major;
    double gpa;
    int cHours, gradYear;
};

int main()
{
    // Creating a vector for Student child class and temp variable for it
    vector<Student> atu;
    Student temp;
    // Opening and checking file
    ifstream iFile;
    iFile.open("input.txt");
    fileCheck(iFile);
    // Calling all of the functions to run the code
    temp.getData(atu, iFile);
    temp.output(atu);

    // Closing file
    iFile.close();
}