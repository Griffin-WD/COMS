// Griffin Dunlap
// Bubble Sorting project with superhero names
// September 18 2024

#include <iostream>
#include<string>
#include <fstream>

using namespace std;

// Calling the functions to be used in main

void checkFile(ifstream& iFile);
int getData(ifstream& iFile, string countingArray[]);
void output(string countingArray[], int counter);
void bubbleSort(int counter, string fNameArray[], string lNameArray[]);
void printMenu(int counter, string fNameArray[], string lNameArray[]);

int main()
{
    // Constant for setting the array size to a consistent 100
    const int SIZE = 100;
    string fNames[SIZE];
    string lNames[SIZE];
    
    // Opening and calling the checkFile Function to check the files and open them

    ifstream fNameIn, lNameIn;
    fNameIn.open("fNames.txt");
    lNameIn.open("lNames.txt");

    checkFile(fNameIn);
    checkFile(lNameIn);

    // Calling counter and getData function to get info needed to get the amount of names for each

    int counter = getData(fNameIn, fNames);
    counter = getData(lNameIn, lNames);

    // Calling printMenu function to ask the user the question of which sorting they want and display it

    printMenu(counter, fNames, lNames);
}
void checkFile(ifstream& iFile)
{
    if (!iFile.is_open())
    {
        cout << "Input file not found" << endl;
        exit(1);
    }
}

int getData(ifstream& iFile, string countingArray[])
{
    int counter = 0;

    while (!iFile.eof())
    {
        getline(iFile, countingArray[counter]);
        counter++;
    }

    return counter;
}

void output(string countingArray[], int counter)
{
    for (int a = 0; a < counter; a++) 
    {
        cout << countingArray[a] << endl;
    }
}

void bubbleSort(int counter, string fNameArray[], string lNameArray[])
{
    string temp;
    for (int a = 0; a < counter; a++) {
        for (int b = 0; b < counter - 1; b++) {
            if (fNameArray[b] > fNameArray[b + 1]) {
                temp = fNameArray[b];
                fNameArray[b] = fNameArray[b + 1];
                fNameArray[b + 1] = temp;
                temp = lNameArray[b];
                lNameArray[b] = lNameArray[b + 1];
                lNameArray[b + 1] = temp;
            }
        }
    }
}

void printMenu(int counter, string fNameArray[], string lNameArray[])
{
    cout << "----------------------" << endl;
    cout << "1 - Sort by First Name" << endl;   
    cout << "2 - Sort by Last Name" << endl;
    cout << "----------------------" << endl;

    int input;
    cin >> input;
    if (input == 1)
    {
        bubbleSort(counter, fNameArray, lNameArray);
        output(fNameArray, counter);
    }
    else if (input == 2)
    {
        bubbleSort(counter, lNameArray, fNameArray);
        output(lNameArray, counter);
    }
    else
    {
        cout << "Invalid Input";
    }
}