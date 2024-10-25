// Griffin Dunlap
// Project 1 program with files, functions, and arrays
// August 30 2024

#include <iostream>
#include<string>
#include<fstream>
using namespace std;

void checkFile(ifstream& iFile)
{
	if (!iFile.is_open())
	{
		cout << "Input file not found" << endl;
		exit(1);
	}
}

int getData(ifstream& iFile, string classes[])
{
	int counter = 0;

	while (!iFile.eof())
	{
		getline(iFile, classes[counter]);
		counter++;
	}

	return counter;
}

void output(int counter, string classes[], ofstream& oFile)
{
	for (int i = 0; i < counter; i++)
	{
		cout << "Class Names: " << classes[i] << endl;
		oFile << "Class Names: " << classes[i] << endl;
	}
}

void revOutput(int counter, string classes[], ofstream& oFile)
{
	for (int i = counter-1; i >= 0; i--)
	{
		cout << "Class Names: " << classes[i] << endl;
		oFile << "Class Names: " << classes[i] << endl;
	}
}

int main()
{
	// Input file creation, opening file, and checking file
	ifstream iFile;

	iFile.open("input.txt");

	checkFile(iFile);

	// Output file creation, and opening file
	ofstream oFile;

	oFile.open("output.txt");

	// Creating the array variable for the classes and counting through it
	string classes[50];

	int counter = getData(iFile, classes);

	// Outputting the original then reversed order of classes and closing the files once done

	output(counter, classes, oFile);
	
	cout << endl << endl;

	revOutput(counter, classes, oFile);

	iFile.close();
	oFile.close();
}